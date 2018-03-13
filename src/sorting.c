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

inline void			findextremum(t_list *a, int *min, int *max)
{
	t_list		*tmp;

	tmp = a->next;
	*min = tmp->nb;
	*max = tmp->nb;
	while (tmp != a)
	{
		if (tmp->nb > *max)
			*max = tmp->nb;
		if (tmp->nb < *min)
			*min = tmp->nb;
		tmp = tmp->next;
	}
}

inline int			dlstissort(t_list *a, t_list *b, int bool)
{
	t_list *cpa;

	if (b->next != b && !bool)
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

static void		algoa(t_list *a, t_list *b, int nb)
{
	int 		min;
	int 		max;

	findextremum(a, &min, &max);
	if (!dlstissort(a, b, 1) && a->next->nb == min)
	{
		pushb(a, b);
		findextremum(a, &min, &max);
	}
	else if (!dlstissort(a, b, 1))
	{
		findextremum(a, &min, &max);
		if (nb <= 4)
			littlesort(a, b, min, max);
		else
			normalsort(a, b, min ,max);
	}
}

static void		algob(t_list *a, t_list *b)
{
	int min;
	int max;

	findextremum(a, &min, &max);
	if (b->next->nb > a->next->nb)
		rotatea(a, b);
	else if (b->next->nb < a->next->nb &&
		(b->next->nb > a->prev->nb || a->prev->nb == max))
		pusha(b, a);
	else
		rrotatea(a, b);
}

void				sort(t_list *a, t_list *b, int nb)
{
	if (nb > 9 && !dlstissort(a, b, 1))
		firstalgo(a, b);
	else
	{
		while (!dlstissort(a, b, 1))
			algoa(a, b, nb);
		while (b->next != b)
			algob(a, b);
		while (!dlstissort(a, b, 1))
		{
			rrotatea(a, b);
		}
	}
}