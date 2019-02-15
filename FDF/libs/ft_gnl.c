/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:16:31 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/27 15:28:52 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static void			lstdelone(void *content, size_t size)
{
	if (size > 0)
	{
		free(((t_bufs *)content)->buf);
		free(content);
	}
}

static int			safe_cat(char **str1, char **buf, size_t n)
{
	size_t	len;
	char	*result;

	len = (*str1 ? ft_strlen(*str1) : 0);
	len += ((ft_strlen(*buf) < n) ? (n = ft_strlen(*buf)) : n);
	if ((result = (char *)malloc(len + 1)))
	{
		ft_memset(result, 0, len + 1);
		if (*str1)
		{
			ft_strcpy(result, *str1);
			free(*str1);
		}
		ft_strncat(result, *buf, n);
		*str1 = result;
		ft_memmove(*buf, *buf + n + 1, BUFF_SIZE - n);
		ft_memset(*buf + BUFF_SIZE - n, 0, n + 1);
		return (0);
	}
	return (1);
}

static void			clean_list(t_list **bufs)
{
	t_list *temp;
	t_list *temp2;

	temp = *bufs;
	while ((*bufs) && ((t_bufs *)((*bufs)->content))->buf[0] == 0)
	{
		temp = (*bufs)->next;
		ft_lstdelone(bufs, lstdelone);
		*bufs = temp;
	}
	if (temp)
		while (temp->next)
		{
			if (((t_bufs *)((temp->next)->content))->buf[0] == 0)
			{
				temp2 = temp->next->next;
				ft_lstdelone(&(temp->next), lstdelone);
				temp->next = temp2;
			}
			else
				temp = temp->next;
		}
}

static int			get_next_line_mult(t_bufs *bufs, char **line)
{
	int		s;
	size_t	n;

	if (!(bufs->buf))
		ft_memset((void *)((bufs->buf) = (char *)malloc(BUFF_SIZE + 1)), 0,
				BUFF_SIZE + 1);
	*line = 0x0;
	if (ft_strchr((bufs->buf), '\n'))
		return ((-2 * (safe_cat(line, &(bufs->buf),
				ft_strchr((bufs->buf), '\n') - (bufs->buf)))) + 1);
		safe_cat(line, &(bufs->buf), BUFF_SIZE + 1);
	while ((s = (int)read(bufs->fd, (bufs->buf), BUFF_SIZE)) > 0)
	{
		n = (ft_strchr((bufs->buf), '\n') ? (ft_strchr((bufs->buf), '\n') -
				(bufs->buf)) : 0);
		if ((bufs->buf)[0] == '\n')
			return ((-2 * safe_cat(line, &(bufs->buf), 0)) + 1);
		if (n)
			return ((-2 * (safe_cat(line, &(bufs->buf),
					ft_strchr((bufs->buf), '\n') - (bufs->buf)))) + 1);
		else
			safe_cat(line, &(bufs->buf), (size_t)s);
	}
	return (s);
}

int					ft_gnl(const int fd, char **line)
{
	static t_list	*bufs;
	t_list			*temp;
	t_bufs			*buf;
	int				result;

	if ((fd < 0) || (!line))
		return (-1);
	buf = (t_bufs *)malloc(sizeof(t_bufs));
	buf->fd = fd;
	buf->buf = 0x0;
	if (!bufs)
		bufs = ft_lstnew((void *)buf, sizeof(t_bufs));
	temp = bufs;
	while ((temp) && (((t_bufs *)(temp->content))->fd != fd))
		temp = temp->next;
	if (!temp)
	{
		ft_lstadd(&bufs, ft_lstnew((void *)buf, sizeof(t_bufs)));
		temp = bufs;
	}
	free(buf);
	result = get_next_line_mult((t_bufs *)temp->content, line);
	clean_list(&bufs);
	return (((*line)[0] && (!result)) ? 1 : result);
}
