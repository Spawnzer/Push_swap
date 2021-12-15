/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:29:15 by adubeau           #+#    #+#             */
/*   Updated: 2021/12/15 15:45:51 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort(int *str_a, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (str_a[j] > str_a[j + 1])
				ft_switch(&str_a[j], &str_a[j + 1]);
			j++;
		}
		i++;
	}
}

int	ft_smallest(int *str, int c, int len)
{
	int	i;
	int	j;

	i = c;
	j = c;
	while (i < len)
	{
		if (str[i] < str[j])
			j = i;
		i++;
	}
	return (j - c);
}

void	ft_index(int *str_a, int *str_t, int len)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 1;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (str_a[i] > str_a[j])
				index++;
			j++;
		}
		str_t[i] = index;
		index = 1;
		i++;
	}
	i = 0;
	while (i < len)
	{
		str_a[i] = str_t[i];
		i++;
	}
}

int	ft_findn(int *str)
{
	int	i;

	i = 0;
	while (str[i] == 0)
		i++;
	return (str[i]);
}

int	ft_maxb(int len)
{
	int	maxb;
	int	max;

	max = len;
	maxb = 0;
	while (max >> maxb != 0)
		++maxb;
	return (maxb);
}
