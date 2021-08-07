/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 14:44:07 by adubeau           #+#    #+#             */
/*   Updated: 2021/08/06 14:11:04 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int	ft_strlen(int str)
{
	int i;

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

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

void	ft_putstr(char *str)
{
	int i;

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

int	ft_atoi(const char *str)
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

void	ft_printArrays(int *strA, int *strB, int argc)
{
	int i;
	int j;
	int space;

	i = 0;
	j = 0;

	while (i < argc)
	{
		//if (strA[i])
			ft_putnbr(strA[i]);
		j = 20 - ft_strlen(strA[i]);
		while (j)
		{
			write(1, " ", 1);
			j--;
		}
		//if (strB[i])
			ft_putnbr(strB[i]);
		ft_putstr("\n");
		i++;
	}
}

int	ft_swap(int *str)
{
	int i;
	int t;

	i = 0;
	while (!str[i])
		i++;
	if (str[i] && str[i + 1] && str[i] > str[i + 1])
	{
		t = str[i];
		str[i] = str[i + 1];
		str[i + 1] = t;
	}
	return (1);
}

int	ft_push(int *strA, int *strB, int argc)
{
	int i;
	int j;
	int t;


	i = 0;
	j = 0;
	while(strB[j] == NULL)
		j++;
	while(strA[i] == NULL)
		i++;
	/*ft_putnbr(i);
	write(1," ", 1);
	ft_putnbr(j);
	write(1, "\n", 1);*/
	t = strA[i];
	strA[i] = strB[j - 1];
	strB[j - 1] = t;
	return (1);
}

int	ft_rotate(int *str, int argc)
{
	int i;
	int t;
	int j;

	i = 0;
	while(str[i] == (int)NULL)
		i++;
	j = str[i];
	while(i < argc)
	{
		t = str[i];
		str[i] = str[i + 1];
		str[i + 1] = t;
		i++;
	}
	str[i]  = j;
	return (1);
}

int	ft_revRotate(int *str, int argc)
{
	int i;
	int t;
	int j;

	i = argc;
	j = str[argc];
	while(i >= 0)
	{
		t = str[i];
		str[i] = str[i + 1];
		str[i + 1] = t;
		i--;
	}
	i++;
	str[i]  = j;
	return (1);
}

int ft_smallest(int *str, int c, int argc)
{
	int i;
	int j;
	int k;

	i = c;
	j = i;
	while (i < argc - 1)
	{
		if (str[i] < str[j])
			j = i;
		i++;
	}
	return (j - c);
}

int	ft_bubble(int *strA, int *strB, int argc)
{
	int i;
	int j;
	int k;
	int c;
	int h;

	i = 0;
	c = 0;
	h = 0;
	ft_printArrays(strA, strB, (argc - 1));
	while(c < argc - 2)
	{	
		j = ft_smallest(strA, c, argc);
		write(1, "j = ", 4);
		ft_putnbr(j);
		write(1, "\n", 1);
		k = j;	
		if(k < ((argc - c) / 2))
		{		
			while (k > 0)
			{
				h += ft_rotate(strA, argc - 2);
				write(1, "ra\n", 3);
				ft_printArrays(strA, strB, (argc - 1));
				k--;
			}
		}
		else	
		{
			while (k + c < argc - 1)
			{
				h += ft_revRotate(strA, argc - 2);
				write(1, "rra\n", 4);
				ft_printArrays(strA, strB, (argc - 1));
				k++;
			}
		}
		h += ft_push(strA, strB, argc - 1);
		c++;
		write(1, "pa\n", 3);
		ft_printArrays(strA, strB, (argc - 1));
	}
	while (strB[argc - 2] != (int)NULL)
	{
		h += ft_push(strB, strA, argc - 1);
		write(1, "pb\n", 3);
		ft_printArrays(strA, strB, (argc - 1));
	}
	return (h);
}

int	ft_sort3(int *strA)
{
	int ret;

	ret = 0;
	if(strA[0] < strA[1] && strA[1] < strA[2])
		return (ret);
	else if (strA[0] < strA[1] && strA[1] > strA[2] && strA[0] < strA[2])
	{
		ret += ft_revRotate(strA, 2);
		write(1, "rra\n", 4);
		ret += ft_swap(strA);
		write(1, "sa\n", 3);
	}
	else if (strA[0] > strA[1] && strA[2] > strA[1] && strA[2] > strA[0])
	{
		ret += ft_swap(strA);
		write(1, "sa\n", 3);
	}
	else if (strA[0] < strA[1] && strA[1] > strA[2])
	{
		ret += ft_revRotate(strA, 2);
		write(1, "rra\n", 4);
	}
	else if (strA[0] > strA[1] && strA[1] > strA[2])
	{
		ret += ft_rotate(strA, 2);
		write(1, "ra\n", 4);
		ret += ft_swap(strA);
		write(1, "sa\n", 3);
	}
	else
	{
		ret += ft_rotate(strA, 2);
		write(1, "ra\n", 3);
	}
	return (ret);
}

int	main(int argc, char **argv)
{
	int i;
	int strA[argc-1];
	int strB[argc - 1];
	int ret;

	ret = 0;
	i = 0;
	/*strB = (int *)(malloc(sizeof(int) * argc + 1));
	if (!strB)
		return (0);*/
	while (i < argc - 1)
	{
		strA[i] = ft_atoi(argv[i + 1]);
		strB[i] = 0;
		i++;		
	}
		/*ft_push(strA, strB, argc - 1);
		//ft_swap(strA);
		ft_revRotate(strA, (argc - 2));
		ft_swap(strA);
		ft_rotate(strA, (argc - 2));
		ft_printArrays(strA, strB, (argc - 1));
		//write(1, "\n\n", 3);
		*/
		if (argc - 1 == 3)
			ret = ft_sort3(strA);
		//else if (argc - 1 == 5)
		//	ret = ft_sort5(strA, strB);
		else
			ret = ft_bubble(strA, strB, argc);
		write(1,"Final:\n", 7);
		ft_printArrays(strA, strB, (argc - 1));
		write(1, "Moves : ", 8);
		ft_putnbr(ret);
		write(1, "\n", 1);

		return (0);
}
