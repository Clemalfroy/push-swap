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

inline static void	bitset(uint32_t *words, int n)
{
	words[n / sizeof(uint32_t) * CHAR_BIT]
		|= (1 << n % sizeof(uint32_t) * CHAR_BIT);
}

inline static int	bitget(uint32_t const *words, int n)
{
	uint32_t bit = words[n / sizeof(uint32_t) * CHAR_BIT] &
		(1 << n % sizeof(uint32_t) * CHAR_BIT);
	return (bit != 0);
}

inline int			getlist(int ac, char **av)
{
	int				i;
	int64_t			nb;
	static uint32_t tab[UINT32_MAX / 64 * 64];
	int 			neg;

	i = 0;
	while (++i < ac)
	{
		neg = 1;
		if ((*av[i] == '+' || *av[i] == '-') && (neg = -1))
			av[i]++;
		if (!av[i] || !ft_stris(av[i], ft_isdigit) || (nb =  ft_atoi(av[i])) > INT_MAX)
			return (FALSE);
		nb = nb * neg;
		if (!bitget(tab, (int)nb))
			bitset(tab, (int)nb);
		else
			return (FALSE);
	}
	return (TRUE);
}