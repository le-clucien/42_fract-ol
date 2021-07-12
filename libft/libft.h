/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clucien <clucien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:01:47 by clucien           #+#    #+#             */
/*   Updated: 2021/06/11 13:00:46 by clucien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

int					ft_atoi(char *str, int *nb);

int					ft_is_str_alpha(char *str);

int					ft_is_alpha(char c);
int					ft_is_even(int i);
int					ft_is_space(char c);
int					ft_is_digit(char c);
int					ft_is_sign(char c);

int					ft_pow(int nb, int power);

void				*ft_memset(void *b, int c, size_t len);

void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);

void				ft_putstr(char *str);
void				ft_putstr_fd(int fd, char *str);

void				ft_exit_msg(char *msg, int ret);
int					ft_ret_msg(char *msg, int ret);

size_t				ft_strlen(char *str);
size_t				ft_strclen(char *str, char c);

int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

char				*ft_toupper(char *str);
char				*ft_tolower(char *str);

#endif
