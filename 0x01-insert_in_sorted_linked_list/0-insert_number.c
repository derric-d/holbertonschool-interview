#include "lists.h"

/**
 * insert_node - insert node at certain index
 * @head: pointer to begin of list
 * @num: num of index we want as insert
 * Return: pointer to new node
 */
listint_t *insert_node(listint_t **head, int num)
{
	listint_t *node, *new_n;

	node = malloc(sizeof(listint_t));
	if (!node)
		return (NULL);

	node->n = num;

	if (!*head)
	{
		node->next = NULL;
		*head = node;
		return (node);
	}
	if (num < (*head)->n)
	{
		node->next = *head;
		*head = node;
		return (node);
	}

	for (new_n = *head; new_n->next && new_n->next->n <= num; new_n = new_n->next)
		;
	node->next = new_n->next;
	new_n->next = node;

	return (node);
}
