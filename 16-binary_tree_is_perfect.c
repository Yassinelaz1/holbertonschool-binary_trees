#include "binary_trees.h"

/**
 * binary_tree_depth - function that Measures the depth
 *  of a node in a binary tree.
 * @tree: A pointer to the node.
 * Return: the depth.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree && tree->parent)
		return (1 + binary_tree_depth(tree->parent));
	else
		return (0);
}
/**
 * binary_tree_is_leaf - Checks if a node is a leaf.
 * @node: A pointer to the node to check.
 * Return: 1 or 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);

	return (1);
}
/**
 * binary_tree_get_leaf - Returns a leaf of a binary tree.
 * @tree: A pointer to the root node of the tree to find a leaf in.
 * Return: A pointer to the first encountered leaf.
 */
const binary_tree_t *binary_tree_get_leaf(const binary_tree_t *tree)
{
	if (binary_tree_is_leaf(tree) == 1)
	{
		return (tree);
	}

	if (tree->left)
	{
		return (binary_tree_get_leaf(tree->left));
	}

	else
	{
		return (binary_tree_get_leaf(tree->right));
	}
}
/**
 * is_perfect - Checks if a binary tree is perfect recursively.
 * @tree: A pointer to the root node of the tree to check.
 * @leaf_depth: The depth of one leaf in the binary tree.
 * @level: Level of current node.
 *
 * Return: If the tree is perfect, 1, otherwise 0.
 */
int is_perfect(const binary_tree_t *tree, size_t leaf_depth, size_t level)
{
	if (binary_tree_is_leaf(tree))
	{
		return (level == leaf_depth ? 1 : 0);
	}

	if (tree->left == NULL || tree->right == NULL)
	{
		return (0);
	}

	return (is_perfect(tree->left, leaf_depth, level + 1) &&
			is_perfect(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node.
 * Return: 1or0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect(tree, binary_tree_depth(binary_tree_get_leaf(tree)), 0));
}
