/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:44:59 by cmalfroy          #+#    #+#             */
/*   Updated: 2018/03/01 11:09:19 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdint.h>
# include <sys/types.h>
# include <limits.h>
# include <unistd.h>
# include <libft.h>

# include "dlist.h"
# include "actions.h"
# include "getinfo.h"

# define TRUE 1
# define FALSE 0

typedef struct		s_cmd
{
	char			*cmd;
	struct s_lcmd	*next;
}					t_cmd;

#endif