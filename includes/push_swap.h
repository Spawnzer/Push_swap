/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:45:50 by adubeau           #+#    #+#             */
/*   Updated: 2021/12/15 16:04:28 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int					ft_sort3(int *str);
int					ft_bubble(int *str_a, int *str_b, int len);
int					ft_radix(int *str_a, int *str_b, int len);
int					ft_strlen(int str);
int					ft_is_space(char c);
int					ft_is_sign(char c);
int					ft_is_digit(char c);
int					ft_atoi(char *str);
void				ft_sort(int *str_a, int len);
int					ft_smallest(int *str, int c, int len);
void				ft_index(int *str_a, int *str_t, int len);
int					ft_findn(int *str);
int					ft_maxb(int len);
int					ft_swap(int *str, int argc);
int					ft_push(int *strA, int *strB, int argc, char *c);
int					ft_rotate(int *str, int argc);
int					ft_rev_rotate(int *str, int argc);
void				ft_switch(int *x, int *y);
void				ft_putchar(char c);
void				ft_putstr(char *str);
int					ft_putnbr(int nbr);
void				ft_print_arrays(int *str_a, int *str_b, int len);
size_t				ft_strlcpy(char *dest, const char *src, size_t n);
char				**ft_malloc_error(char **tab);
unsigned int		ft_get_nb_strs(char const *s, char c);
void				ft_get_next_str(char **next_str,
						unsigned int *next_str_len, char c);
char				**ft_split(char const *s, char c);
int					ft_is_sorted(int *str, int argc);
int					ft_double(int *str, int len);
void				ft_check_argc(int argc);
void				ft_freetmp(char **str);
int					main(int argc, char **argv);

#endif
