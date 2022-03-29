/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:42:56 by wmari             #+#    #+#             */
/*   Updated: 2022/03/29 18:36:44 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	id_sa(t_stack **stack)
{
	t_stack	*temp;
	int		order;

	if ((*stack)->harm_value == (*stack)->next->harm_value + 1)
	{
		temp = (*stack)->next->next;
		order = 1;
		while (temp && temp->next && order == 1)
		{
			if (temp->harm_value != temp->next->harm_value - 1)
				order = 0;
			temp = temp->next;
		}
		if (order == 1)
			swapa(stack);
	}
}

void	id_ra(t_stack **stack)
{
	t_stack	*last;
	t_stack	*temp;
	int		order;

	last = *stack;
	while (last->next)
		last = last->next;
	if (last->harm_value == (*stack)->harm_value - 1
		&& highest_in_stack(stack, (*stack)->harm_value))
	{
		order = 1;
		temp = (*stack)->next;
		while (temp && temp->next != last && order == 1)
		{
			if (temp->harm_value != temp->next->harm_value - 1)
				order = 0;
			temp = temp->next;
		}
		if (order == 1)
			rota(stack);
	}
}

void	id_rra(t_stack **stack)
{
	t_stack	*last;
	t_stack	*temp;
	int		order;

	last = *stack;
	while (last->next)
		last = last->next;
	if (last->harm_value == (*stack)->harm_value - 1
		&& lowest_in_stack(stack, last->harm_value))
	{
		order = 1;
		temp = (*stack)->next;
		while (temp->next != last && temp && order == 1)
		{
			if (temp->harm_value != temp->next->harm_value - 1)
				order = 0;
			temp = temp->next;
		}
		if (order == 1)
			rrota(stack);
	}	
}

void	id_sara(t_stack **stack)
{
	t_stack	*last;
	t_stack	*temp;
	int		order;

	last = *stack;
	while (last->next)
		last = last->next;
	if (highest_in_stack(stack, (*stack)->next->harm_value)
		&& lowest_in_stack(stack, (*stack)->harm_value))
	{
		order = 1;
		temp = (*stack)->next->next;
		while (temp->next != NULL && temp && order == 1)
		{
			if (temp->harm_value != temp->next->harm_value - 1)
				order = 0;
			temp = temp->next;
		}
		if (order == 1)
		{
			swapa(stack);
			rota(stack);
		}
	}
}

void	id_sarra(t_stack **stack)
{
	t_stack	*last;
	t_stack	*temp;
	int		order;

	last = *stack;
	while (last->next)
		last = last->next;
	if (lowest_in_stack(stack, last->harm_value)
		&& last->harm_value == (*stack)->next->harm_value - 1
		&& (*stack)->harm_value == (*stack)->next->harm_value + 1)
	{
		order = 1;
		temp = (*stack)->next->next;
		while (temp->next != NULL && temp->next != last && temp && order == 1)
		{
			if (temp->harm_value != temp->next->harm_value - 1)
				order = 0;
			temp = temp->next;
		}
		if (order == 1)
		{
			swapa(stack);
			rrota(stack);
		}
	}
}
