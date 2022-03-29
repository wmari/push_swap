/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:52:31 by wmari             #+#    #+#             */
/*   Updated: 2022/03/29 18:35:38 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	notsorted(t_stack **stacka, t_stack **stackb)
{
	t_stack	*temp;

	if (*stackb != NULL)
		return (1);
	temp = *stacka;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	test_if_order(t_stack **stacka, t_stack **stackb)
{
	t_stack	*temp;

	temp = *stacka;
	if ((*stacka) && (*stackb))
	{
		if ((*stacka)->harm_value != (*stackb)->harm_value + 1)
			return (0);
	}
	while (temp->next)
	{
		if (temp->harm_value != temp->next->harm_value - 1)
			return (0);
		temp = temp->next;
	}
	temp = *stackb;
	while (temp && temp->next)
	{
		if (temp->harm_value != temp->next->harm_value + 1)
			return (0);
		temp = temp->next;
	}
	return (1);
}

long int	find_start(t_stack **stacka, int bit)
{
	t_stack	*temp;

	temp = *stacka;
	while (temp)
	{
		if ((temp->harm_value >> bit) & 1)
			return (temp->harm_value);
		temp = temp->next;
	}
	return (-1);
}

int	still_push(t_stack **stacka, t_stack **stackb, int bit)
{
	t_stack	*temp;

	temp = *stacka;
	if (!notsorted(stacka, stackb))
		return (0);
	while (temp)
	{
		if (!((temp->harm_value >> bit) & 1))
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	sort_stack(t_stack **stacka, t_stack **stackb)
{
	int			bit;
	long int	start;

	bit = 0;
	if (!(highest_in_stack(stacka, 1)))
		identity_cont(stacka);
	while (notsorted(stacka, stackb))
	{
		start = find_start(stacka, bit);
		if (start > -1)
		{
			while (still_push(stacka, stackb, bit))
				smart_push(stacka, stackb, bit);
			if (bit > 0 && notsorted(stacka, stackb))
				back_to_start(stacka, start);
			bit++;
		}
		back_to_a(stacka, stackb, bit);
	}
}
