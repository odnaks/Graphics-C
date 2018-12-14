/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtforeach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:12:54 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/21 22:12:55 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rbtforeach_pre(t_rbtree *root, void (*f)(t_rbtree *elem))
{
	if (root->content)
		f(root);
	if (root->left->content)
		ft_rbtforeach_pre(root->left, f);
	if (root->right->content)
		ft_rbtforeach_pre(root->right, f);
}

static void	ft_rbtforeach_in(t_rbtree *root, void (*f)(t_rbtree *elem))
{
	if (root->left->content)
		ft_rbtforeach_in(root->left, f);
	if (root->content)
		f(root);
	if (root->right->content)
		ft_rbtforeach_in(root->right, f);
}

static void	ft_rbtforeach_post(t_rbtree *root, void (*f)(t_rbtree *elem))
{
	if (root->left->content)
		ft_rbtforeach_post(root->left, f);
	if (root->right->content)
		ft_rbtforeach_post(root->right, f);
	if (root->content)
		f(root);
}

void		ft_rbtforeach(t_rbtree *root, void (*f)(t_rbtree *elem), int order)
{
	if (!root || !f)
		return ;
	if (order == PREFIX)
	{
		ft_rbtforeach_pre(root, f);
	}
	else if (order == INFIX)
	{
		ft_rbtforeach_in(root, f);
	}
	else if (order == POSTFIX)
	{
		ft_rbtforeach_post(root, f);
	}
}
