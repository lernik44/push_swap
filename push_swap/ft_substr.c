/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmirzakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:31:01 by lmirzakh          #+#    #+#             */
/*   Updated: 2022/04/28 13:41:20 by lmirzakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*text;
	size_t	min_len;

	min_len = len;
	if (ft_strlen(s + start) < len)
		min_len = ft_strlen(s + start);
	if (ft_strlen(s) < start)
		min_len = 0;
	text = (char *)malloc(sizeof(char) * (min_len + 1));
	if (!text)
		return (NULL);
	ft_strlcpy(text, s + start, min_len + 1);
	return (text);
}
