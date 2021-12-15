/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:26:43 by adubeau           #+#    #+#             */
/*   Updated: 2021/12/15 15:45:25 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_swap(int *str, int argc)
{
	int	i;
	int	t;

	i = argc;
	i = 0;
	while (!str[i])
		i++;
	if (str[i] && str[i + 1] && str[i] > str[i + 1])
	{
		t = str[i];
		str[i] = str[i + 1];
		str[i + 1] = t;
		write(1, "sa\n", 3);
		return (1);
	}
	return (0);
}

int	ft_push(int *strA, int *strB, int argc, char *c)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	j = argc - 1;
	while (strB[j] != 0)
		j--;
	while (strA[i] == 0)
		i++;
	t = strA[i];
	strA[i] = strB[j];
	strB[j] = t;
	ft_putstr(c);
	return (1);
}

int	ft_rotate(int *str, int argc)
{
	int	i;
	int	t;
	int	j;

	i = 0;
	while (str[i] == 0)
		i++;
	j = str[i];
	while (i < argc)
	{
		t = str[i];
		str[i] = str[i + 1];
		str[i + 1] = t;
		i++;
	}
	str[i] = j;
	write(1, "ra\n", 3);
	return (1);
}

int	ft_rev_rotate(int *str, int argc)
{
	int	i;
	int	j;
	int	t;

	i = argc;
	j = str[argc];
	while (str[i] != 0 && i >= 0)
	{
		t = str[i];
		str[i] = str[i + 1];
		str[i + 1] = t;
		i--;
	}
	i++;
	str[i] = j;
	write(1, "rra\n", 4);
	return (1);
}

void	ft_switch(int *x, int *y)
{
	int	t;

	t = *x;
	*x = *y;
	*y = t;
}
