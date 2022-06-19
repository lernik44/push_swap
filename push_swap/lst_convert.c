/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmirzakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:04:28 by lmirzakh          #+#    #+#             */
/*   Updated: 2022/05/03 18:06:41 by lmirzakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

t_list	**free_list(t_list **list)
{
	if (!list)
		return (NULL);
	while (*list)
	{
		free(*list);
		*list = (*list)->next;
	}
	free(list);
	return (NULL);
}

int	check_duplic(t_list **beginning, int data)
{
	t_list	*temp;

	temp = *beginning;
	if (!temp)
		return (0);
	while (temp->next)
	{
		if (temp->data == data)
			return (1);
		temp = temp->next;
	}
	return (0);
}

static t_list	**lst_convert2(t_list **beginning, char	**arr)
{
	t_list	*list;
	int		i;

	*beginning = malloc(sizeof(t_list));
	list = *beginning;
	i = -1;
	while (arr[++i])
	{
		if (!list)
			return (free_list(beginning));
		list->next = NULL;
		list->data = ft_atoi(arr[i]);
		if (check_duplic(beginning, list->data))
			return (free_list(beginning));
		if (arr[i + 1])
			list->next = malloc(sizeof(t_list));
		list = list->next;
	}
	return (beginning);
}

t_list	**lst_convert(char **arr)
{
	t_list	**beginning;

	if (!arr)
		return (NULL);
	beginning = malloc(sizeof(t_list *));
	if (!beginning)
		return (NULL);
	beginning = lst_convert2(beginning, arr);
	return (beginning);
}

t_list	**create_stack(int argc, char **argv)
{
	t_list	**stack_a;
	char	**arr;
	char	*s;

	stack_a = NULL;
	arr = NULL;
	if (argc == 1)
		return (NULL);
	else
	{
		s = arr_to_str(argc, argv);
		arr = make_arr(s);
		stack_a = lst_convert(arr_check(arr));
		ft_free_arr(arr);
	}
	if (!stack_a && argc != 1)
		write(1, "Error\n", 6);
	ft_indexlist(stack_a);
	return (stack_a);
}
