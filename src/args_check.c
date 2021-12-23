/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwastche </var/mail/cwastche>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:22:55 by cwastche          #+#    #+#             */
/*   Updated: 2021/12/12 16:22:56 by cwastche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	ft_args_check(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (argv[j])
		j++;
	if (j == 1)
		return (-1);
	while (argv[i] && argc > 1)
	{
		if (!ft_isnum(argv[i]))
			return (1);
		if (ft_minmaxint(argv[i]))
			return (1);
		if (ft_find_dupl(ft_atoi(argv[i]), argv, i))
			return (1);
		i++;
		argc--;
	}
	return (0);
}

int	ft_isnum(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_dupl(int nb, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == nb)
			return (1);
		i++;
	}
	return (0);
}

int	ft_minmaxint(char *arg)
{
	int			i;
	long long	nb;

	i = 0;
	nb = 0;
	if (arg[i] == '-')
		i++;
	while (arg[i])
	{
		nb += (arg[i] - 48);
		if (arg[++i])
			nb *= 10;
	}
	if (arg[0] == '-')
		nb = -nb;
	if (nb > 2147483647 || nb < -2147483648)
		return (1);
	return (0);
}
