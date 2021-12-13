/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:23:33 by adubeau           #+#    #+#             */
/*   Updated: 2021/12/09 20:45:42 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

void	ft_putstr(char *str)
{
	int	i;

	i = 1;
	while (*str)
	{
		write(1, str++, 1);
	}
}

int	ft_putnbr(int nbr)
{
	int			len;
	int			i;
	char		deci[25];
	long		nb;

	i = 0;
	len = 0;
	nb = nbr;
	if (nb == 0)
		ft_putchar('0');
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	while (nb > 0)
	{
		deci[i] = nb % 10 + 48;
		nb = nb / 10;
		i++;
	}
	i--;
	while (i >= 0)
		ft_putchar(deci[i--]);
	return (len);
}

void	ft_print_arrays(int *str_a, int *str_b, int len)
{
	int	i;
	int	j;
	int	space;

	i = 0;
	j = 0;
	while (i < len)
	{
		ft_putnbr(str_a[i]);
		j = 20 - ft_strlen(str_a[i]);
		while (j)
		{
			write(1, " ", 1);
			j--;
		}
		ft_putnbr(str_b[i]);
		write(1, "\n", 1);
		i++;
	}
}
