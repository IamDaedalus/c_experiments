#ifndef QUEUE_H
#define QUEUE_H

#include <stdarg.h>
#include <stdlib.h>

typedef struct queue {
	int num;
	char* str;
	struct queue* next;
} queue_t;

queue_t* init(int, char*);
queue_t* peek(queue_t**);
queue_t* get_elem_at_index(queue_t**, int);
queue_t* join_queue(queue_t**, queue_t**);
void dequeue(queue_t**);
void enqueue(queue_t**, int num, char*);
void free_elem(queue_t*);
size_t size_of_queue(queue_t**);

/* random things added here */
int gen_sum(queue_t**);

#endif
