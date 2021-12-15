/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:30:32 by adubeau           #+#    #+#             */
/*   Updated: 2021/12/15 15:43:26 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_sort3(int *str)
{
	int	ret;

	ret = 0;
	if (str[0] > str[1] && str[0] > str[2])
		ret += ft_rotate(str, 3);
	else if (str[1] > str[0] && str[1] > str[2])
		ret += ft_rev_rotate(str, 3);
	ret += ft_swap(str, 2);
	return (ret);
}

int	ft_bubble(int *str_a, int *str_b, int len)
{
	int	j;
	int	c;
	int	h;

	c = 0;
	h = 0;
	while (c < len - 2)
	{
		j = ft_smallest(str_a, c, len);
		if (j < ((len - c) / 2))
			while (j-- > 0)
				h += ft_rotate(str_a, len - 1);
		else
			while (j++ + c < len)
				h += ft_rev_rotate(str_a, len - 1);
		h += ft_push(str_a, str_b, len, "pb\n");
		c++;
	}
	if (str_a[3] > str_a[4])
		h += ft_swap(str_a, len);
	while (str_b[len - 1] != 0)
		h += ft_push(str_b, str_a, len, "pa\n");
	return (h);
}

int	ft_radix(int *str_a, int *str_b, int len)
{
	int	i;
	int	j;
	int	k;
	int	max;
	int	u;

	i = -1;
	j = 0;
	u = 0;
	max = ft_maxb(len);
	while (++i < max)
	{
		while (j++ < len)
		{
			k = ft_findn(str_a);
			if (((k >> i) & 1) == 0)
				u += ft_push(str_a, str_b, len, "pb\n");
			else
				u += ft_rotate(str_a, len - 1);
		}
		j = 0;
		while (str_b[len - 1] != 0)
			u += ft_push(str_b, str_a, len, "pa\n");
	}
	return (u);
}
