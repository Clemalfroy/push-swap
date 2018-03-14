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

void			findextremum(t_list *a, int *min, int *max)
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

static int		searchmin(t_list *a, int nb, int min)
{
    t_list	*tmp;
    int		i;

    tmp = a->next;
    i = 0;
    while (tmp->nb != min && ++i)
        tmp = tmp->next;
    if (i <= nb / 2)
        return (1);
    return (0);
}

static void			normalsort(t_list *a, t_list *b, int nb, int min)
{
    if (nb < 19 && a->next->nb > a->next->next->nb)
        getactions("sa", a, b, swapa);
    else if (searchmin(a, nb, min))
        getactions("ra", a, b, rotatea);
    else
        getactions("rra", a, b, rrotatea);
}

void			littlesort(t_list *a, t_list *b, int min, int max)
{
    if (a->next->nb == min && a->next->next->nb == max)
        getactions("sa", a, b, swapa);
    else if ((a->next->nb == min || a->next->nb == max) &&
             (a->next->next->nb == max || a->next->next->nb == min))
        getactions("ra", a, b, rotatea);
    else if (a->next->nb == min && a->prev->nb < a->prev->prev->nb)
        getactions("rra", a, b, rrotatea);
    else if (a->next->nb > a->next->next->nb &&
             (a->next->next->nb != min || a->next->nb != max))
        getactions("sa", a, b, swapa);
    else if ((a->next->nb > a->prev->nb && a->next->nb != min))
        getactions("rra", a, b, rrotatea);
    else if ((a->next->nb < a->prev->nb && a->next->nb != max))
        getactions("ra", a, b, rotatea);
    if (!dlstissort(a, b, 1))
        littlesort(a, b, min, max);
}

void	pushtwob(t_list *a, t_list *b)
{
    getactions("pb", a, b, pushb);
    getactions("pb", a, b, pushb);
	if (b->next->nb < b->next->next->nb)
		swapb(a, b);
}

static void		algoa(t_list *a, t_list *b, int *nb)
{
	int 		min;
	int 		max;

	findextremum(a, &min, &max);
	if (!dlstissort(a, b, 1) && a->next->nb == min)
	{
		*nb = *nb - 1;
        getactions("pb", a, b, pushb);
		findextremum(a, &min, &max);
	}
	else if (!dlstissort(a, b, 1))
	{
		findextremum(a, &min, &max);
		if (*nb <= 4)
			littlesort(a, b, min, max);
		else
			normalsort(a, b, *nb, min);
	}
}

static void		algob(t_list *a, t_list *b, int *nb)
{
	int min;
	int max;

	findextremum(a, &min, &max);
	if (b->next->nb > a->next->nb)
        getactions("ra", a, b, rotatea);
	else if (b->next->nb < a->next->nb &&
			 (b->next->nb > a->prev->nb || a->prev->nb == max))
	{
		*nb = *nb + 1;
		getactions("pa", a, b, pusha);
	}
	else
		rrotatea(a, b);
}

void			firstalgo(t_list *a, t_list *b) {
    //int min;
    //int max;
    pushtwob(a, b);
    /*
	while (!dlstissort(a, b, 1))
	{
		findextremum(b, &min, &max);
		ft_ps_calcopti(a, b);
		ft_ps_selectopti(a, b);
	}
	ft_ps_orderb(a, b);
	while (a->prev->rnk > b->next->rnk && a->next->rnk != b->next->rnk + 1
		   && ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("rra\n")))
		ft_ps_reverse(a);
	while (b->next != b)
	{
		while (a->next->rnk == a->prev->rnk + 1
			   && ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("rra\n")))
			ft_ps_reverse(a);
		ft_ps_push(b, a);
		ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("pa\n"));
	}
	while (a->next->rnk != 1
		   && ft_ps_addcmd(&(a->cmds), a, b, ft_strdup("rra\n")))
		ft_ps_reverse(a);
	ft_ps_putcmds(a->cmds);
}*/
}


void			sort(t_list *a, t_list *b, int nb)
{
	if (nb > 9 && !dlstissort(a, b, 1))
		firstalgo(a, b);
	else
	{
		while (!dlstissort(a, b, 1))
			algoa(a, b, &nb);
		while (b->next != b)
			algob(a, b, &nb);
		while (!dlstissort(a, b, 1))
		{
            getactions("rra", a, b, rrotatea);
		}
	}
}