//
// Created by Tsun Rhogoro on 24/11/2018.
//

#include "libft.h"
#include "fdf.h"

static t_list	*ft_lstcpy(t_list *elem)
{
	t_list *new;

	new = ft_lstnew(elem->content, elem->content_size);
	return (new);
}


int apply_correction(t_list *matrix, char **image, t_correction correction)
{
	t_list *temp;

	temp = ft_lstmap(matrix, ft_lstcpy);
	ft_apply_move(temp, &correction.mv);
	ft_apply_scale(temp, &correction.sc);
	ft_apply_rotation(temp, &correction.rt);
	ft_apply_type(temp,correction.type);
}