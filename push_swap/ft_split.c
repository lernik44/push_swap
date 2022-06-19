/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmirzakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:47:15 by lmirzakh          #+#    #+#             */
/*   Updated: 2022/04/28 19:22:10 by lmirzakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

static size_t	str_count(char const *s, char c)
{
	size_t	str_qty;
	size_t	i;

	str_qty = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			str_qty++;
		i++;
	}
	return (str_qty);
}

static char	**free_mem(char **str_arr)
{
	size_t	i;

	i = 0;
	while (str_arr[i])
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
	return (NULL);
}

static char	**ft_split2(char **str_arr, char const *s, char c, size_t s_i)
{
	size_t	wordlen;
	size_t	str_start;
	size_t	str_i;

	str_i = 0;
	while (s[s_i])
	{
		while (s[s_i] == c)
			s_i++;
		if (!s[s_i])
			break ;
		wordlen = 0;
		str_start = s_i;
		while (s[s_i] != c && s[s_i] && ++s_i)
			wordlen++;
		str_arr[str_i] = ft_substr(s, str_start, wordlen);
		if (!(str_arr[str_i]))
			return (free_mem(str_arr));
		str_i++;
	}
	str_arr[str_i] = NULL;
	return (str_arr);
}

char	**ft_split(char const *s, char c)
{
	char	**str_arr;
	size_t	str_qty;
	size_t	s_i;

	str_qty = str_count(s, c);
	str_arr = (char **)malloc(sizeof(char *) * (str_qty + 1));
	if (!str_arr)
		return (NULL);
	s_i = 0;
	ft_split2(str_arr, s, c, s_i);
	return (str_arr);
}
