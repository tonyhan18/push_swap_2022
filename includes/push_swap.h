/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:53:45 by chahan            #+#    #+#             */
/*   Updated: 2022/04/10 18:51:43 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "structures.h"

void	print_error(void);

void	free_all(t_stack *a, t_stack *b);

int		get_mid_value_five(t_node *node);
int		get_min_value(t_node *node, int size);
int		get_max_value(t_node *node, int size);

void	push_stack(t_stack *from, t_stack *to, int flag);

void	reverse_rotate_stack(t_stack *stack, int flag);
void	reverse_rotate_all_stack(t_stack *a, t_stack *b, int flag);

void	rotate_stack(t_stack *stack, int flag);
void	rotate_all_stack(t_stack *a, t_stack *b, int flag);

void	swap_stack(t_stack *stack, int flag);
void	swap_all_stack(t_stack *a, t_stack *b, int flag);

int		check_arg(char *arg);
void	check_duplicate(t_node *a);

int		ft_atoi(char *arg);

t_stack	*make_stack_new(void);
t_node	*make_stack_param(t_stack **stack, int argc, char **argv);

void	handle_arg_two(t_stack *a, t_stack *b, int flag);
void	handle_under_three(int r, t_stack *a, t_stack *b, int flag);

void	a_to_b(int r, t_stack *a, t_stack *b, int *cnt);

void	handler_five_sort(int size, t_stack *a, t_stack *b, int flag);
void	handler_five(t_stack *a, t_stack *b);

void	handler_three_a(int r, t_stack *a);

void	handler_three_b(int r, t_stack *a, t_stack *b);

void	b_to_a(int r, t_stack *a, t_stack *b, int *cnt);

void	utils_init_value(t_value *var);
void	utils_select_pivot(int r, t_stack *stack, t_value *var);
void	push_swap(t_stack *a, t_stack *b);

#endif
