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

inline void getaction(char *actions, t_stacks *a, t_stacks *b, t_funcsort *sort)
{
    //read(STDIN_FILENO, NULL, 4096);
    if (!ft_strcmp(actions, "pa"))
    {
        a->nbr++;
        b->nbr--;
    }
    else if (!ft_strcmp(actions, "pb"))
    {
        a->nbr--;
        b->nbr++;
    }
    ft_putl(1, actions);
    sort(a->lst, b->lst);
}