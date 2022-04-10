/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:53:45 by chahan            #+#    #+#             */
/*   Updated: 2022/04/10 16:24:40 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exceptional_cases(int r, t_stack *a, t_stack *b)
{
	if (r <= 3)
	{
		handle_under_three(r, a, b, B);
		return (0);
	}
	else if (r == 5)
	{
		hanlde_sort_five(5, a, b, B);
		return (0);
	}
	else
		return (1);
}

static void	push_rotate_b(t_stack *a, t_stack *b, t_value *var)
{
	// 작은 값을 b 밑으로 내리기
	if (b->top->value <= var->piv_small)
	{
		rotate_stack(b, B);
		var->rb++;
	}
	else
	{
		// b의 값을 a로 올리기
		push_stack(b, a, A);
		var->pa++;
		// a에 올린 값 중에서 상대적으로 덜 작은 녀석들은 내리기
		//나중에 올릴거임
		if (a->top->value <= var->piv_big)
		{
			rotate_stack(a, A);
			var->ra++;
		}
	}
}

static void	back_to_orig_ra(t_stack *a, t_stack *b, t_value *var)
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

static void	back_to_orig_rb(t_stack *a, t_stack *b, t_value *var)
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

void		b_to_a(int r, t_stack *a, t_stack *b, int *cnt)
{
	int		r_temp;
	t_value	var;

	(*cnt)++;
	if (!exceptional_cases(r, a, b))
		return ;
	init_value(&var);
	select_pivot(r, b, &var);
	r_temp = r;
	// 큰 값부터 a에 올려놓기
	while (r_temp--)
		push_rotate_b(a, b, &var);
	// a에 올라간 작은 값들이 이상한 것일 수 있기 때문에 b로 돌려주기
	a_to_b(var.pa - var.ra, a, b, cnt);
	// 아래로 내려갔던 값들을 원래 위치로 돌리기
	if (var.ra > var.rb)
		back_to_orig_ra(a, b, &var);
	else
		back_to_orig_rb(a, b, &var);
	a_to_b(var.ra, a, b, cnt);
	b_to_a(var.rb, a, b, cnt);
}
