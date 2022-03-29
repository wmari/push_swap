/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identity_cont.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:15:57 by wmari             #+#    #+#             */
/*   Updated: 2022/03/29 16:46:47 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	identity_cont(t_stack **stack)
{
	id_sa(stack);
	id_ra(stack);
	id_rra(stack);
	id_sara(stack);
	id_sarra(stack);
}

int		highest_in_stack(t_stack **stack, long int val)
{
	t_stack	*temp;

	temp = *stack;
	while (temp)
	{
		if (val < temp->harm_value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int		lowest_in_stack(t_stack **stack, long int val)
{
	t_stack	*temp;

	temp = *stack;
	while (temp)
	{
		if (val > temp->harm_value)
			return (0);
		temp = temp->next;
	}
	return (1);
}
