/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:53:45 by chahan            #+#    #+#             */
/*   Updated: 2022/04/10 18:46:16 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*make_stack_new(void)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->size = 0;
	new_stack->top = NULL;
	new_stack->bottom = NULL;
	return (new_stack);
}

static t_node	*init_node(void)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

static void	connect_list(t_node **new, t_node **node, t_stack **stack)
{
	if (!*node)
	{
		*node = *new;
		(*stack)->top = *node;
	}
	else
	{
		(*node)->next = *new;
		(*new)->prev = *node;
		*node = (*node)->next;
	}
}

static int	new_node(char *argv, t_node **node, t_stack **stack)
{
	int		i;
	char	**arg;
	t_node	*new;

	arg = ft_split(argv, ' ');
	if (!arg || !*arg)
		return (0);
	i = -1;
	while (arg[++i])
	{
		new = init_node();
		if (!new)
			print_error();
		new->value = ft_atoi(arg[i]);
		connect_list(&new, node, stack);
		(*stack)->size++;
		free(arg[i]);
	}
	free(arg);
	return (1);
}

t_node	*make_stack_param(t_stack **stack, int argc, char **argv)
{
	int		i;
	int		ret;
	t_node	*node;

	i = 0;
	node = NULL;
	while (++i < argc)
	{
		ret = new_node(argv[i], &node, stack);
		if (!ret)
			print_error();
	}
	if (!node->next)
		(*stack)->bottom = node;
	while (node->prev)
		node = node->prev;
	return (node);
}
