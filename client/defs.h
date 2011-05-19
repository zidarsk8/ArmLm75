#ifndef _DEFS_H
#define _DEFS_H

#define SERVER_PORT 20000

struct cmd_t {
    char path[256];
    char name[64];
    char arg[64];
};

#endif /* _DEFS_H */
