/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:45:23 by wmari             #+#    #+#             */
/*   Updated: 2022/03/21 14:37:00 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_stack	*create_elem(long int val)
{
	t_stack *elem;

	elem = malloc(sizeof(t_stack));
	elem->value = val;
	elem->harm_value = 0;
	elem->next = NULL;
	return (elem);
}

void	add_back(t_stack *stack, t_stack *elem)
{
	t_stack *copy;

	if (stack == NULL)
	{
		stack = elem;
		stack->next = NULL;
	}
	else
	{
		copy = stack;
		while (copy->next)
			copy = copy->next;
		copy->next = elem;
	}
}
void	free_everything(t_list *list, t_stack *stack)
{
	if (stack)
		free_stack(stack);
	free(list->tab);
	free(list);
}

t_stack *createstack(char **argv)
{
	t_stack *stack;
	size_t	i;
	t_list	*list;
	t_stack	*elem;

	list = parsing(argv);
	if (list == NULL)
		return (NULL);
	i = 1;
	stack = create_elem(list->tab[0]);
	while (i < list->nb_elem)
	{
		elem = create_elem(list->tab[i]);
		if (elem == NULL)
		{
			free_everything(list, stack);
			return (NULL);
		}
		add_back(stack, elem);
		i++;
	}
	free(list->tab);
	free(list);
	return (stack);
}
