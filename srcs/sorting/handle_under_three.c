/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_under_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:53:45 by chahan            #+#    #+#             */
/*   Updated: 2022/04/10 18:27:44 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_arg_two(t_stack *a, t_stack *b, int flag)
{
	if (flag == A)
	{
		if (a->top->value > a->top->next->value)
			swap_stack(a, A);
	}
	else
	{
		if (b->top->value < b->top->next->value)
			swap_stack(b, B);
		push_stack(b, a, A);
		push_stack(b, a, A);
	}
}

void	handle_under_three(int r, t_stack *a, t_stack *b, int flag)
{
	if (r == 3)
	{
		if (flag == A)
			handler_three_a(r, a);
		else
			handler_three_b(r, a, b);
	}
	else if (r == 2)
		handle_arg_two(a, b, flag);
	else if (r == 1)
	{
		if (flag == B)
			push_stack(b, a, A);
	}
}
