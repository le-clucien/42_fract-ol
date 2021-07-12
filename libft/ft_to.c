/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clucien <clucien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:45:01 by clucien           #+#    #+#             */
/*   Updated: 2019/11/07 13:48:57 by clucien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ctoup(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

char	*ft_toupper(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		str[i] = ft_ctoup(str[i]);
	return (str);
}

static int	ft_ctolow(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

char	*ft_tolower(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		str[i] = ft_ctolow(str[i]);
	return (str);
}
