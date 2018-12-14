/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtrmv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:12:10 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/22 17:20:09 by trhogoro         ###   ########.fr       */
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

static void	ft_rbtdel(t_rbtree *elem)
{
	if (elem->content_size)
	{
		elem->content_size = 0;
		free(elem->content);
	}
	free(elem);
}

static int	ft_first_check_dbl_black(t_rbtree **bb)
{
	if (!(*bb)->parent)
		return (0);
	if ((SIBLING((*bb)))->color == RB_RED)
	{
		(*bb)->parent->color = RB_RED;
		(SIBLING((*bb)))->color = RB_BLACK;
		(*bb)->parent->left == (*bb) ? ft_rotation((*bb)->parent, LEFT) :
		ft_rotation((*bb)->parent, RIGHT);
		return (0);
	}
	return (1);
}

static void	dbl_black(t_rbtree **bb)
{
	if (!ft_first_check_dbl_black(bb))
		return ;
	if ((SL(bb)->color == RB_BLACK) && (SR(bb)->color == RB_BLACK))
	{
		((SIBLING((*bb)))->color = RB_RED);
		return (((*bb)->parent->color == RB_BLACK) ?
		(dbl_black(&((*bb)->parent))) : ((*bb)->parent->color = RB_BLACK));
	}
	if (((*bb)->parent->left == *bb) && ((SIBLING((*bb)))->right == RB_BLACK))
	{
		(SIBLING((*bb)))->color = RB_RED;
		(SIBLING((*bb)))->left->color = RB_BLACK;
		ft_rotation(SIBLING((*bb)), RIGHT);
		return (dbl_black(bb));
	}
	if (((*bb)->parent->right == *bb) && ((SIBLING((*bb)))->left == RB_BLACK))
	{
		(SIBLING((*bb)))->color = RB_RED;
		(SIBLING((*bb)))->right->color = RB_BLACK;
		ft_rotation(SIBLING((*bb)), LEFT);
		return (dbl_black(bb));
	}
	(SIBLING((*bb)))->color = (*bb)->parent->color;
	(*bb)->parent->color = RB_BLACK;
	((*bb)->parent->left == *bb ? SR(bb) : SL(bb))->color = RB_BLACK;
}

void		ft_rbtrmv(t_rbtree **elem)
{
	t_rbtree *temp;

	if (((*elem)->left->content) && ((*elem)->right->content))
		temp = (((*elem)->right->left->content) ? (*elem)->right->left
												: (*elem)->right);
	else
		temp = ((*elem)->left->content ? (*elem)->left : (*elem)->right);
	if (temp->content)
	{
		ft_memswap(&(*elem)->content_size, &temp->content_size, sizeof(size_t));
		ft_memswap(&(*elem)->content, &temp->content, sizeof(void *));
		return (ft_rbtrmv(&temp));
	}
	temp->parent = (*elem)->parent;
	(temp->parent->left == (*elem)) ? (temp->parent->left = temp) :
	(temp->parent->right = temp);
	ft_rbtdel((*elem)->left);
	if ((*elem)->color == RB_RED)
		return (ft_rbtdel(*elem));
	if (((*elem)->parent->color == RB_RED) && !(SIBLING((*elem))->content))
		(*elem)->parent->color = RB_BLACK;
	else if (temp->parent)
		dbl_black(&temp);
	ft_rbtdel(*elem);
}
