#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	queue_t* head = NULL;
	queue_t* new_head = NULL;

	/* HEAD */
	head = init(54, "Isaac");
	enqueue(&head, 25, "James");
	enqueue(&head, 77, "Jonathan");
	enqueue(&head, 384, "Akwasi");
	enqueue(&head, 37, "PK");
	enqueue(&head, 87, "Micaiah");
	enqueue(&head, 75, "Vivian");
	enqueue(&head, 7, "Miriam");

	/* NEW_HEAD */
	new_head = init(28, "Danny");
	enqueue(&new_head, 893, "Levi");
	enqueue(&new_head, 39, "San");

	printf("size of head is %d\n", size_of_queue(&head));

	join_queue(&head, &new_head);

	printf("size of head is %d\n", size_of_queue(&head));
	queue_t* last_elem = get_elem_at_index(&head, (int)size_of_queue(&head) - 1);
	printf("last element is %lu and %s\n", last_elem->num, last_elem->str);

	return (0);
}
