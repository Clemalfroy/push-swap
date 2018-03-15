/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:56:10 by cmalfroy          #+#    #+#             */
/*   Updated: 2018/03/08 11:56:12 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include <dlist.h>

typedef struct s_sort	t_sort;

typedef void	(t_funcsort)(t_list *a, t_list *b);

struct			s_sort
{
	char		*sort;
    t_funcsort	*func;
};

typedef struct  s_stacks
{
    t_list      *lst;

    int         min;
    int         max;

    int         nb;
}               t_stacks;

extern void		initsort(t_sort *sort);

void			sort(t_list *a, t_list *b, int nbina);

extern void		swapa(t_list *a, t_list *b);
extern void		swapb(t_list *a, t_list *b);
extern void		swapab(t_list *a, t_list *b);

extern void		pusha(t_list *a, t_list *b);
extern void		pushb(t_list *a, t_list *b);

extern void		rotatea(t_list *a, t_list *b);
extern void		rrotatea(t_list *a, t_list *b);
extern void		rotateb(t_list *a, t_list *b);
extern void		rrotateb(t_list *a, t_list *b);
extern void		rotateab(t_list *a, t_list *b);
extern void		rrotateab(t_list *a, t_list *b);

extern void     getaction(char *actions, t_stacks *a, t_stacks *b,
                           t_funcsort *sort);

#endif
