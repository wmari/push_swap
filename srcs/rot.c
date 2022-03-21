/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:48:32 by wmari             #+#    #+#             */
/*   Updated: 2022/03/21 17:26:34 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	rota(t_stack **stack)
{
	t_stack	*temp;

	if ((*stack)->next)
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = *stack;
		temp = (*stack)->next;
		(*stack)->next = NULL;
		*stack = temp;
		write(1, "ra\n", 3);
	}
}

void	rotb(t_stack **stack)
{
	t_stack	*temp;

	if ((*stack)->next)
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = *stack;
		temp = (*stack)->next;
		(*stack)->next = NULL;
		*stack = temp;
		write(1, "rb\n", 3);
	}
}
