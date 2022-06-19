/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmirzakh <lmirzakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:39:29 by lmirzakh          #+#    #+#             */
/*   Updated: 2022/06/19 16:49:01 by lmirzakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	rot(t_list **stack)
{
	t_list	*temp;

	if (!*stack)
		return ;
	if (!((*stack)->next))
		return ;
	if (!((*stack)->next->next))
	{
		swap(stack);
		return ;
	}
	temp = *stack;
	while ((*stack)->next)
		*stack = (*stack)->next;
	(*stack)->next = temp;
	*stack = (*stack)->next;
	temp = (*stack)->next;
	(*stack)->next = NULL;
	*stack = temp;
}

void	rot2(t_list	**stack_a, t_list **stack_b)
{
	rot(stack_a);
	rot(stack_b);
}

void	rev_rot(t_list **stack)
{
	t_list	*temp;

	if (!*stack)
		return ;
	if (!((*stack)->next))
		return ;
	if (!((*stack)->next->next))
	{
		swap(stack);
		return ;
	}
	temp = *stack;
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	(*stack)->next->next = temp;
	temp = (*stack)->next;
	(*stack)->next = NULL;
	*stack = temp;
}

void	rev_rot2(t_list **stack_a, t_list **stack_b)
{
	rev_rot(stack_a);
	rev_rot(stack_b);
}

void	command(t_list **stack_a, t_list **stack_b, char *s)
{
	if (ft_strcmp(s, "sa") == 0)
		swap(stack_a);
	else if (ft_strcmp(s, "sb") == 0)
		swap(stack_b);
	else if (ft_strcmp(s, "ss") == 0)
		swap2(stack_a, stack_b);
	else if (ft_strcmp(s, "pa") == 0)
		push(stack_a, stack_b);
	else if (ft_strcmp(s, "pb") == 0)
		push(stack_b, stack_a);
	else if (ft_strcmp(s, "ra") == 0)
		rot(stack_a);
	else if (ft_strcmp(s, "rb") == 0)
		rot(stack_b);
	else if (ft_strcmp(s, "rr") == 0)
		rot2(stack_a, stack_b);
	else if (ft_strcmp(s, "rra") == 0)
		rev_rot(stack_a);
	else if (ft_strcmp(s, "rrb") == 0)
		rev_rot(stack_b);
	else if (ft_strcmp(s, "rrr") == 0)
		rev_rot2(stack_a, stack_b);
	ft_putstr(s);
}
