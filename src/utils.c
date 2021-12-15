/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwastche </var/mail/cwastche>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:21:46 by cwastche          #+#    #+#             */
/*   Updated: 2021/12/12 16:21:48 by cwastche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	is_sorted(t_list *a, t_list *b)
{
	t_list	*tmp;

	tmp = a;
	if (b)
		return (0);
	while (tmp && tmp->next)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_tree(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 2)
		sa(a);
	else if (ft_lstsize(*a) == 3)
		sort_3(a);
	else if (ft_lstsize(*a) == 4)
		sort_4(a, b);
	else if (ft_lstsize(*a) == 5)
		sort_5(a, b);
	else
		sort_radix(a, b);
}

int	ft_free_all(t_list **a, t_list **b)
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
	return (1);
}
