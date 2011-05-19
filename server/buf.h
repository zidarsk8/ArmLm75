/* 
 * File:   buf.h
 * Author: zidar
 *
 * Created on November 14, 2010, 12:22 PM
 */

#ifndef BUFFER_H
#define	BUFFER_H

#define BUFFER_LENGTH 100 // how many elements will the buf store

typedef int element_t; // what kind of elements will the buf store

//predifined needed functions
extern void buf_put(element_t element);
extern int  buf_get(element_t *element);
extern void  buf_print(void);

#endif	/* BUFFER_H */

