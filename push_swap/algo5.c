/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmirzakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:39:55 by lmirzakh          #+#    #+#             */
/*   Updated: 2022/06/04 19:51:21 by lmirzakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	algo5(t_list **stack_a, t_list **stack_b)
{
	int	next;
	int	count;

	if (!stack_a || !*stack_a)
		return ;
	count = (int)ft_lstsize(*stack_a);
	while (count > 3)
	{
		command(stack_a, stack_b, "pb");
		count--;
	}
	if (check_sorted(stack_a) != 1)
		algo3(stack_a, stack_b);
	while (*stack_b)
	{
		next = find_next(stack_a, stack_b);
		send_next_to_top(stack_a, stack_b, next);
		command(stack_a, stack_b, "pa");
	}
	send_min_to_top(stack_a, stack_b);
}
