/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:53:45 by chahan            #+#    #+#             */
/*   Updated: 2022/04/10 18:44:48 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	top_min_a(t_stack *a, int max)
{
	if (a->size == 3)
	{
		if (a->top->next->value == max)
		{
			reverse_rotate_stack(a, A);
			swap_stack(a, A);
		}
	}
	else
	{
		if (a->top->next->value == max)
		{
			rotate_stack(a, A);
			swap_stack(a, A);
			reverse_rotate_stack(a, A);
		}
	}
}

static void	middle_min_a(t_stack *a, int max)
{
	if (a->size == 3)
	{
		if (a->bottom->value == max)
			swap_stack(a, A);
		else
			rotate_stack(a, A);
	}
	else
	{
		swap_stack(a, A);
		if (a->top->next->value == max)
		{
			rotate_stack(a, A);
			swap_stack(a, A);
			reverse_rotate_stack(a, A);
		}
	}
}

static void	bottom_min_a(t_stack *a, int max)
{
	if (a->size == 3)
	{
		if (a->top->value == max)
			swap_stack(a, A);
		reverse_rotate_stack(a, A);
	}
	else
	{
		if (a->top->value == max)
			swap_stack(a, A);
		rotate_stack(a, A);
		swap_stack(a, A);
		reverse_rotate_stack(a, A);
		swap_stack(a, A);
	}
}

void	handler_three_a(int r, t_stack *a)
{
	int	min;
	int	max;

	min = get_min_value(a->top, r);
	max = get_max_value(a->top, r);
	if (a->top->value == min)
		top_min_a(a, max);
	else if (a->top->next->value == min)
		middle_min_a(a, max);
	else if (a->top->next->next->value == min)
		bottom_min_a(a, max);
}
