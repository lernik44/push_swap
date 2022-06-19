/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmirzakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:35:57 by lmirzakh          #+#    #+#             */
/*   Updated: 2022/06/19 16:46:22 by lmirzakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	ft_putstr(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	swap(t_list **stack)
{
	t_list	*temp;

	if (!(*stack))
		return ;
	if (!(*stack)->next)
		return ;
	temp = (*stack)->next->next;
	(*stack)->next->next = *stack;
	*stack = (*stack)->next;
	(*stack)->next->next = temp;
}

void	swap2(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	push(t_list **in, t_list **out)
{
	t_list	*temp;

	if (!*out)
		return ;
	temp = (*out)->next;
	(*out)->next = *in;
	*in = *out;
	*out = temp;
}
