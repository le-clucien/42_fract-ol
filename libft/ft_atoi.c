/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clucien <clucien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:01:47 by clucien           #+#    #+#             */
/*   Updated: 2021/06/11 12:53:53 by clucien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	atoi_size(char *str)
{
	int	i;
	int	out;

	i = 0;
	while (str[i] && ft_is_space(str[i]))
		i++;
	if (!str[i])
		return (-1);
	if (ft_is_sign(str[i]))
		i++;
	if (!str[i] || !ft_is_digit(str[i]))
		return (-1);
	out = 0;
	while (str[i] && ft_is_digit(str[i]))
	{
		i++;
		out++;
	}
	return (out);
}

int	ft_atoi(char *str, int *nb)
{
	unsigned long long	out;
	int					i;
	int					scale;

	scale = atoi_size(str);
	if (scale < 0)
		return (0);
	i = 0;
	while (str[i] && !ft_is_sign(str[i]) && !ft_is_digit(str[i]))
		i++;
	if (str[i] && str[i] == '-')
		*nb = -1;
	if (str[i] && ft_is_sign(str[i]))
		i++;
	out = 0;
	while (str[i] && ft_is_digit(str[i]) && scale--)
		out += (str[i++] - '0') * ft_pow(10, scale);
	if (out > INT_MAX || (*nb == -1 && out > -INT_MIN))
		return (0);
	if (*nb < 0)
		*nb = (int)out * -1;
	else
		*nb = (int)out;
	return (1);
}
