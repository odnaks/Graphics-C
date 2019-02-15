/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 06:39:44 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/20 06:43:18 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

static char	*ft_strtrim_c(char *s, char c)
{
	int len;
	int i;

	len = ft_strlen((char *)s);
	i = 0;
	while ((len > 0) && (s[len - 1] == c))
		len--;
	if (len != 0)
	{
		while (s[i] == c)
			i++;
		len -= i;
	}
	return (ft_strsub(s, i, len));
}

static int	ft_count_words(char *s, char c)
{
	char *next;

	next = ft_strchr(s, c);
	if (next == 0x0)
		return (s[0] != 0);
	else if (next == s)
		return (ft_count_words(next + 1, c));
	else
		return (ft_count_words(next + 1, c) + 1);
}

static char	**ft_clear(char **matrix, int size, char *temp)
{
	int i;

	i = 0;
	if (size > 0)
	{
		while (i < size)
			free(matrix[i++]);
		free(matrix);
		matrix = 0x0;
	}
	free(temp);
	return (matrix);
}

static int	ft_malloc_matrix(char const *s, char **temp, char ***result, char c)
{
	int count;

	if (!s)
		return (-1);
	if (!(*temp = ft_strtrim_c((char *)s, c)))
		return (-1);
	count = ft_count_words(*temp, c);
	if (!(*result = (char **)malloc((count + 1) * sizeof(char *))))
	{
		free(*temp);
		return (-1);
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		count;
	char	**result;
	char	*temp;
	size_t	j;

	if ((count = ft_malloc_matrix(s, &temp, &result, c)) < 0)
		return (0x0);
	i = 0;
	j = 0;
	while (i < count - 1)
	{
		if (ft_strchr(temp + j, c) != temp + j)
			result[i++] = ft_strsub(temp + j, 0,
									ft_strchr(temp + j, c) - (temp + j));
		if (!result[i - 1])
			return (ft_clear(result, i - 1, temp));
		j = (ft_strchr(temp + j, c) - temp) + 1;
	}
	if ((count > 0) && !(result[i++] = ft_strtrim_c(temp + j, c)))
		return (ft_clear(result, i - 1, temp));
	result[i] = 0x0;
	return (ft_clear(result, 0, temp));
}
