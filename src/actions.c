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

inline void getactions(char *actions, t_list *a, t_list *b, t_funcsort *sort)
{
    ft_puts(1, actions);
    sort(a, b);
}