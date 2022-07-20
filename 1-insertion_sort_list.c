#include "sort.h"

/**
* swap - Swaps tha nodes
* @node1: node1 or lower node
* @node2: node2 or later node
* @h: Head of the list
*/

void swap(listint_t *node1, listint_t *node2, listint_t **h)
{
	listint_t *temp;

	temp = node1->prev;
	if (temp)
		temp->next = node2;
	node2->prev = temp;
	node1->prev = node2;
	node1->next = node2->next;
	node2->next = node1;
	if (node1->next != NULL)
		node1->next->prev = node1;
	if (node2->prev == NULL)
		*h = node2;
	print_list(*h);
}

/**
* insertion_sort_list - sorts a doubly linked list of integers
*	in ascending order
* @list: Head of the list
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *save_current, *prev, *save_prev;

	if (list == NULL)
		return;

	current = save_current = *list;
	while (current)
	{
		while (current->prev)
		{
			prev = current->prev;
			save_prev = prev;
			if (prev->n > current->n)
				swap(prev, current, list);
			current = save_prev;
		}
		current = save_current->next;
		save_current = current;
	}

}
