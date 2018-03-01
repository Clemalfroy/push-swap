/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:33:29 by cmalfroy          #+#    #+#             */
/*   Updated: 2018/02/26 13:33:32 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int argc, char **argv)
{
	char **la;

	la = ft_malloc(sizeof(char *) * (argc - 1));
	if (argc == 1 || !getlist(argc, argv, la))
		return (ft_retf(NOP, "Error\n"));



	int i = -1;
	while(la[++i])
		ft_putl(1, la[i]);



	return (YEP);
}