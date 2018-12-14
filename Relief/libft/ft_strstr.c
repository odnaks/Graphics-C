/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:00:22 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/19 19:01:04 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *sub)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		if (str[i] == sub[0])
		{
			j = 0;
			while (sub[j] && (str[i + j] == sub[j]))
				j++;
			if (!sub[j])
				return ((char *)(str + i));
		}
		i++;
	}
	if (*sub)
		return (0x0);
	else
		return ((char *)str);
}
