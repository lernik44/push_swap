/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bottom_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmirzakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:28:56 by lmirzakh          #+#    #+#             */
/*   Updated: 2022/06/11 10:29:36 by lmirzakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	bottom_index(t_list **stack)
{
	int		number;

	number = -1;
	if (*stack)
	{
		rev_rot(stack);
		number = (*stack)->index;
		rot(stack);
	}
	return (number);
}
