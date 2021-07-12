/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clucien <clucien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 09:21:40 by clucien           #+#    #+#             */
/*   Updated: 2019/11/11 09:21:41 by clucien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	nui;
	char			c;

	if (n < 0)
	{
		nui = -n;
		write(1, "-", 1);
	}
	else
		nui = n;
	if (nui > 9)
		ft_putnbr((nui / 10));
	c = (nui % 10) + '0';
	write(1, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nui;
	char			c;

	if (n < 0)
	{
		nui = -n;
		write(fd, "-", 1);
	}
	else
		nui = n;
	if (nui > 9)
		ft_putnbr_fd((nui / 10), fd);
	c = (nui % 10) + '0';
	write(fd, &c, 1);
}
