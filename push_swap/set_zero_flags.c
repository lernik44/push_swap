/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sero_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmirzakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:37:51 by lmirzakh          #+#    #+#             */
/*   Updated: 2022/05/28 22:07:45 by lmirzakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	set_zero_flags(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp)
	{
		(*stack)->flag = 0;
		temp = temp->next;
	}
}
