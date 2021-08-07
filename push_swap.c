/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 14:44:07 by adubeau           #+#    #+#             */
/*   Updated: 2021/08/06 20:13:38 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;


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

int	ft_strcmp(char *str1, char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] == str2[i] && str1[i] && str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

t_list	*ft_addLink(t_list *list, char *str)
{
	t_list *tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->content = str;
		tmp->next = list;
	}
	return (tmp);
}
int	ft_lstsize(t_list *lst)
{
	unsigned int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}



void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (alst)
	{
		if (*alst)
		{
			last = ft_lstlast(*alst);
			last->next = new;
		}
		else
			*alst = new;
	}
}

int ft_rotate(t_list *a)
{
	char *str;

	while (a->next->content)
	{
		a->content = a->next->content;
		ft_putstr(a->content);
		ft_putchar('\n');

	}	
}

int	main(int argc,char **argv)
{
	t_list *a;
	t_list *b;
	int i;
	
	i = argc;
	a = NULL;
	b = NULL;

	while (i)
	{
		a = ft_addLink(a, argv[i]);
		//a = a->next;
		i--;
	}
	while (i++ < argc - 1)
	{
		ft_putstr(a->content);
		ft_putchar('\n');
		a = a->next;
	}
	ft_rotate(a);
/*	while (i)
	{
		ft_putstr(a->content);
		ft_putchar('\n');
		a = a->next;
		i--;
	}*/
	return (0);
	
}
