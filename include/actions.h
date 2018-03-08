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
# define  ACTIONS_H

# include <dlist.h>

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

#endif