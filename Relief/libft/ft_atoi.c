/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 20:06:46 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/04 20:14:15 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char		*ft_remove_spaces(char *str)
{
	while (*str)
	{
		if ((*str == '\n') || (*str == '\t') || (*str == '\v')
			|| (*str == ' ') || (*str == '\r') || (*str == '\f'))
			str++;
		else
			return (str);
	}
	return (str);
}

int				ft_atoi(const char *str)
{
	char	*temp;
	long	result;

	result = 1;
	if (!*str)
		return (0);
	temp = ft_remove_spaces((char *)str);
	if ((*temp == '-') || (*temp == '+'))
		result = ((*temp++ == '-') ? -1 : 1);
	while (*temp == '0')
		temp++;
	if ((*temp < '0') || (*temp > '9'))
		return (0);
	result *= (*temp++ - '0');
	while ((*temp >= '0') && (*temp <= '9'))
	{
		if (((result * 10 + ((result < 0) ? ('0' - *temp) : (*temp - '0'))) +
			((result < 0) ? (*temp - '0') : ('0' - *temp))) / 10 != result)
			return (-1 * (result > 0));
		if (result < 0)
			result = result * 10 - (*temp++ - '0');
		else
			result = result * 10 + (*temp++ - '0');
	}
	return ((int)result);
}
