/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmirzakh <lmirzakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:43:02 by lmirzakh          #+#    #+#             */
/*   Updated: 2022/06/19 16:48:31 by lmirzakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PUSH_SWAP_H
# define LIB_PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				data;
	int				index;
	int				flag;
	struct s_list	*next;
}					t_list;

typedef struct mem
{
	int	counter;
	int	max;
	int	next;
	int	mid;
	int	flag;
}				t_mem;

void	ft_putstr(char *s);
int		ft_strcmp(char *s1, char *s2);
void	swap(t_list **stack);
void	swap2(t_list **stack_a, t_list **stack_b);
void	push(t_list **in, t_list **out);
void	rot(t_list **stack);
void	rot2(t_list	**stack_a, t_list **stack_b);
void	rev_rot(t_list **stack);
void	rev_rot2(t_list **stack_a, t_list **stack_b);
void	command(t_list **stack_a, t_list **stack_b, char *s);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*arr_to_str(int argc, char **argv);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
char	**make_arr(char *s);
char	**ft_free_arr(char **arr);
int		overlimit(char *num, int sign, int zero);
char	**arr_check(char **arr);
t_list	**free_list(t_list **list);
int		check_duplic(t_list **beginning, int data);
t_list	**lst_convert(char **arr);
t_list	**create_stack(int argc, char **argv);
int		ft_lstsize(t_list *lst);
void	fill_indexes(t_list **stack, int *arr, unsigned int len);
void	ft_indexlist(t_list **stack);
void	set_zero_flags(t_list **stack);
int		check_sorted(t_list	**stack);
void	algo3(t_list **stack_a, t_list **stack_b);
void	algo3b(t_list **stack_a, t_list **stack_b);
void	algo5(t_list **stack_a, t_list **stack_b);
void	algo100(t_list **stack_a, t_list **stack_b);
int		find_max(t_list **stack);
int		find_min(t_list **stack);
int		find_next(t_list **stack_a, t_list **stack_b);
void	send_min_to_top(t_list **stack_a, t_list **stack_b);
void	send_next_to_top(t_list **stack_a, t_list **stack_b, int next);
int		bottom_index(t_list **stack);
int		send_tophalf_to_b(t_list **stack_a, t_list **stack_b, t_mem *mem_x);
int		empty_b(t_list **stack_a, t_list **stack_b, t_mem *mem_x);

#endif
