/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 20:14:27 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/26 20:18:16 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_shell.h"

char	*read_token(const char *s, size_t *i)
{
	int		st;
	int		show;
	t_buf	b;

	st = STATE_DEFAULT;
	b.ptr = NULL;
	b.len = 0;
	b.cap = 0;
	while (s[*i])
	{
		if (is_delim_top(st, s[*i]))
			break ;
		show = is_visible(st, s[*i]);
		st = update_state(st, s[*i]);
		if (show && buf_push(&b, s[*i]) < 0)
			return (free(b.ptr), NULL);
		(*i)++;
	}
	if (!b.ptr && b.len == 0)
		return (NULL);
	if (buf_push(&b, '\0') < 0)
		return (free(b.ptr), NULL);
	return (b.ptr);
}
