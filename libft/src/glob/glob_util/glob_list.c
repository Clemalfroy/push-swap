/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 09:57:56 by mc                #+#    #+#             */
/*   Updated: 2018/02/25 22:49:30 by mc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_util.h"

t_match		*matchctor(char const *path, size_t len, int escape)
{
	t_match *new;

	if (!(new = malloc(sizeof(t_match) + len)))
		return ((NULL));
	ft_bzero(new, sizeof(t_match) + len);
	if (escape)
		sprglbcp((char *)new->buf, path);
	else
		ft_memcpy(new->buf, path, len);
	return (new);
}

void		matchdtor(t_match *match)
{
	t_match *prev;

	if (!match)
		return ;
	prev = match;
	match = match->next;
	free(prev);
	while (match)
	{
		prev = match;
		match = match->next;
		free(prev);
	}
}

void		add_match_to_list(t_match *match, t_match **match_list)
{
	match->next = *match_list;
	*match_list = match;
}

int			matchctoradd(char const *path, int escape, t_match **match_list)
{
	t_match		*match;

	match = matchctor(path, ft_strlen(path), escape);
	if (!match)
		return (GLOBUX_NOSPACE);
	add_match_to_list(match, match_list);
	return (GLOBUX_SUCCESS);
}

size_t		list_len(t_match *match_list)
{
	size_t	ret;

	ret = 0;
	while (match_list)
	{
		ret++;
		match_list = match_list->next;
	}
	return (ret);
}
