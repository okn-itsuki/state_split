/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_buf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 20:14:31 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/26 20:20:21 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_shell.h"

int	buf_grow(t_buf *b, size_t need)
{
	size_t	ncap;
	char	*newp;
	size_t	i;

	if (b->cap >= need)
		return (0);
	ncap = (b->cap == 0) ? 16 : b->cap * 2;
	while (ncap < need)
		ncap *= 2;
	newp = (char *)malloc(ncap);
	if (!newp)
		return (-1);
	i = 0;
	while (i < b->len)
	{
		newp[i] = b->ptr[i];
		i++;
	}
	free(b->ptr);
	b->ptr = newp;
	b->cap = ncap;
	return (0);
}

int	buf_push(t_buf *b, char c)
{
	if (buf_grow(b, b->len + 1 + 1) < 0)
		return (-1);
	b->ptr[b->len++] = c;
	return (0);
}
