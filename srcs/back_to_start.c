/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:07:28 by wmari             #+#    #+#             */
/*   Updated: 2022/03/21 16:50:15 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	back_to_start(t_stack **stack, long int start)
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
			rrota(stack);
		else
			rota(stack);
	}
}
