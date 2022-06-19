/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmirzakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:27:58 by lmirzakh          #+#    #+#             */
/*   Updated: 2022/05/03 19:31:19 by lmirzakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

char	*arr_to_str(int argc, char **argv)
{
	char			*s;
	int				i;
	unsigned int	char_qty;

	i = 0;
	char_qty = 0;
	while (++i < argc)
		char_qty += ft_strlen(argv[i]);
	char_qty += argc;
	s = (char *)malloc(sizeof(char) * char_qty);
	if (!s)
		return (NULL);
	*s = 0;
	i = 0;
	while (++i < argc)
	{
		ft_strlcat(s, argv[i], char_qty);
		ft_strlcat(s, " ", char_qty);
	}
	return (s);
}

char	**make_arr(char *s)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = ft_split(s, ' ');
	if (!arr)
		return (NULL);
	if (!*arr)
		return (NULL);
	free(s);
	return (arr);
}

char	**ft_free_arr(char **arr)
{
	int	i;

	if (!arr)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

int	overlimit(char *num, int sign, int zero)
{
	if (!num)
		return (2);
	if (num[sign + zero] > '2')
		return (1);
	if (num[sign + zero] < '2')
		return (0);
	if (sign == 1 && num[0] == '-' && num[sign + zero] == '2')
	{
		if (ft_atoi(num) > 1)
			return (1);
	}
	else if (num[sign + zero] == '2')
		if (ft_atoi(num) < 1)
			return (1);
	return (0);
}

char	**arr_check(char **arr)
{
	int	i;
	int	sign;
	int	j;
	int	zero;

	if (!arr)
		return (NULL);
	i = -1;
	while (arr[++i])
	{
		sign = 0;
		if (arr[i][sign] == '+' || arr[i][sign] == '-')
			sign++;
		zero = 0;
		while (arr[i][sign + zero] == '0')
			zero++;
		j = -1;
		while (arr[i][sign + zero + ++j])
			if (!ft_isdigit(arr[i][sign + zero + j]) || j == 10)
				return (NULL);
		if ((j == 0 && zero == 0) || (j == 10 && overlimit(arr[i], sign, zero)))
			return (NULL);
	}
	return (arr);
}
