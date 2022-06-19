/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmirzakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:39:55 by lmirzakh          #+#    #+#             */
/*   Updated: 2022/06/12 19:26:14 by lmirzakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

static void	algo3b_2(t_list **stack_a, t_list **stack_b, int min, int max)
{
	if ((*stack_b)->index == max)
	{
		if ((*stack_b)->next->index == min)
			command(stack_a, stack_b, "rb");
		else
		{
			command(stack_a, stack_b, "sb");
			command(stack_a, stack_b, "rrb");
		}
	}
	else
	{
		if ((*stack_b)->next->index == min)
			command(stack_a, stack_b, "sb");
		else
			command(stack_a, stack_b, "rrb");
	}
}

void	algo3b(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	max;

	min = find_min(stack_b);
	max = find_max(stack_b);
	if (!stack_a || !*stack_a)
		return ;
	if ((*stack_b)->index == min)
	{
		command(stack_a, stack_b, "rrb");
		command(stack_a, stack_b, "sb");
	}
	else
		algo3b_2(stack_a, stack_b, min, max);
}
