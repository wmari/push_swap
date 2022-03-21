/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:54:09 by wmari             #+#    #+#             */
/*   Updated: 2022/03/21 17:30:32 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	check_void(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
			{
				j++;
				if (argv[i][j] > '9' || argv[i][j] < '0' || argv[i][j] == '\0')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_valid(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != ' ' && argv[i][j] != '-'
				&& (argv[i][j] < '0' || argv[i][j] > '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_double(t_list *list)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < list->nb_elem)
	{
		j = i + 1;
		while (j < list->nb_elem)
		{
			if (list->tab[i] == list->tab[j])
			{
				free(list->tab);
				free(list);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_long(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		if (temp->value > 2147483647 || temp->value < -2147483648)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	deal_with_arg(int argc, char **argv)
{
	t_list	*list;

	if (argc == 1)
		return (1);
	if (check_valid(argv))
		return (1);
	if (check_void(argv))
		return (1);
	list = parsing(argv);
	if (list == NULL)
		return (1);
	if (check_double(list))
		return (1);
	free(list->tab);
	free(list);
	return (0);
}
