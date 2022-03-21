/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:46:34 by wmari             #+#    #+#             */
/*   Updated: 2022/03/21 11:28:05 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

long int	ft_atoi(const char *str)
{
	int					sign;
	long int		ret;

	ret = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\r' ||
		*str == '\v' || *str == '\f' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		ret = (ret * 10) + (*str - 48);
		str++;
	}
	return (ret * sign);
}

void	fill_list(t_list **list, char **argv)
{
	int i;
	int j;
	size_t elem;

	i = 1;
	elem = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] > '0' && argv[i][j] < '9') || argv[i][j] == '-')
			{
				(*list)->tab[elem++] = ft_atoi(&argv[i][j]);
				if (argv[i][j] == '-')
					j++;
				while (argv[i][j] > '0' && argv[i][j] < '9')
					j++;
			}
			if (argv[i][j] == ' ')
				j++;
		}
		i++;
	}
}
int		nb_elem(char *argv)
{
	int count;
	int	i;
	int trig;

	i = 0;
	count = 0;
	trig = 0;
	while (argv[i])
	{
		if (argv[i] > '0' && argv[i] < '9' && trig == 0)
			trig = 1;
		if ((argv[i] < '0' || argv[i] > '9') && trig == 1)
		{
			count++;
			trig = 0;
		}
		i++;
	}
	return (count + trig);
}

t_list *parsing(char **argv)
{
	t_list	*list;
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (argv[i])
	{
		count = count + nb_elem(argv[i]);
		i++;
	}
	list = (t_list*)malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->tab = (long int*)malloc(sizeof(long int) * count);
	if (list->tab == NULL)
	{
		free(list);
		return (NULL);
	}
	list->nb_elem = count;
	fill_list(&list, argv);
	return (list);
}
