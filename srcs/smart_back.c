/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_back.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:30:45 by wmari             #+#    #+#             */
/*   Updated: 2022/03/21 16:54:21 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	rev_rot_to_back(t_stack **stack, int tot)
{
	while (tot > 0)
	{
		rrotb(stack);
		tot--;
	}
}

void	rot_to_back(t_stack **stack, int count)
{
	while (count > 0)
	{
		rotb(stack);
		count--;
	}
}

void	go_to_back(t_stack **stack, int bit)
{
	t_stack	*temp;
	int		count;
	int		tot;

	temp = *stack;
	count = 0;
	tot = 0;
	while ((!((temp->harm_value >> bit) & 1)) && temp)
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
		rot_to_back(stack, count);
	else
		rev_rot_to_back(stack, tot);
}

void	smart_back(t_stack **stacka, t_stack **stackb, int bit)
{
	if (test_if_order(stacka, stackb))
	{
		while (*stackb)
			push_a(stacka, stackb);
	}
	else if (((*stackb)->harm_value >> bit) & 1)
		push_a(stacka, stackb);
	else
		go_to_back(stackb, bit);
}
