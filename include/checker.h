/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:44:59 by cmalfroy          #+#    #+#             */
/*   Updated: 2018/03/01 11:09:19 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define  CHECKER_H

# include <stdint.h>
# include <sys/types.h>
# include <limits.h>
# include <unistd.h>
# include <libft.h>

# define TRUE 1
# define FALSE 0

typedef struct s_list_a t_list_a;

struct	s_list_a
{
	int 		nb;
	t_list_a 	*next;
};

extern int getlist(int ac, char **a, char **la);

#endif
