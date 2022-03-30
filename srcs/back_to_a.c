/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:15:57 by wmari             #+#    #+#             */
/*   Updated: 2022/03/30 09:37:04 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

long int	find_start_b(t_stack **stack, int bit)
{
	t_stack	*temp;

	temp = *stack;
	while (temp)
	{
		if (!((temp->harm_value >> bit) & 1))
			return (temp->harm_value);
		temp = temp->next;
	}
	return (-1);
}

int	still_back(t_stack **stack, int bit)
{
	t_stack	*temp;

	temp = *stack;
	while (temp)
	{
		if ((temp->harm_value >> bit) & 1)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	back_to_a(t_stack **stacka, t_stack **stackb, int bit)
{
	long int	start;

	start = find_start_b(stackb, bit);
	if (test_if_order(stacka, stackb))
	{
		while (*stackb)
			push_a(stacka, stackb);
	}
	else
	{	
		while (still_back(stackb, bit))
			smart_back(stacka, stackb, bit);
		if (bit > 1)
			back_to_start_b(stackb, start);
	}
	identity(stacka, stackb);
}
