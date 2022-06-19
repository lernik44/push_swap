/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmirzakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 20:13:46 by lmirzakh          #+#    #+#             */
/*   Updated: 2022/06/04 20:13:49 by lmirzakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	check_sorted(t_list	**stack_a)
{
	t_list	*temp;

	if (!stack_a || !*stack_a)
		return (-1);
	temp = *stack_a;
	while (temp->next)
	{
		if (temp->index > temp->next->index)
			return (0);
		temp = temp->next;
	}
	return (1);
}
