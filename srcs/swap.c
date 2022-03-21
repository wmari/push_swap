/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:48:43 by wmari             #+#    #+#             */
/*   Updated: 2022/03/17 14:48:45 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header/push_swap.h"

void	swapa(t_stack **stack)
{
	t_stack	*temp;

	if ((*stack)->next)
	{
		temp = (*stack)->next;
		(*stack)->next = temp->next;
		temp->next = *stack;
		*stack = temp;
		write(1, "sa\n", 3);
	}
}

void	swapb(t_stack **stack)
{
	t_stack	*temp;

	if ((*stack)->next)
	{
		temp = (*stack)->next;
		(*stack)->next = temp->next;
		temp->next = *stack;
		*stack = temp;
		write(1, "sb\n", 3);
	}
}
