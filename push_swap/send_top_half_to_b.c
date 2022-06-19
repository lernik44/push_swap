/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_top_half_to_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmirzakh <lmirzakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 12:56:47 by lmirzakh          #+#    #+#             */
/*   Updated: 2022/06/19 13:13:43 by lmirzakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

static void	ra_addup_next(t_list **stack_a, t_list **stack_b, t_mem *mem_x)
{
	command(stack_a, stack_b, "ra");
	mem_x->next++;
}

static void	pb_addup_counter(t_list **stack_a, t_list **stack_b, t_mem *mem_x)
{
	(*stack_a)->flag++;
	command(stack_a, stack_b, "pb");
	mem_x->counter++;
}

int	send_tophalf_to_b(t_list **stack_a, t_list **stack_b, t_mem *mem_x)
{
	int	activated;

	activated = 0;
	mem_x->counter = 0;
	while ((*stack_a) && (*stack_a)->flag == 0
		&& mem_x->counter < mem_x->mid - mem_x->next)
	{
		activated = 1;
		if ((*stack_a)->index < mem_x->mid)
		{
			if ((*stack_a)->index == mem_x->next
				&& bottom_index(stack_a) == mem_x->next - 1)
				ra_addup_next(stack_a, stack_b, mem_x);
			else
				pb_addup_counter(stack_a, stack_b, mem_x);
		}
		else
			command(stack_a, stack_b, "ra");
	}
	return (activated);
}
