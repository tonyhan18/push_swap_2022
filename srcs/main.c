/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:53:45 by chahan            #+#    #+#             */
/*   Updated: 2022/04/10 17:43:40 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*node;

	node = a->top;
	while (node)
	{
		if (node->next)
		{
			if (node->value > node->next->value)
				return (0);
		}
		if (node->next)
			node = node->next;
		else
			break ;
	}
	if (node->value == a->bottom->value)
		return (1);
	else
		return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc > 1)
	{
		a = make_stack_new();
		b = make_stack_new();
		a->top = make_stack_param(&a, argc, argv);
		check_duplicate(a->top);
		if (is_sorted(a))
		{
			free_all(a, b);
			return (0);
		}
		push_swap(a, b);
		free_all(a, b);
	}
	return (0);
}
