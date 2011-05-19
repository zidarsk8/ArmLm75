/**
 * Imlementation of a circular buf with a full indicator.
 * Works the same way as with one empty slot, except it uses 
 * less space with more coplex buf elements than char,
 * the first element will this way be random, but all next e
 * lements should work fine.
 */

#include <stdio.h>
#include "buf.h"

static element_t buf[BUFFER_LENGTH];
static element_t *start = &buf[0]; //points to the unread element
static element_t *end = &buf[0]; //points to the last written element
static char full = 0;

static element_t *increase_pointer(element_t *p){
	p++; //this increases the pointer by the size of the element
	if (p == &buf[BUFFER_LENGTH]) {
		p = &buf[0];
	}
	return p;
}

void buf_put(element_t element){
	if (end == start && full == 1){
            start = increase_pointer(start);
        }
        end = increase_pointer(end);
	*end = element;
    if (end == start){
        full = 1;
    }
}

int buf_get(element_t *element){
	if (element == NULL) return 1; //we have nowhere to store the element value
	if (start == end && full == 0) return 2;//this means that the buf is empty

	start = increase_pointer(start);
    *element = *start;

    if (start == end) full = 0; //if we come around we mark it as empty
	return 0;
}

void buf_print(){
    int i;
    printf("start %d  end %d\n", *start, *end);
    for (i=0; i<BUFFER_LENGTH; i++){
        printf("buf %d = %d\n", i, buf[i]);
    }
}
