/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 14:44:07 by adubeau           #+#    #+#             */
/*   Updated: 2021/08/24 19:18:34 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(int str)
{
	int	i;

	i = 0;
	if (str == 0)
		i++;
	while (str != 0)
	{
		str = str / 10;
		i++;
	}
	return (i);
}

int	ft_is_space(char c)
{
	if (c == '\f' || c == ' ' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
		return (1);
	return (0);
}

int	ft_is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	res = 0;
	neg = 1;
	while (ft_is_space(str[i]))
		i++;
	if (ft_is_sign(str[i]))
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (ft_is_digit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * neg);
}

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

void	ft_printArrays(int *strA, int *strB, int len)
{
	int	i;
	int	j;
	int	space;

	i = 0;
	j = 0;
	while (i < len)
	{
		ft_putnbr(strA[i]);
		j = 20 - ft_strlen(strA[i]);
		while (j)
		{
			write(1, " ", 1);
			j--;
		}
		ft_putnbr(strB[i]);
		write(1, "\n", 1);
		i++;
	}
}

int	ft_swap(int *str, int argc)
{
	int	i;
	int	t;

	i = 0;
	while (!str[i])
		i++;
	if (str[i] && str[i + 1] && str[i] > str[i + 1])
	{
		t = str[i];
		str[i] = str[i + 1];
		str[i + 1] = t;
		return (1);
	}
	return (0);
}

int	ft_push(int *strA, int *strB, int argc, char c)
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
	write(1, "\np", 2);
	ft_putchar(c);
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
	write(1, "\nra", 3);
	return (1);
}

int	ft_revRotate(int *str, int argc)
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
	write(1, "\nrra", 4);
	return (1);
}

void	ft_switch(int *x, int *y)
{
	int	t;

	t = *x;
	*x = *y;
	*y = t;
}

void	ft_sort(int *strA, int len)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (strA[j] > strA[j + 1])
				ft_switch(&strA[j], &strA[j + 1]);
			j++;
		}
		i++;
	}
}

int	ft_smallest(int *str, int c, int len)
{
	int	i;
	int	j;
	int	k;

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

void	ft_index(int *strA, int *strT, int len)
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
			if (strA[i] > strA[j])
				index++;
			j++;
		}
		strT[i] = index;
		index = 1;
		i++;
	}
	i = 0;
	while (i < len)
	{
		strA[i] = strT[i];
		i++;
	}
}

int	ft_findN(int *str)
{
	int	i;

	i = 0;
	while (str[i] == 0)
		i++;
	return (str[i]);
}

int	ft_maxB(int len)
{
	int	maxB;
	int	max;

	max = len;
	maxB = 0;
	while (max >> maxB != 0)
		++maxB;
	return (maxB);
}

int	ft_sort3(int *strA)
{
	int	ret;

	ret = 0;
	if (ft_swap(strA, ret))
	{
		write(1, "sa\n", 3);
		ret++;
	}
	if (strA[0] > strA[2])
	{
		ret += ft_revRotate(strA, 2);
		write(1, "rra\n", 4);
	}
	else if (strA[0] < strA[1] && strA[1] > strA[2])
	{
		ret += ft_revRotate(strA, 2);
		write(1, "rra\n", 4);
	}
	if (ft_swap(strA, ret))
	{
		write(1, "sa\n", 3);
		ret++;
	}
	return (ret);
}

int	ft_bubble(int *strA, int *strB, int len)
{
	int	j;
	int	c;
	int	h;

	c = 0;
	h = 0;
	while (c < len - 2)
	{
		j = ft_smallest(strA, c, len);
		if (j < ((len - c) / 2))
			while (j-- > 0)
				h += ft_rotate(strA, len - 1);
		else
			while (j++ + c < len)
				h += ft_revRotate(strA, len - 1);
		h += ft_push(strA, strB, len, 'a');
		c++;
	}
	if (ft_swap(strA, len))
		h++;
	while (strB[len - 1] != 0)
		h += ft_push(strB, strA, len, 'b');
	return (h);
}

int	ft_radix(int *strA, int *strB, int len)
{
	int	i;
	int	j;
	int	k;
	int	max;
	int	u;

	i = -1;
	j = 0;
	u = 0;
	max = ft_maxB(len);
	while (++i < max)
	{
		while (j++ < len)
		{
			k = ft_findN(strA);
			if (((k >> i) & 1) == 1)
				 u += ft_rotate(strA, len - 1);
			else
				u += ft_push(strA, strB, len, 'a');
		}
		j = 0;
		while (strB[len - 1] != 0)
			u += ft_push(strB, strA, len, 'b');
	}
	return (u);
}

int	main(int argc, char **argv)
{
	int	i;
	int	len;
	int	strA[argc - 1];
	int	strB[argc - 1];
	int	strT[argc - 1];

	i = -1;
	len = argc - 1;
	while (++i < len)
	{
		strA[i] = ft_atoi(argv[i + 1]);
		strB[i] = 0;
		strT[i] = strA[i];
	}
	ft_index(strA, strT, len);
	i = 0;
	if (len == 3)
		i += ft_sort3(strA);
	else if (len == 5)
		i += ft_bubble(strA, strB, len);
	else
		i = ft_radix(strA, strB, len);
	ft_printArrays(strA, strB, len);
	write(1, "\nFinal: ", 7);
	ft_putnbr(i);
}
