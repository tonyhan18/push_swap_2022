/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:53:45 by chahan            #+#    #+#             */
/*   Updated: 2022/04/10 18:40:08 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	utils_init_value(t_value *value)
{
	value->pa = 0;
	value->pb = 0;
	value->ra = 0;
	value->rb = 0;
}

void	utils_select_pivot(int r, t_stack *stack, t_value *var)
{
	long	min;
	long	max;

	min = get_min_value(stack->top, r);
	max = get_max_value(stack->top, r);
	var->piv_big = (min + max) / 2;
	var->piv_small = (min + var->piv_big) / 2;
}

void	push_swap(t_stack *a, t_stack *b)
{
	int	cnt;

	cnt = 0;
	if (a->size == 5)
		handler_five(a, b);
	else
		a_to_b(a->size, a, b, &cnt);
}
