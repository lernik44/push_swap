/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmirzakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:39:55 by lmirzakh          #+#    #+#             */
/*   Updated: 2022/05/29 22:06:26 by lmirzakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

static void	algo3_2(t_list **stack_a, t_list **stack_b, int min, int max)
{
	if ((*stack_a)->index == max)
	{
		if ((*stack_a)->next->index == min)
			command(stack_a, stack_b, "ra");
		else
		{
			command(stack_a, stack_b, "sa");
			command(stack_a, stack_b, "rra");
		}
	}
	else
	{
		if ((*stack_a)->next->index == min)
			command(stack_a, stack_b, "sa");
		else
			command(stack_a, stack_b, "rra");
	}
}

void	algo3(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	max;

	min = find_min(stack_a);
	max = find_max(stack_a);
	if (!stack_a || !*stack_a)
		return ;
	if ((*stack_a)->index == min)
	{
		command(stack_a, stack_b, "rra");
		command(stack_a, stack_b, "sa");
	}
	else
		algo3_2(stack_a, stack_b, min, max);
}
