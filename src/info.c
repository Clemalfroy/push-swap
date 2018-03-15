/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 10:46:52 by cmalfroy          #+#    #+#             */
/*   Updated: 2018/03/15 10:46:55 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

inline void         findextremum(t_list *a, t_stacks *lst)
{
    t_list		*tmp;

    tmp = a->next;
    lst->min = tmp->nb;
    lst->max = tmp->nb;
    while (tmp != a)
    {
        if (tmp->nb > lst->max)
            lst->max = tmp->nb;
        if (tmp->nb < lst->min)
            lst->min = tmp->nb;
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