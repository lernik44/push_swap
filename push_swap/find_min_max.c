/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmirzakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 20:14:02 by lmirzakh          #+#    #+#             */
/*   Updated: 2022/06/04 20:14:04 by lmirzakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	find_min(t_list **stack)
{
	t_list	*temp;
	int		min;

	min = INT_MAX;
	temp = *stack;
	while (temp)
	{
		if (temp->index < min)
			min = temp->index;
		temp = temp->next;
	}
	return (min);
}

int	find_max(t_list **stack)
{
	t_list	*temp;
	int		max;

	max = INT_MIN;
	temp = *stack;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	return (max);
}
