/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 18:00:17 by cmalfroy          #+#    #+#             */
/*   Updated: 2018/03/08 18:00:19 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

inline int			dlstissort(t_list *a, t_list *b)
{
	t_list *cpa;

	if (b->next != b)
		return (FALSE);
	cpa = a->next;
	while (cpa->next != a)
	{
		if (cpa->nb > cpa->next->nb)
			return (FALSE);
		cpa = cpa->next;
	}
	return (TRUE);
}

inline static int	findmin(t_list *a, int *cpt)
{
	int i;
	int min;
	t_list *cpya;

	cpya = a->next;
	min = cpya->nb;
	*cpt = 0;
	i = 0;
	while (cpya != a && ++i < 5)
	{
		if (cpya->nb < min && (*cpt = i))
			min = cpya->nb;
		cpya = cpya->next;
	}
	return (min);
}

inline static void	gotomin(t_list *a, t_list *b, int min, int bool)
{
	while (a->next->nb != min)
	{
		!bool ? rrotatea(a, b) : rotatea(a, b);
		!bool ? ft_putl(1, "rra") : ft_putl(1, "ra");
	}
	ft_putl(1, "pb");
	pushb(a, b);
}

void				sort(t_list *a, t_list *b, int nb)
{
	int		min;
	int 	cpt;

	if (nb == 2 && !dlstissort(a, b))
	{
		ft_putl(1, "sa");
		swapa(a, b);
	}
	while (!dlstissort(a, b))
	{
		min = findmin(a, &cpt);
		gotomin(a, b, min, (cpt < (nb-- / 2)));
	}
}