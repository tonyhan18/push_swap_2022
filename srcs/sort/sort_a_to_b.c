/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:53:45 by chahan            #+#    #+#             */
/*   Updated: 2022/04/10 16:24:43 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exceptional_cases(int r, t_stack *a, t_stack *b)
{
	if (r <= 3)
	{
		handle_under_three(r, a, b, A);
		return (0);
	}
	else if (r == 5)
	{
		hanlde_sort_five(5, a, b, A);
		return (0);
	}
	else
		return (1);
}

static void	push_rotate_a(t_stack *a, t_stack *b, t_value *var)
{
	// 중간값보다 크다면 아래로 내리기
	if (a->top->value > var->piv_big)
	{
		rotate_stack(a, A);
		var->ra++;
	}
	// 중간값보다 작다면
	else
	{
		// B 스택에 삽입하기
		push_stack(a, b, B);
		var->pb++;
		// B 스택에서도 값이 piv_small보다 크다면 아래로 내리기
		if (b->top->value > var->piv_small)
		{
			rotate_stack(b, B);
			var->rb++;
		}
	}
}

static void	back_to_orig_ra(t_stack *a, t_stack *b, int *cnt, t_value *var)
{
	int	rrr;
	int	rem;

	rrr = var->rb; //1 
	rem = var->ra - rrr; //1
	if ((*cnt) > 0)
	{
		while (rrr--)
			reverse_rotate_all_stack(a, b, ALL);
		while (rem--)
			reverse_rotate_stack(a, A);
	}
	else
	{
		while (rrr--)
			reverse_rotate_stack(b, B);
	}
}

static void	back_to_orig_rb(t_stack *a, t_stack *b, int *cnt, t_value *var)
{
	int	rrr;
	int	rem;

	rrr = var->ra;
	rem = var->rb - rrr;
	if ((*cnt) > 0)
	{
		while (rrr--)
			reverse_rotate_all_stack(a, b, ALL);
		while (rem--)
			reverse_rotate_stack(b, B);
	}
	else
	{
		rrr = var->rb;
		while (rrr--)
			reverse_rotate_stack(b, B);
	}
}

void		a_to_b(int r, t_stack *a, t_stack *b, int *cnt)
{
	int		r_temp;
	t_value	var;

	if (!exceptional_cases(r, a, b))
		return ;
	init_value(&var);
	// 피봇고르기
	select_pivot(r, a, &var);
	r_temp = r;
	while (r_temp--)
		push_rotate_a(a, b, &var);
	// 아래로 내려갔던 값들을 원래 위치로 돌리기
	if (var.ra > var.rb)
		back_to_orig_ra(a, b, cnt, &var);
	else
		back_to_orig_rb(a, b, cnt, &var);
	a_to_b(var.ra, a, b, cnt);
	b_to_a(var.rb, a, b, cnt);
	b_to_a(var.pb - var.rb, a, b, cnt);
}
