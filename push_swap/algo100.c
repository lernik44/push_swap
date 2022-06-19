/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo100.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmirzakh <lmirzakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 12:51:42 by lmirzakh          #+#    #+#             */
/*   Updated: 2022/06/19 13:17:19 by lmirzakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	first_split_to_b(t_list **stack_a, t_list **stack_b, t_mem *mem_x)
{
	mem_x->next = 1;
	mem_x->max = find_max(stack_a);
	mem_x->flag = 0;
	mem_x->mid = (mem_x->max - mem_x->next + 1) / 2 + mem_x->next;
	send_tophalf_to_b(stack_a, stack_b, mem_x);
}

int	send_back_to_b(t_list **stack_a, t_list **stack_b, t_mem *mem_x)
{
	int	activated;

	activated = 0;
	while ((*stack_a)->flag > 0)
	{
		activated = 1;
		if ((*stack_a)->index == mem_x->next)
		{
			command(stack_a, stack_b, "ra");
			mem_x->next++;
		}
		else
			command(stack_a, stack_b, "pb");
	}
	return (activated);
}

int	second_split_to_b(t_list **stack_a, t_list **stack_b, t_mem *mem_x)
{
	int	activated;

	activated = 0;
	mem_x->max = find_max(stack_a);
	mem_x->mid = (mem_x->max - mem_x->next + 1) / 2 + mem_x->next;
	mem_x->counter = 0;
	if (send_tophalf_to_b(stack_a, stack_b, mem_x))
	{
		activated = 1;
		while (bottom_index(stack_a) != mem_x->next - 1)
		{
			if (*stack_b && (*stack_b)->index != mem_x->next)
				command(stack_a, stack_b, "rrr");
			else
				command(stack_a, stack_b, "rra");
		}
	}
	return (activated);
}

void	algo100(t_list **stack_a, t_list **stack_b)
{
	t_mem	mem_x;

	first_split_to_b(stack_a, stack_b, &mem_x);
	while (empty_b(stack_a, stack_b, &mem_x)
		|| send_back_to_b(stack_a, stack_b, &mem_x))
		mem_x.flag++;
	while (second_split_to_b(stack_a, stack_b, &mem_x))
		while (empty_b(stack_a, stack_b, &mem_x)
			|| send_back_to_b(stack_a, stack_b, &mem_x))
			mem_x.flag++;
	send_min_to_top(stack_a, stack_b);
}
