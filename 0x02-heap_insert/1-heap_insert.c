#include "binary_trees.h"

/**
 * swap - swap two nodes in place
 * @n1: 1st node
 * @n2: second node
 */
void swap(heap_t *n1, heap_t *n2)
{
	char left = 0;
	heap_t *tmp;

	n2->parent = n1->parent;
	if (n1->left == n2)
		left = 1;

	if (n1->parent)
	{
		if (n1->parent->right == n1)
			n1->parent->right = n2;
		else
			n1->parent->left = n2;
	}
	n1->parent = n2;
	if (!left)
	{
		n1->right = n2->right;
		if (n1->right)
			n1->right->parent = n1;
		n2->right = n1, tmp = n1->left, n1->left = n2->left;
		if (n1->left)
			n1->left->parent = n1;
		n2->left = tmp;
		if (n2->left)
			n2->left->parent = n2;
	}
	else
	{
		n1->left = n2->left;
		if (n1->left)
			n1->left->parent = n1;
		n2->left = n1, tmp = n1->right, n1->right = n2->right;
		if (n1->right)
			n1->right->parent = n1;
		n2->right = tmp;
		if (n2->right)
			n2->right->parent = n2;
	}
}

/**
 * heap_h - get hight of heap
 * @tree: pointer to tree to use
 * Return: size of tree
 */
size_t heap_h(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);

	left = 1 + heap_h(tree->left);
	right = 1 + heap_h(tree->right);
	return (left > right ? left : right);
}

/**
 * get_parent - get parent node
 * @r: pointer to heap root
 * Return: pointer to node parent
 */
heap_t *get_parent(heap_t *r)
{
	while (r->left && r->right)
		r = heap_h(r->left) == heap_h(r->right) ? r->left : r->right;
	return (r);
}

/**
 * heap_insert - insert new heap node
 * @root: pointer to root of heap structure
 * @val: value to add to heap
 * Return: pointer to new node
 */
heap_t *heap_insert(heap_t **root, int val)
{
	heap_t *new, *curr;

	if (!root)
		return (NULL);
	if (!(*root))
	{
		*root = binary_tree_node(NULL, val);
		return (*root);
	}
	curr = get_parent(*root);
	new = binary_tree_node(curr, val);

	if (!(curr->left))
		curr->left = new;
	else
		curr->right = new;

	while (new->parent && new->parent->n < val)
		swap(new->parent, new);

	while ((*root)->parent)
		*root = (*root)->parent;

	return (new);
}
