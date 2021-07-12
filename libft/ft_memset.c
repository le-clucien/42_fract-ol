/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clucien <clucien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:14:35 by clucien           #+#    #+#             */
/*   Updated: 2019/11/04 11:14:59 by clucien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptuc;
	unsigned char	cuc;
	size_t			i;

	ptuc = (unsigned char *)b;
	cuc = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		ptuc[i] = cuc;
		i++;
	}
	return (b);
}
