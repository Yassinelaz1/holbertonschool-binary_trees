#include "binary_trees.h"

/**
 * FULL - Checks if a binary tree is full.
 * @tree: A pointer to the root node.
 * Return:0 or 1
 */
int FULL(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left == NULL && tree->right != NULL) ||
			(tree->left != NULL && tree->right == NULL) ||
			FULL(tree->left) == 0 ||
			FULL(tree->right) == 0)
			return (0);
	}
	return (1);
}
/**
 * binary_tree_is_full-function that checks if a binary tree is full
 * @tree: A pointer to the root node.
 * Return:0 or 1
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	else
		return (FULL(tree));
}