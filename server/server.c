#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <pthread.h>
#include "defs.h"
#include "buf.h"

void *server_listen();
static int cmd_exec(int fd, struct cmd_t cmd);
int s;
int lastTemp;

int get_temp(){
    //lastTemp = syscall(361);
    lastTemp = (int)(random()%120)+160;
    
    //printf("temp: %d \n",lastTemp);
    
    return lastTemp;
}

static int cmd_exec(int fd, struct cmd_t cmd){
    FILE *f;
    int temp;
    int read_status;
    f = fdopen(fd, "w");
    if (f == NULL) return 1;

    if(strcmp( cmd.name , "get_single_temp" ) == 0){
        read_status = buf_get(&temp);
        if (read_status == 1) fprintf(f,"napaka pri branju bufferja\n");
        if (read_status == 2) fprintf(f,"buf je prazen\n");
        if (!read_status) fprintf(f,"%d\n",temp);

    }else if(strcmp( cmd.name , "get_last_temp" ) == 0){
        fprintf(f,"%d\n",lastTemp); // last temp bi mogla biti sinhronizirana

    }else if(strcmp( cmd.name , "get_temp_all" ) == 0){
        read_status = buf_get(&temp);
        if (read_status == 2) fprintf(f,"buf je prazen\n");
        while (!read_status){
            fprintf(f,"%d\n", temp);
            read_status = buf_get(&temp);
        }
        if (read_status == 1) fprintf(f,"napaka pri branju bufferja\n");
    }

    fclose(f);
    return 0;
}

static int setup_listen(short port){
	int s, e, val;
	struct sockaddr_in server_addr;

	s = socket(PF_INET, SOCK_STREAM, 0);
	if (s < 0) return -1;

	val = 1;
	e = setsockopt(s, SOL_SOCKET, SO_REUSEADDR, (void *) &val, sizeof(val));
	if (e) return -1;

	memset((void *) &server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	e = bind(s, (struct sockaddr *) &server_addr, sizeof(server_addr));
	if (e) return -1;

	e = listen(s, 128);
	if (e) return -1;

	return s; 
}

static void serve(int client){
	int n;
	struct cmd_t cmd;

	n = read(client, (void *) &cmd, sizeof(cmd));
	if (n != sizeof(cmd)) return;

	cmd_exec(client, cmd);
}

static void run_server(int server){
	int s, cl_len;
	struct sockaddr_in client_addr;
	cl_len = sizeof(client_addr);
	s = accept(server, (struct sockaddr *) &client_addr, &cl_len);
	if (s < 0) return;
	serve(s);
	close(s);
}


int main(int argc, char **argv)
{
  int pth1;  

  pthread_t thread_serv_listen;
  pthread_attr_t attr; // set of attributes for the thread 
  pthread_attr_init(&attr); // get the default attributes 

  s = setup_listen(SERVER_PORT);
  if (s < 0) {
    printf("error opening server\n");
    exit(1);
  }else{
    printf("server started\n");
  }

  if( (pth1 = pthread_create( &thread_serv_listen, &attr, server_listen, NULL)) ){
    printf("Server listen thread creation failed: %d\n", pth1);
  }else{
    printf("Server thread created\n");
  }


  while(1){
//    printf("while1 read temp\n");
    usleep(1000000); // cakamo eno sekundo
    buf_put((element_t)get_temp());
  }
  close(s);

  return 0;
}

void *server_listen(){
    while(1){
        run_server(s);
    }
}

