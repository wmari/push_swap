/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:52:53 by wmari             #+#    #+#             */
/*   Updated: 2022/03/30 09:54:35 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	long int		value;
	long int		harm_value;
	struct s_stack	*next;
}t_stack;

typedef struct s_list
{
	long int	*tab;
	size_t		nb_elem;
}t_list;

int		deal_with_arg(char **argv);
int		check_long(t_stack *stack);
t_list	*parsing(char **argv);
void	push_a(t_stack **stackA, t_stack **stackB);
void	push_b(t_stack **stackA, t_stack **stackB);
void	rrota(t_stack **stack);
void	rrotb(t_stack **stack);
void	rota(t_stack **stack);
void	rotb(t_stack **stack);
void	swapa(t_stack **stack);
void	swapb(t_stack **stack);
void	free_stack(t_stack *stack);
void	sort_stack(t_stack **stacka, t_stack **stackb);
int		check_arg(int argc, char **argv);
void	smart_push(t_stack **stacka, t_stack **stackb, int bit);
t_stack	*createstack(char **argv);
void	back_to_start(t_stack **stack, long int start);
void	back_to_a(t_stack **stacka, t_stack **stackb, int bit);
int		test_if_order(t_stack **stacka, t_stack **stackb);
void	smart_back(t_stack **stacka, t_stack **stackb, int bit);
void	back_to_start_b(t_stack **stack, long int start);
void	id_sa(t_stack **stack);
void	id_ra(t_stack **stack);
void	id_rra(t_stack **stack);
void	id_sara(t_stack **stack);
void	id_sarra(t_stack **stack);
void	identity_cont(t_stack **stack);
int		highest_in_stack(t_stack **stack, long int val);
int		lowest_in_stack(t_stack **stack, long int val);
int		no_arg(char **arg);
void	identity(t_stack **stacka, t_stack **stackb);
#endif
