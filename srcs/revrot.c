/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:48:18 by wmari             #+#    #+#             */
/*   Updated: 2022/03/21 17:31:12 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	rrota(t_stack **stack)
{
	t_stack	*temp;

	if ((*stack)->next)
	{
		temp = *stack;
		while (temp->next->next)
			temp = temp->next;
		temp->next->next = *stack;
		*stack = temp->next;
		temp->next = NULL;
		write(1, "rra\n", 4);
	}
}

void	rrotb(t_stack **stack)
{
	t_stack	*temp;

	if ((*stack)->next)
	{
		temp = *stack;
		while (temp->next->next)
			temp = temp->next;
		temp->next->next = *stack;
		*stack = temp->next;
		temp->next = NULL;
		write(1, "rrb\n", 4);
	}
}
