/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getinfo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:56:10 by cmalfroy          #+#    #+#             */
/*   Updated: 2018/03/08 11:56:12 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETINFO_H
# define GETINFO_H

# include <dlist.h>

# define TRUE 1
# define FALSE 0

void			freeall(t_list *a, t_list *b);
extern int		getlist(int ac, char **av, t_list *a);

#endif
