/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:18:13 by cmalfroy          #+#    #+#             */
/*   Updated: 2018/03/01 11:18:17 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

inline static int	strisnb(char *str)
{
	short i;

	i = -1;
	while (str[++i])
		if (i > 10 || ft_isdigit(str[i]))
			return (FALSE);
	return (TRUE);
}

inline int			getlist(int ac, char **av)
{
	int		i;

	i = 0;
	while (++i < ac)
		if (!av[i] || !strisnb(av[i]) || ft_atoi(av[i]) > INT_MAX)
			return (FALSE);
	return (TRUE);
}