/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to_start_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:43:50 by wmari             #+#    #+#             */
/*   Updated: 2022/03/21 16:49:42 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	back_to_start_b(t_stack **stack, long int start)
{
	int		count;
	int		tot;
	t_stack	*temp;

	count = 0;
	tot = 0;
	temp = *stack;
	while (start != temp->harm_value)
	{
		count++;
		temp = temp->next;
	}
	while (temp)
	{
		tot++;
		temp = temp->next;
	}
	while ((*stack)->harm_value != start)
	{
		if (count > tot)
			rrotb(stack);
		else
			rotb(stack);
	}
}
