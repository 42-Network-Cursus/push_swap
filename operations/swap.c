/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwastche </var/mail/cwastche>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:20:34 by cwastche          #+#    #+#             */
/*   Updated: 2021/12/12 16:20:36 by cwastche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	ft_swap(t_list **stack)
{
	int	tmp_value;
	int	tmp_index;

	if (ft_lstsize(*stack) < 2)
		return (1);
	tmp_value = (*stack)->value;
	tmp_index = (*stack)->index;
	(*stack)->value = (*stack)->next->value;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->value = tmp_value;
	(*stack)->next->index = tmp_index;
	return (0);
}

int	sa(t_list **a)
{
	if (ft_swap(a))
		return (1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_list **b)
{
	if (ft_swap(b))
		return (1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_list **a, t_list **b)
{
	if ((ft_lstsize(*a) < 2) || (ft_lstsize(*b) < 2))
		return (1);
	ft_swap(a);
	ft_swap(b);
	ft_putendl_fd("ss", 1);
	return (0);
}
