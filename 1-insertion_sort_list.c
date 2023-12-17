#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: list of integers in ascending order using Insertion sort algorithm
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *previous, *temp;

	if (*list == NULL && (*list)->next == NULL)
	{
		return;
	}
	else
	{
		current = (*list)->next;
		while (current)
		{
			temp = current->next;
			previous = current->prev;
			while (previous && previous->n > current->n)
			{
				current->next = previous;
				current->prev = previous->prev;

				previous->prev = current;
				previous->next = temp;

				if (current->prev != NULL)
				{
					current->prev->next = current;
				}
				if (temp != NULL)
				{
					temp->prev = previous;
				}
				if (current->prev == NULL)
				{
					(*list) = current;
				}
				print_list(*list);
				previous = current->prev;
				temp = current->next;
			}
			current = temp;
		}
	}
}
