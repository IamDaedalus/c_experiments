#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	queue_t* head = NULL;
	head = init(54, "Isaac");
	enqueue(&head, 25, "James");
	enqueue(&head, 77, "Jonathan");
	enqueue(&head, 384, "Akwasi");
	enqueue(&head, 37, "PK");
	enqueue(&head, 87, "Micaiah");
	enqueue(&head, 93287, "Vivian");
	enqueue(&head, 7, "Miriam");

	printf("peeking value yields %s\n", (peek(&head))->str);
	printf("size of head is %lu\n", size_of_queue(&head));
	dequeue(&head);
	printf("peeking value yields %s\n", (peek(&head))->str);
	printf("size of head is %lu\n", size_of_queue(&head));

	return (0);
}