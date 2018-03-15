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

static int		searchmin(t_list *a, t_stacks *lst)
{
    t_list	*tmp;
    int		i;

    tmp = a->next;
    i = 0;
    while (tmp->nb != lst->min && ++i)
        tmp = tmp->next;
    if (i <= lst->nb / 2)
        return (1);
    return (0);
}

static void			normalsort(t_stacks *a, t_stacks *b)
{
    if (a->nb < 19 && a->lst->next->nb > a->lst->next->next->nb)
        getaction("sa", a, b, swapa);
    else if (searchmin(a->lst, a))
        getaction("ra", a, b, rotatea);
    else
        getaction("rra", a, b, rrotatea);
}

void			littlesort(t_stacks *a, t_stacks *b)
{
    if (a->lst->next->nb == a->min && a->lst->next->next->nb == a->max)
        getaction("sa", a, b, swapa);
    else if ((a->lst->next->nb == a->min || a->lst->next->nb == a->max) &&
             (a->lst->next->next->nb == a->max || a->lst->next->next->nb == a->min))
        getaction("ra", a, b, rotatea);
    else if (a->lst->next->nb == a->min && a->lst->prev->nb < a->lst->prev->prev->nb)
        getaction("rra", a, b, rrotatea);
    else if (a->lst->next->nb > a->lst->next->next->nb &&
             (a->lst->next->next->nb != a->min || a->lst->next->nb != a->max))
        getaction("sa", a, b, swapa);
    else if ((a->lst->next->nb > a->lst->prev->nb && a->lst->next->nb != a->min))
        getaction("rra", a, b, rrotatea);
    else if ((a->lst->next->nb < a->lst->prev->nb && a->lst->next->nb != a->max))
        getaction("ra", a, b, rotatea);
    if (!dlstissort(a->lst, b->lst, 1))
        littlesort(a, b);
}

void	pushtwob(t_stacks *a, t_stacks *b)
{
    getaction("pb", a, b, pushb);
    getaction("pb", a, b, pushb);
	if (b->lst->next->nb < b->lst->next->next->nb)
        getaction("sb", a, b, swapb);
}

static void		algoa(t_stacks *a, t_stacks *b)
{
	if (!dlstissort(a->lst, b->lst, 1) && a->lst->next->nb == a->min)
	{
        getaction("pb", a, b, pushb);
	}
	else if (!dlstissort(a->lst, b->lst, 1))
	{
		if (a->nb <= 4)
			littlesort(a, b);
		else
			normalsort(a, b);
	}
}

static void		algob(t_stacks *a, t_stacks *b)
{
	if (b->lst->next->nb > a->lst->next->nb)
        getaction("ra", a, b, rotatea);
	else if (b->lst->next->nb < a->lst->next->nb &&
			 (b->lst->next->nb > a->lst->prev->nb || a->lst->prev->nb == a->max))
	{
		getaction("pa", a, b, pusha);
	}
	else
        getaction("rra", a, b, rrotatea);
}

void			firstalgo(t_stacks *a, t_stacks *b) {

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
    t_stacks lsta;
    t_stacks lstb;

    ft_memset(&lsta, 0, sizeof(t_stacks));
    ft_memset(&lstb, 0, sizeof(t_stacks));
    lsta.lst = a;
    lstb.lst = b;
    lsta.nb = nb;
    findextremum(lstb.lst, &lstb);
    findextremum(lsta.lst, &lsta);
	if (nb > 9 && !dlstissort(lsta.lst, lstb.lst, 1))
		firstalgo(&lsta, &lstb);
	else
	{
		while (!dlstissort(a, b, 1))
			algoa(&lsta, &lstb);
		while (b->next != b)
            algob(&lsta, &lstb);
		while (!dlstissort(a, b, 1))
            getaction("rra", &lsta, &lstb, rrotatea);
	}
}