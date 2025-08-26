/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_buf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 20:14:31 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/27 06:13:02 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_shell.h"

int	buf_grow(t_buf *buf, size_t need)
{
	size_t	ncap;
	char	*newp;

	if (buf->cap >= need)
		return (0);
	if (buf->cap == 0)
		ncap = 16;
	else
		ncap = buf->cap * 2;
	while (ncap < need)
		ncap *= 2;
	newp = my_realloc(buf->ptr, ncap);
	if (!newp)
		return (error_mes(_ENOMEM), -1);
	buf->ptr = newp;
	buf->cap = ncap;
	return (0);
}

int	buf_push(t_buf *buf, char c)
{
	if (buf_grow(buf, buf->len + 1 + 1) < 0)
		return (-1);
	buf->ptr[buf->len++] = c;
	return (0);
}
