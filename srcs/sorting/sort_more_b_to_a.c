/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_b_to_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:53:45 by chahan            #+#    #+#             */
/*   Updated: 2022/04/10 18:44:36 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	escape(int r, t_stack *a, t_stack *b)
{
	if (r <= 3)
	{
		handle_under_three(r, a, b, B);
		return (0);
	}
	else if (r == 5)
	{
		handler_five_sort(5, a, b, B);
		return (0);
	}
	else
		return (1);
}

static void	push_rotate_b(t_stack *a, t_stack *b, t_value *var)
{
	if (b->top->value <= var->piv_small)
	{
		rotate_stack(b, B);
		var->rb++;
	}
	else
	{
		push_stack(b, a, A);
		var->pa++;
		if (a->top->value <= var->piv_big)
		{
			rotate_stack(a, A);
			var->ra++;
		}
	}
}

static void	back_to_origin_ra(t_stack *a, t_stack *b, t_value *var)
{
	int	rrr;
	int	rem;

	rrr = var->rb;
	rem = var->ra - rrr;
	while (rrr--)
		reverse_rotate_all_stack(a, b, ALL);
	while (rem--)
		reverse_rotate_stack(a, A);
}

static void	back_to_origin_rb(t_stack *a, t_stack *b, t_value *var)
{
	int	rrr;
	int	rem;

	rrr = var->ra;
	rem = var->rb - rrr;
	while (rrr--)
		reverse_rotate_all_stack(a, b, ALL);
	while (rem--)
		reverse_rotate_stack(b, B);
}

void	b_to_a(int r, t_stack *a, t_stack *b, int *cnt)
{
	int		r_tmp;
	t_value	var;

	(*cnt)++;
	if (!escape(r, a, b))
		return ;
	utils_init_value(&var);
	utils_select_pivot(r, b, &var);
	r_tmp = r;
	while (r_tmp--)
		push_rotate_b(a, b, &var);
	a_to_b(var.pa - var.ra, a, b, cnt);
	if (var.ra > var.rb)
		back_to_origin_ra(a, b, &var);
	else
		back_to_origin_rb(a, b, &var);
	a_to_b(var.ra, a, b, cnt);
	b_to_a(var.rb, a, b, cnt);
}
