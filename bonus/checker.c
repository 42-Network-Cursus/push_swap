/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwastche </var/mail/cwastche>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:10:34 by cwastche          #+#    #+#             */
/*   Updated: 2021/12/12 16:18:55 by cwastche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

static int	ft_free_checker(t_list **a, t_list **b, char **cmd)
{	
	t_list	*tmp;

	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
	while (*b)
	{
		tmp = (*b)->next;
		free(*b);
		*b = tmp;
	}
	free(*cmd);
	return (1);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static int	op_tree(char *cmd, t_list **a, t_list **b)
{
	if (!ft_strcmp(cmd, "pa\n"))
		return (ft_push(a, b));
	else if (!ft_strcmp(cmd, "pb\n"))
		return (ft_push(b, a));
	else if (!ft_strcmp(cmd, "rra\n") || !ft_strcmp(cmd, "rrr\n"))
		return (ft_rev_rotate(a));
	else if (!ft_strcmp(cmd, "rrb\n") || !ft_strcmp(cmd, "rrr\n"))
		return (ft_rev_rotate(b));
	else if (!ft_strcmp(cmd, "ra\n") || !ft_strcmp(cmd, "rr\n"))
		return (ft_rotate(a));
	else if (!ft_strcmp(cmd, "rb\n") || !ft_strcmp(cmd, "rr\n"))
		return (ft_rotate(b));
	else if (!ft_strcmp(cmd, "sa\n") || !ft_strcmp(cmd, "ss\n"))
		return (ft_swap(a));
	if (!ft_strcmp(cmd, "sb\n") || !ft_strcmp(cmd, "ss\n"))
		return (ft_swap(b));
	write(2, "Error\n", 6);
	return (-1);
}

static void	ft_result(t_list **a, t_list **b, char **ptr_cmd)
{
	if (is_sorted(*a, *b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_checker(a, b, ptr_cmd);
	return ;
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;
	char	*cmd;

	if (argc < 2)
		return (1);
	if (ft_args_check(argc, argv))
		return (write(2, "Error\n", 6));
	a = malloc(sizeof(t_list));
	b = malloc(sizeof(t_list));
	if (a == NULL || b == NULL)
		return (ft_free_all(a, b));
	*a = NULL;
	*b = NULL;
	if (ft_init_stack(argv, a))
		return (ft_free_all(a, b));
	cmd = get_next_line(0);
	while (cmd)
	{
		if (op_tree(cmd, a, b) == -1)
			return (ft_free_checker(a, b, &cmd));
		free(cmd);
		cmd = get_next_line(0);
	}
	ft_result(a, b, &cmd);
	return (0);
}
