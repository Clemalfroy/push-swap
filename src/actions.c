/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:16:48 by cmalfroy          #+#    #+#             */
/*   Updated: 2018/03/13 17:16:51 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "getinfo.h"

inline void getaction(char *actions, t_stacks *a, t_stacks *b, t_funcsort *sort)
{
    if (ft_strcmp(actions, "pa"))
    {
        findextremum(a->lst, a);
        findextremum(b->lst, b);
        a->nb++;
        b->nb--;
    }
    else if (ft_strcmp(actions, "pb"))
    {
        findextremum(a->lst, a);
        findextremum(b->lst, b);
        a->nb--;
        b->nb++;
    }
    ft_putl(1, actions);
    sort(a->lst, b->lst);
}