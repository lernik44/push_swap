/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_min_to_top.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmirzakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 20:11:33 by lmirzakh          #+#    #+#             */
/*   Updated: 2022/06/11 16:17:32 by lmirzakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	find_next(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	temp = (*stack_a);
	if (temp->index > (*stack_b)->index)
	{
		if (bottom_index(stack_a) < (*stack_b)->index)
			return ((*stack_a)->index);
		while (temp && temp->index > (*stack_b)->index)
			temp = temp->next;
	}
	while (temp && temp->index < (*stack_b)->index)
		temp = temp->next;
	if (temp)
		return (temp->index);
	send_min_to_top(stack_a, stack_b);
	return ((*stack_a)->index);
}

void	send_next_to_top(t_list **stack_a, t_list **stack_b, int next)
{
	int		count;
	int		next_ind;
	t_list	*temp;

	next_ind = 1;
	temp = *stack_a;
	while (temp && temp->index != next)
	{
		temp = temp->next;
		next_ind++;
	}
	count = (int)ft_lstsize(*stack_a);
	if (count - next_ind + 1 >= next_ind)
		while ((*stack_a)->index != next)
			command(stack_a, stack_b, "ra");
	else
		while ((*stack_a)->index != next)
			command(stack_a, stack_b, "rra");
}

void	send_min_to_top(t_list **stack_a, t_list **stack_b)
{
	int	next;

	next = find_min(stack_a);
	send_next_to_top(stack_a, stack_b, next);
}
