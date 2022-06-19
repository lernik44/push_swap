/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmirzakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 13:16:50 by lmirzakh          #+#    #+#             */
/*   Updated: 2022/06/19 14:37:42 by lmirzakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

static void	pa_ra_addup_next(t_list **stack_a, t_list **stack_b, t_mem *mem_x)
{
	command(stack_a, stack_b, "pa");
	command(stack_a, stack_b, "ra");
	mem_x->next++;
}

static void	empty_rem_3(t_list **stack_a, t_list **stack_b, t_mem *mem_x)
{
	algo3b(stack_a, stack_b);
	while (*stack_b)
	{
		if ((*stack_b)->index == mem_x->next)
			pa_ra_addup_next(stack_a, stack_b, mem_x);
		else
			command(stack_a, stack_b, "pa");
	}
}

static void	split_empty(t_list **stack_a, t_list **stack_b, t_mem *mem_x)
{
	if ((*stack_b)->index >= mem_x->mid)
	{
		mem_x->counter--;
		command(stack_a, stack_b, "pa");
		(*stack_a)->flag++;
	}
	else
	{
		if ((*stack_b)->index == mem_x->next)
			pa_ra_addup_next(stack_a, stack_b, mem_x);
		else
			command(stack_a, stack_b, "rb");
	}
}

int	empty_b(t_list **stack_a, t_list **stack_b, t_mem *mem_x)
{
	int	activated;

	activated = 0;
	mem_x->max = find_max(stack_b);
	while (*stack_b)
	{
		activated = 1;
		mem_x->mid = (mem_x->max - mem_x->next + 1) / 2 + mem_x->next;
		mem_x->counter = mem_x->max - mem_x->mid;
		while ((*stack_b) && mem_x->counter >= 0)
		{
			if (ft_lstsize(*stack_b) == 3)
				empty_rem_3(stack_a, stack_b, mem_x);
			else
				split_empty(stack_a, stack_b, mem_x);
		}
	}
	return (activated);
}
