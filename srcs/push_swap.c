/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:35:19 by adubeau           #+#    #+#             */
/*   Updated: 2021/12/09 21:20:18 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_sorted(int *str, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (j + i < argc - 1)
		{
			if (str[i] > str[i + j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_double(int *str, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (i == j)
				j++;
			if (str[j] == str[i])
			{
				ft_putstr("Erreur, présence de doublons\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_check_argc(int argc)
{
	if (argc != 2)
	{
		ft_putstr("Erreur, mauvais nombre d'argument\n");
		exit(0);
	}
}

void	ft_freetmp(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	main(int argc, char **argv)
{
	int		i;
	int		str_a[1000];
	int		str_b[1000];
	int		str_t[1000];
	char	**temp;

	i = -1;
	ft_check_argc(argc);
	temp = ft_split(argv[1], ' ');
	while (temp[++i])
	{
		str_a[i] = ft_atoi(temp[i]);
		str_b[i] = 0;
		str_t[i] = str_a[i];
	}
	ft_freetmp(temp);
	ft_double(str_a, i);
	ft_index(str_a, str_t, i);
	if (i == 3)
		ft_sort3(str_a);
	else if (i == 5)
		ft_bubble(str_a, str_b, i);
	else
		ft_radix(str_a, str_b, i);
	return (1);
}
