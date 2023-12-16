#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in 
 * ascending order using the Insertion sort algorithm
 *
 * @list: list of integers in ascending order using Insertion sort algorithm
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *previous, *temp;


   if ((*list) == NULL || (*list)->next == NULL)
   {
		return;
   }
   current = *list;
    while(current && current->next)
    {
        current = current->next;
        previous = current->prev;
        
        while(previous && previous->n > current->n)
        {
            temp = current->next;
            current->next = previous->next;
            previous->next = temp;
            temp = current->prev;
            current->prev = previous->prev;
            previous->prev = temp;
        }
        temp->prev = previous;
        temp->next = previous;
        print_list(*list);
        if (current->next != NULL)
        {
            current->next->prev = previous;
        }
        if (previous->next != NULL)
        {
            previous->next->prev = current;
        }
    }
}
