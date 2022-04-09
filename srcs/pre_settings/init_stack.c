/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:53:45 by chahan            #+#    #+#             */
/*   Updated: 2022/04/09 20:54:46 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack			*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->top = NULL;
	stack->bottom = NULL;
	return (stack);
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

static void		connect_list(t_node **temp, t_node **node, t_stack **stack)
{
	if (!*node)
	{
		*node = *temp;
		(*stack)->top = *node;
	}
	else
	{
		(*node)->next = *temp;
		(*temp)->prev = *node;
		*node = (*node)->next;
	}
}

static int		set_node(char *argv, t_node **node, t_stack **stack)
{
	int		i;
	char	**arg;
	t_node	*temp;

	arg = ft_split(argv, ' ');
	if (!arg || !*arg)
		return (0);
	i = -1;
	while (arg[++i])
	{
		temp = init_node();
		if (!temp)
			print_error();
		temp->value = ft_atoi(arg[i]);
		connect_list(&temp, node, stack);
		(*stack)->size++;
		free(arg[i]);
	}
	free(arg);
	return (1);
}

t_node			*make_stack(int argc, char **argv, t_stack **stack)
{
	int		i;
	int		ret;
	t_node	*node;

	i = 0;
	node = NULL;
	while (++i < argc)
	{
		ret = set_node(argv[i], &node, stack);
		if (!ret)
			print_error();
	}
	if (!node->next)
		(*stack)->bottom = node;
	while (node->prev)
		node = node->prev;
	return (node);
}
