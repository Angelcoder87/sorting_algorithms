#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using Insertion sort algorithm.
 *
 * @list: Double pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted, *curr, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	return;

	sorted = *list;
	curr = sorted->next;

	while (curr)
	{
	next = curr->next;

	while (curr->prev && curr->n < curr->prev->n)
	{
	if (curr->next)
	curr->next->prev = curr->prev;
	curr->prev->next = curr->next;

	curr->next = curr->prev;
	curr->prev = curr->prev->prev;
	curr->next->prev = curr;

	if (curr->prev == NULL)
	*list = curr;
	else
	curr->prev->next = curr;

	print_list(*list);
	}

	sorted = curr;
	curr = next;
	}
}

