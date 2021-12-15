/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwastche </var/mail/cwastche>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:10:01 by cwastche          #+#    #+#             */
/*   Updated: 2021/12/12 16:10:03 by cwastche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	sort_3(t_list **a)
{
	int	one;
	int	two;
	int	three;

	while (!is_sorted(*a, NULL))
	{
		one = (*a)->index;
		two = (*a)->next->index;
		three = (*a)->next->next->index;
		if (one < two && two > three && one > three)
			rra(a);
		else if (one > three && two < three && one > three)
			ra(a);
		else
			sa(a);
	}
	return ;
}

void	sort_4(t_list **a, t_list **b)
{
	int	i;

	i = find_min(*a);
	if (i == 1)
		ra(a);
	while (i > 1 && i < 4)
	{
		rra(a);
		i++;
	}
	pb(a, b);
	sort_3(a);
	pa(a, b);
	return ;
}

void	sort_5(t_list **a, t_list **b)
{
	int	i;

	i = find_min(*a);
	while (i > 1 && i < 5)
	{
		rra(a);
		i++;
	}
	while (i > 0 && i < 2)
	{
		ra(a);
		i++;
	}
	pb(a, b);
	sort_4(a, b);
	while (*b)
	{
		if ((*a)->index < ((*b)->index))
			ra(a);
		pa(a, b);
	}
	if ((*a)->index > (ft_lstlast(*a)->index) && !(*b))
		rra(a);
	return ;
}

int	find_min(t_list	*a)
{
	t_list	*tmp;
	int		min;
	int		j;
	int		i;

	tmp = a;
	min = a->index;
	j = 0;
	i = 0;
	while (tmp)
	{
		if (min > tmp->index)
		{
			min = tmp->index;
			j = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (j);
}

void	sort_radix(t_list **a, t_list **b)
{
	int	size;
	int	i;
	int	j;
	int	bits;

	size = ft_lstsize(*a);
	i = 0;
	while (!is_sorted(*a, NULL))
	{
		j = 0;
		while (j < size)
		{
			bits = (*a)->index;
			if ((bits >> i) & 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (ft_lstsize(*b))
			pa(a, b);
		i++;
	}
	return ;
}
