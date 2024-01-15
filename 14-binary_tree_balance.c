#include "binary_trees.h"
/**
 * binary_tree_balance-measures the balance factor of a binary tree
 * @tree: A pointer to the root node.
 * Return: balance
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
	{
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	}
	return(0);
}
/**
 * binary_tree_height - function that Measures the height of a binary tree.
 * @tree: A pointer to the root node.
 * Return:height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t right = 0, left = 0;

		if (tree->right)
			right = 1 + binary_tree_height(tree->right);
		else
			right = 1;
		if (tree->left)
			left = 1 + binary_tree_height(tree->left);
		else
			left = 1;

		if (right < left)
			return (left);
		else
			return (right);
	}
	return (0);
}
