/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:42:05 by wmari             #+#    #+#             */
/*   Updated: 2022/03/21 16:39:52 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	rot_to_push(t_stack **stack, int count)
{
	while (count > 0)
	{
		rota(stack);
		count--;
	}
}

void	rev_rot_to_push(t_stack **stack, int tot)
{
	while (tot > 0)
	{
		rrota(stack);
		tot--;
	}
}

void	go_to_next_push(t_stack **stack, int bit)
{
	t_stack	*temp;
	int		count;
	int		tot;

	count = 0;
	tot = 0;
	temp = *stack;
	while (((temp->harm_value >> bit) & 1) && temp)
	{
		temp = temp->next;
		count++;
	}
	while (temp)
	{
		tot++;
		temp = temp->next;
	}
	if (tot > count)
		rot_to_push(stack, count);
	else
		rev_rot_to_push(stack, tot);
}

void	smart_push(t_stack **stacka, t_stack **stackb, int bit)
{
	if (test_if_order(stacka, stackb))
	{
		while (*stackb)
			push_a(stacka, stackb);
	}
	else if (!(((*stacka)->harm_value >> bit) & 1))
		push_b(stacka, stackb);
	else
		go_to_next_push(stacka, bit);
}
