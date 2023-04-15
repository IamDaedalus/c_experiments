#include "queue.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * init - initialises a new queue with values
 * @value: the int value of the queue
 * @str: the string value of the queue
 * Return: returns the new queue
 */
queue_t* init(int value, char* str)
{
	queue_t* result;

	result = malloc(sizeof(struct queue));
	if (!result)
		return (NULL);

	result->num = value;
	result->str = str ? strdup(str) : strdup("");
	if (!result->str) {
		free(result);
		return (NULL);
	}

	result->next = NULL;
	return (result);
}

/**
 * size_of_queue - returns the length of the queue
 * @head: the queue to check
 * Return: returns the lenght of the queue as an int
 */
size_t size_of_queue(queue_t** head)
{
	queue_t* current;
	size_t count = 0;

	if (!*head)
		return (0);
	else
		current = *head;

	while (current) {
		current = current->next;
		count++;
	}

	return (count);
}

/**
 * get_elem_at_index - returns an alement at an index (if it exists)
 * @head: queue to check
 * @index: the index to check
 * Return: returns NULL if index is non existent
 */
queue_t* get_elem_at_index(queue_t** head, int index)
{
	queue_t *elem, *current;
	size_t total = *head ? size_of_queue(head) : 0;
	printf("%lu\n", total);
	int cur_index = 0;

	if (!*head || index > total - 1)
		return (NULL);
	else {
		current = *head;
		while (current) {
			if (cur_index != index) {
				current = current->next;
				cur_index++;
			} else if (cur_index == index) {
				elem = current;
				break;
			}
		}
	}

	return (elem);
}

/**
 * peek - returns the first element of the queue without removing it
 * @head: the queue to peek
 */
queue_t* peek(queue_t** head)
{
	if (*head)
		return (*head);
	else
		return (NULL);
}

/**
 * dequeue - removes the top of the queue aka the first element
 * @head: the queue to operate on
 */
void dequeue(queue_t** head)
{
	queue_t *current, *tmp;

	if (!*head)
		exit(EXIT_FAILURE);
	else {
		current = *head;
		tmp = current->next;

		free_elem(current);

		*head = tmp;
	}
}

/**
 * enqueue - adds the bottom of the queue aka the last element
 * @head: the queue to operate on
 */
void enqueue(queue_t** head, int val, char* str)
{
	queue_t* new;
	queue_t* current;

	new = malloc(sizeof(struct queue));
	if (!new)
		exit(EXIT_FAILURE);

	new->num = val;
	new->str = strdup(str);
	new->next = NULL;

	if (!*head) {
		*head = new;
	} else {
		current = *head;
		while (current->next) {
			current = current->next;
		}
		current->next = new;
	}
}

/**
 * join_queue - joins two queues together
 * @head: the queue that will receive the incoming queue
 * @incoming: the incoming queue
 * Return: returns the head of the queue_t
 */
queue_t* join_queue(queue_t** head, queue_t** incoming)
{
	queue_t* current;

	if (!*head && !*incoming)
		return (NULL);
	else {
		current = *head;

		while (current->next) {
			current = current->next;
		}
		current->next = *incoming;
	}

	/* this is not adviced apparently */
	return (*head);
}

/**
 * free_elem - frees the queue from memory
 * @head: the head of the queue
 */
void free_elem(queue_t* head)
{
	if (head) {
		free(head->str);
		free(head);
	}
}
