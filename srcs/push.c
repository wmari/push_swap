/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:48:02 by wmari             #+#    #+#             */
/*   Updated: 2022/03/17 14:48:07 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	push_b(t_stack **stackA, t_stack **stackB)
{
	t_stack *temp;

	temp = (*stackA)->next;
	if (*stackA)
	{
		if (*stackB)
		{
			(*stackA)->next = *stackB;
			*stackB = *stackA;
			*stackA = temp;
		}
		else
		{
			*stackB = *stackA;
			(*stackB)->next = NULL;
			*stackA = temp;
		}
		write(1,"pb\n",3);
	}
}

void	push_a(t_stack **stackA, t_stack **stackB)
{
	t_stack *temp;

	temp = (*stackB)->next;
	if (*stackB)
	{
		if (*stackA)
		{
			(*stackB)->next = *stackA;
			*stackA = *stackB;
			*stackB = temp;
		}
		else
		{
			*stackA = *stackB;
			(*stackA)->next = NULL;
			*stackB = temp;
		}
		write(1,"pa\n",3);
	}
}
