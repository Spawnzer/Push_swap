/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 14:44:07 by adubeau           #+#    #+#             */
/*   Updated: 2021/08/23 15:02:54 by adubeau          ###   ########.fr       */
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

int	ft_swap(int *str, int argc)
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
		return (1);
	}
	return (0);
}

int	ft_push(int *strA, int *strB, int argc)
{
	int i;
	int j;
	int t;


	i = 0;
	j = argc - 1;
	while(strB[j] != 0)
		j--;
	while(strA[i] == 0)
		i++;
	/*ft_putnbr(i);
	write(1," ", 1);
	ft_putnbr(j);
	write(1, "\n", 1);*/
	t = strA[i];
	strA[i] = strB[j];
	strB[j] = t;
	return (1);
}

int	ft_rotate(int *str, int argc)
{
	int i;
	int t;
	int j;

	i = 0;
	while(str[i] == 0)
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

	while(str[i] != 0 && i >= 0)
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
	j = c;
	while (i < argc - 1)
	{
		if (str[i] < str[j])
			j = i;
		i++;
	}
	return (j - c);
}

int ft_biggest(int *str, int argc)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < argc)
	{
		if(str[i] > str[j])
			j = i;
		i++;
	}
	return (str[j]);
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
	//ft_printArrays(strA, strB, (argc - 1));
	//write(1, "\n", 1);
	while(c < argc - 1)
	{	
		j = ft_smallest(strA, c, argc);
	/*	write(1, "j = ", 4);
		ft_putnbr(j);
		write(1, " Value: ", 8);
		ft_putnbr(strA[j + c]);
		write(1, "\n", 1); */
		k = j;	
		if(k < ((argc - c) / 2))
		{		
			while (k > 0)
			{
				h += ft_rotate(strA, argc);
			//	write(1, "ra\n", 3);
			//	ft_printArrays(strA, strB, (argc - 1));
			//	write(1, "\n", 1);
				k--;
			}
		}
		else	
		{
			while (k + c < argc)
			{
				h += ft_revRotate(strA, argc);
			//	write(1, "rra\n", 4);
			//	ft_printArrays(strA, strB, (argc - 1));
			//	write(1, "\n", 1);
				k++;
			}
		}
		h += ft_push(strA, strB, argc);
		c++;
		//write(1, "pa\n", 3);
	//	ft_printArrays(strA, strB, (argc - 1));
	//	write(1, "\n", 1);
			}
	if (ft_swap(strA, argc))
		h++;
		//write(1, "sa\n", 3);
	while (strB[argc - 1] != 0)
	{
		h += ft_push(strB, strA, argc);
	//	write(1, "pb\n", 3);
	//	ft_printArrays(strA, strB, (argc - 1));
	//	write(1, "\n", 1);
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
		ret += ft_swap(strA, ret);
		write(1, "sa\n", 3);
	}
	else if (strA[0] > strA[1] && strA[2] > strA[1] && strA[2] > strA[0])
	{
		ret += ft_swap(strA, ret);
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
		ret += ft_swap(strA, ret);
		write(1, "sa\n", 3);
	}
	else
	{
		ret += ft_rotate(strA, 2);
		write(1, "ra\n", 3);
	}
	return (ret);
}
int ft_is_sorted(int *strA, int argc)
{
	int i;
	int j;

	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (j + i < argc - 1)
		{
			if (strA[i] > strA[i + j])
				return (0);	
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_bogo(int *strA, int *strB, int argc)
{
	int i;
	int (*f[3])(int *, int);
	int h;

	i = 0;
	h = 0;
	f[0] = &ft_swap;
	f[1] = &ft_revRotate;
	f[2] = &ft_rotate;
	while (!ft_is_sorted(strA, argc))
	{
		i = rand() % 3;
		f[i](strA, argc - 2);
		if (i == 0)
			write(1, "sa\n", 3);
		else if (i == 1)
			write(1, "rra\n", 4);
		else
			write(1, "ra\n", 3);
		ft_printArrays(strA, strB, (argc - 1));
		h++;
	}
	return (h);
}

int ft_quick(int *strA, int *strB, int argc)
{
	int med;
	int i;
	int h;
	int p;

	i = 0;
	h = 0;
	p = 0;
	med = 0;
	
	med = (strA[ft_smallest(strA, 0, argc)] + ft_biggest(strA, argc)) / 2;
	write(1, "Med: ", 5);
	ft_putnbr(med);
	write(1, "\n", 1);
	i = 0;
	while (i < (argc))
	{
		if (strA[p] > med)	
		{
			h += ft_push(strA, strB, argc);
			p++;
		}
		else
			h += ft_rotate(strA, argc - 1);
		i++;
		ft_printArrays(strA, strB, (argc));
		write(1, "\n", 1);
	}
	return (h);
}

int	ft_find(int *str1, int nb)
{
	int i;

	i = 0;
	while (str1[i])
	{
		if (str1[i] == nb)
			return (i + 1);
		i++;
	}
	return (i + 1);
}

void	ft_switch(int *x, int *y)
{
	int t;
	t = *x;
	*x = *y;
	*y = t;
}
void ft_quickS(int *strA,  int *strC, int argc)
{
	int i;
	int j;

	i = 0;
	while (strA[i])
	{
		j = 0;
		while (strC[j]) 
		{
			if (strA[i] == strC[j])
			{
				strA[i] = j + 1;
			}
			j++;

		}
		i++;
	}
}

unsigned int ft_binary(unsigned int nb)
{
	int rem;
	int bin;
	int u;

	u = 1;
	rem = 0;
	bin = 0;
	while (nb != 0)
	{
		rem = nb % 2;
		bin += rem * u;
		nb = nb / 2;
		u *= 10;
	}
	return (bin);
}

int	ft_findN(int *str)
{
	int i;
	
	i = 0;
	while (str[i] == 0)
		i++;
	return (i);
}

int ft_radix(int *strA, int *strB, int argc)
{
	int max;
	int max_b;
	int i;
	int j;
	int u;
	int h;

	max = argc - 1;
	max_b = 0;
	i = 1;
	j = 0;
	u = 2;
	h = 0;
	while (max >> max_b != 0)
		++max_b;
	while (i < max_b)
	{
		while (j < argc - 1)
		{
			u = ft_findN(strA);
			if (((strA[u] >> i)&1) != 1)
			{
				write(1, "\npa", 3);
				h += ft_push(strA, strB, argc - 1);
			}
			 j++;	
		}
		j = 0;
		while (strB[argc - 2] != 0)
		{
			write(1, "\npb", 3);
			h += ft_push(strB, strA, argc - 1);
		}
		i++;
	}
	write(1, "\n", 1);
	return (h);
}

int	main(int argc, char **argv)
{
	int i;
	int strA[argc - 1];
	int strB[argc - 1];
	int strC[argc - 1];
	int ret;

	ret = 0;
	i = 0;
	/*strB = (int *)(malloc(sizeof(int) * argc + 1));
	if (!strB)
		return (0);*/
	while (i < argc - 1)
	{
		strA[i] = ft_atoi(argv[i + 1]);
		strC[i] = ft_atoi(argv[i + 1]);
		strB[i] = 0;
		i++;		
	}
	i = 0;
	ft_bubble(strC, strB,  argc - 1); // a regler
	ft_printArrays(strC, strB, argc - 1);
	write(1, "\n", 1);
	ft_quickS(strA, strC, argc);
	/*while (i < argc - 1)
	{
		strA[i] = ft_binary(strA[i]);
		i++;
	}*/
	ft_printArrays(strA, strB, argc - 1);
	ret = ft_radix(strA, strB, argc - 1);
		/*ft_push(strA, strB, argc - 1);
		//ft_swap(strA, argc);
		ft_revRotate(strA, (argc - 2));
		ft_swap(strA, argc);
		ft_rotate(strA, (argc - 2));
		ft_printArrays(strA, strB, (argc - 1));
		//write(1, "\n\n", 3);
		*/
	//	if (argc - 1 == 3)
	//		ret = ft_sort3(strA);
		//else if (argc - 1 == 5)
		//	ret = ft_sort5(strA, strB);
		//else
		//ret = ft_bubble(strA, strB, argc);
	//	ret = ft_bogo(strA, strB, argc);
	//	ret = ft_quick(strA, strB, argc - 1);
		write(1,"Final:\n", 7);
		ft_printArrays(strA, strB, (argc - 1));
		write(1, "Moves : ", 8);
		ft_putnbr(ret);
		write(1, "\n", 1);

		return (0);
}
