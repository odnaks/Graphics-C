/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtadd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:13:17 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/21 22:13:18 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_rotation(t_rbtree *node, int dest)
{
	t_rbtree *son;

	son = (dest == LEFT) ? node->right : node->left;
	if (node->parent)
	{
		((node)->parent->left == node) ?
		((node)->parent->left = son) :
		((node)->parent->right = son);
	}
	son->parent = node->parent;
	node->parent = son;
	if (dest == LEFT)
	{
		node->right = son->left;
		son->left = node;
		node->right->parent = node;
	}
	else
	{
		node->left = son->right;
		son->right = node;
		node->left->parent = node;
	}
}

static void	ft_recolor(t_rbtree *node)
{
	node->parent->color = RB_BLACK;
	(SIBLING(node))->color = RB_RED;
}

static void	ft_rotate(t_rbtree *node)
{
	if ((GRAND(node)->right == node->parent) && (node->parent->right == node))
	{
		ft_rotation(GRAND(node), LEFT);
		ft_recolor(node);
	}
	else if ((GRAND(node)->left == node->parent) &&
		(node->parent->left == node))
	{
		ft_rotation(GRAND(node), RIGHT);
		ft_recolor(node);
	}
	else if ((GRAND(node)->right == node->parent) &&
		(node->parent->left == node))
	{
		ft_rotation(node->parent, RIGHT);
		ft_rotation(node->parent, LEFT);
		ft_recolor(node->right);
	}
	else if ((GRAND(node)->left == node->parent) &&
		(node->parent->right == node))
	{
		ft_rotation(node->parent, LEFT);
		ft_rotation(node->parent, RIGHT);
		ft_recolor(node->left);
	}
}

static void	ft_check_double_red(t_rbtree *new)
{
	if (!(new->parent))
		new->color = RB_BLACK;
	else if (new->parent->color == RB_RED)
	{
		if ((UNCLE(new))->color == RB_RED)
		{
			(UNCLE(new))->color = RB_BLACK;
			new->parent->color = RB_BLACK;
			(GRAND(new))->color = RB_RED;
			ft_check_double_red(GRAND(new));
		}
		else
			ft_rotate(new);
	}
}

void		ft_rbtadd(t_rbtree **root, t_rbtree *new)
{
	t_rbtree *temp;

	if (!*root)
	{
		*root = new;
		(*root)->color = RB_BLACK;
		return ;
	}
	temp = *root;
	while (temp->content)
		temp = ((ft_rbtcmp(temp, new) > 0) ? temp->left : temp->right);
	new->parent = temp->parent;
	(ft_rbtcmp(new->parent, new) > 0) ? (new->parent->left = new) :
										(new->parent->right = new);
	ft_check_double_red(new);
	free(temp);
	*root = ft_rbtroot(*root);
}
