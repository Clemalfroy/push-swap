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
	while (++i && cpya != a)
	{
		if (cpya->nb < min && (*cpt = i))
			min = cpya->nb;
		cpya = cpya->next;
	}
	return (min);
}

inline static void	findnext(t_list *a, t_list *b, int min)
{
	while (a->next->nb != min)
	{
		ft_putl(1, "ra");
		rotatea(a, b);
	}
	ft_putl(1, "pb");
	pushb(a, b);
}

inline static void	findprev(t_list *a, t_list *b, int min)
{
	while (a->next->nb != min)
	{
		ft_putl(1, "rra");
		rrotatea(a, b);
	}
	ft_putl(1, "pb");
	pushb(a, b);
}

void				sort(t_list *a, t_list *b, int nb)
{
	int		min;
	int 	cpt;
	t_list	*cpyb;

	while (!dlstissort(a, b))
	{
		if (a->next == a)
		{
			cpyb = b->next;
			while (cpyb != b)
			{
				ft_putl(1, "pa");
				pusha(a, b);
				cpyb = cpyb->next;
			}
		}
		else
		{
			min = findmin(a, &cpt);
			if (cpt < nb / 2)
				findnext(a, b, min);
			else
				findprev(a, b, min);
			nb--;
		}
	}
}