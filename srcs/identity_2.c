/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identity_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:11:41 by wmari             #+#    #+#             */
/*   Updated: 2022/03/30 09:49:28 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	rraparapa(t_stack **stacka, t_stack **stackb)
{
	rrota(stacka);
	push_a(stacka, stackb);
	rota(stacka);
	push_a(stacka, stackb);
}

void	saparapa(t_stack **stacka, t_stack **stackb)
{
	swapa(stacka);
	push_a(stacka, stackb);
	rota(stacka);
	push_a(stacka, stackb);
}

void	sapapara(t_stack **stacka, t_stack **stackb)
{
	swapa(stacka);
	push_a(stacka, stackb);
	push_a(stacka, stackb);
	rota(stacka);
}

void	rrapapara(t_stack **stacka, t_stack **stackb)
{
	rrota(stacka);
	push_a(stacka, stackb);
	push_a(stacka, stackb);
	rota(stacka);
}

void	identity(t_stack **stacka, t_stack **stackb)
{
	if (highest_in_stack(stacka, 3) && highest_in_stack(stackb, 4))
	{
		if ((*stacka)->next->harm_value == 1)
		{
			if ((*stackb)->harm_value == 0)
				sapapara(stacka, stackb);
			else
				saparapa(stacka, stackb);
		}
		else
		{
			if ((*stackb)->harm_value == 0)
				rrapapara(stacka, stackb);
			else
				rraparapa(stacka, stackb);
		}
	}
}
