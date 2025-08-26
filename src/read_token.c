/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 20:14:27 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/27 00:56:57 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_shell.h"

static int	read_handle_error(t_buf buf)
{
	if (!buf.ptr && buf.len == 0)
		return (-1);
	if (buf_push(&buf, '\0') < 0)
	{
		error_mes(_ENOMEM);
		return (free(buf.ptr), -1);
	}
	return (0);
}

char	*read_token(const char *s, size_t *i)
{
	int		state;
	int		show;
	t_buf	buf;

	state = STATE_DEFAULT;
	buf.ptr = NULL;
	buf.len = 0;
	buf.cap = 0;
	while (s[*i])
	{
		if (is_delim_top(state, s[*i]))
			break ;
		show = is_visible(state, s[*i]);
		state = update_state(state, s[*i]);
		if (show && buf_push(&buf, s[*i]) < 0)
			return (free(buf.ptr), NULL);
		(*i)++;
	}
	if (handle_error(buf) < 0)
		return (NULL);
	return (buf.ptr);
}
