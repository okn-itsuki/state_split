/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_shell_utilty.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 03:28:44 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/26 19:12:24 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_shell.h"

void	free_strv(char **v)
{
	size_t	i;

	if (!v)
		return ;
	i = 0;
	while (v[i])
	{
		free(v[i]);
		i++;
	}
	free(v);
}

int	is_set(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

void	skip_set(const char *s, size_t *i)
{
	while (s[*i] && is_set(s[*i]))
		(*i)++;
}

bool	is_visible(int st_before, char c)
{
	if (c == '\\' && !(st_before & STATE_SQUOTE))
		return (false);
	if (c == '\'' && !(st_before & STATE_DQUOTE))
		return (false);
	if (c == '\"' && !(st_before & STATE_SQUOTE))
		return (false);
	return (true);
}

int	is_delim_top(int st, char c)
{
	if (st != STATE_DEFAULT)
		return (0);
	return (is_set(c));
}
