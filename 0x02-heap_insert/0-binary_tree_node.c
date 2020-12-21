#include "binary_trees.h"

/**
 * binary_tree_node - add ndoe to binary tree
 * @parent: node we attach our tree to.
 * @value: value node holds
 * Return: pointer to new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_n;

	new_n = malloc(sizeof(*new_n));
	if (!new_n)
		return (NULL);
	new_n->left = NULL;
	new_n->right = NULL;
	new_n->n = value;
	new_n->parent = parent;

	return (new_n);
}
