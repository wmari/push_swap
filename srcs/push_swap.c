/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:37:16 by wmari             #+#    #+#             */
/*   Updated: 2022/03/30 10:22:50 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	free_stack(t_stack *stack)
{
	if (stack->next)
		free_stack(stack->next);
	free(stack);
}

void	harmonized(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*parkour;
	int		count;

	temp = *stack;
	while (temp)
	{
		count = 0;
		parkour = *stack;
		while (parkour)
		{
			if (parkour->value < temp->value)
				count++;
			parkour = parkour->next;
		}
		temp->harm_value = count;
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb;

	if (argc == 1 || no_arg(argv))
		return (0);
	if (deal_with_arg(argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	stacka = createstack(argv);
	if (stacka == NULL)
		write(2, "Error\n", 6);
	if (check_long(stacka))
	{
		free_stack(stacka);
		write(2, "Error\n", 6);
		return (0);
	}
	stackb = NULL;
	harmonized(&stacka);
	sort_stack(&stacka, &stackb);
	free_stack(stacka);
	return (0);
}
