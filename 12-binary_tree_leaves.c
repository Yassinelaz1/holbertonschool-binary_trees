#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 * @tree: A pointer to the root node
 * Return: The number of leaves in the tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t numbr_leaves = 0;

	if (tree)
	{
		if (!tree->left && !tree->right)
		{
			numbr_leaves += 1;
		}

		numbr_leaves += binary_tree_leaves(tree->left);
		numbr_leaves += binary_tree_leaves(tree->right);
	}

	return (numbr_leaves);
}
