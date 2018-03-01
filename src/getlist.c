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

inline int			getlist(int ac, char **a)
{
	int				i;
	int64_t			nb;
	static uint32_t tab[UINT32_MAX / 64 * 64];

	i = 0;
	while (++i < ac)
	{
		if (!a[i] || !ft_stris(a[i] + (*a[i] == '+' || *a[i] == '-' ? 1 : 0),
			ft_isdigit) || (nb = ft_atoi(a[i])) > INT_MAX || nb < INT_MIN)
			return (FALSE);
		if (!bitget(tab, (unsigned int)nb))
			bitset(tab, (unsigned int)nb);
		else
			return (FALSE);
	}
	return (TRUE);
}