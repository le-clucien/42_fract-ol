/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ret.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clucien <clucien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:01:47 by clucien           #+#    #+#             */
/*   Updated: 2021/06/11 13:00:29 by clucien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit_msg(char *msg, int ret)
{
	write(1, msg, ft_strlen(msg));
	exit(ret);
}

int	ft_ret_msg(char *msg, int ret)
{
	write(1, msg, ft_strlen(msg));
	return (ret);
}
