/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmirzakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 12:40:59 by lmirzakh          #+#    #+#             */
/*   Updated: 2022/06/19 12:41:02 by lmirzakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	*list_b;

	list_b = NULL;
	stack_a = create_stack(argc, argv);
	if (!stack_a)
		return (-1);
	if (check_sorted(stack_a) == 1)
		return (0);
	if (ft_lstsize(*stack_a) == 3)
		algo3(stack_a, &list_b);
	else if (ft_lstsize(*stack_a) <= 5)
		algo5(stack_a, &list_b);
	else
		algo100(stack_a, &list_b);
	return (0);
}
