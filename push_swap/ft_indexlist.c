/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmirzakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:07:55 by lmirzakh          #+#    #+#             */
/*   Updated: 2022/06/19 16:47:35 by lmirzakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	fill_int_arr(int *arr, t_list **stack)
{
	unsigned int	i;
	t_list			*temp;

	if (!stack || !arr)
		return ;
	temp = *stack;
	i = 0;
	while (temp)
	{
		arr[i++] = temp->data;
		temp = temp->next;
	}
}

void	sort_int_arr(int *arr, unsigned int arr_len)
{
	unsigned int	i;

	if (!arr || arr_len < 2)
		return ;
	while (arr_len-- > 0)
	{
		i = -1;
		while (++i < arr_len)
			if (arr[i] > arr[i + 1])
				ft_swap(&arr[i], &arr[i + 1]);
	}
}

void	fill_indexes(t_list **stack, int *arr, unsigned int len)
{
	unsigned int	i;
	t_list			*temp;

	if (!stack || !arr || !len)
		return ;
	temp = *stack;
	while (temp)
	{
		i = -1;
		while (++i < len)
		{
			if (temp->data == arr[i])
			{
				temp->index = i + 1;
				break ;
			}
		}
		temp = temp->next;
	}
	free(arr);
}

void	ft_indexlist(t_list **stack)
{
	unsigned int	listlen;
	int				*arr;

	if (!stack)
		return ;
	listlen = ft_lstsize(*stack);
	arr = malloc(sizeof(int) * listlen);
	if (!arr)
	{
		free_list(stack);
		return ;
	}
	fill_int_arr(arr, stack);
	sort_int_arr(arr, listlen);
	fill_indexes(stack, arr, listlen);
	set_zero_flags(stack);
}
