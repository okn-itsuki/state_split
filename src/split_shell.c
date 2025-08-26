/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 03:28:41 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/26 19:12:26 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// split_shell.c
#include "split_shell.h"

static int	update_state(int st, char c)
{
	if (st & STATE_ESC)
		return (st & ~STATE_ESC);
	if (c == '\\' && !(st & STATE_SQUOTE))
		return (st | STATE_ESC);
	if (c == '\'' && !(st & STATE_DQUOTE))
		return (st ^ STATE_SQUOTE);
	if (c == '\"' && !(st & STATE_SQUOTE))
		return (st ^ STATE_DQUOTE);
	return (st);
}

static int	buf_grow(t_buf *b, size_t need)
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

static int	buf_push(t_buf *b, char c)
{
	if (buf_grow(b, b->len + 1 + 1) < 0)
		return (-1);
	b->ptr[b->len++] = c;
	return (0);
}

static int	vec_grow(t_vec *v, size_t need)
{
	size_t	ncap;
	char	**newv;
	size_t	i;

	if (v->cap >= need)
		return (0);
	ncap = (v->cap == 0) ? 4 : v->cap * 2;
	while (ncap < need)
		ncap *= 2;
	newv = (char **)malloc(sizeof(char *) * (ncap + 1));
	if (!newv)
		return (-1);
	i = 0;
	while (i < v->len)
	{
		newv[i] = v->v[i];
		i++;
	}
	free(v->v);
	v->v = newv;
	v->cap = ncap;
	v->v[v->len] = NULL;
	return (0);
}

static int	vec_push(t_vec *v, char *s)
{
	if (vec_grow(v, v->len + 1) < 0)
		return (-1);
	v->v[v->len++] = s;
	v->v[v->len] = NULL;
	return (0);
}

static int	balanced_quotes(const char *s)
{
	size_t	i;
	int		st;

	i = 0;
	st = STATE_DEFAULT;
	while (s[i])
	{
		st = update_state(st, s[i]);
		i++;
	}
	return ((st & (STATE_SQUOTE | STATE_DQUOTE | STATE_ESC)) == 0);
}

static char	*read_token(const char *s, size_t *i)
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

char	**split_shell(const char *s)
{
	size_t	i;
	t_vec	vec;
	char	*tok;

	if (!s)
		return (NULL);
	if (!balanced_quotes(s))
		return (errno = EINVAL, NULL);
	i = 0;
	vec.v = NULL;
	vec.len = 0;
	vec.cap = 0;
	skip_set(s, &i);
	while (s[i])
	{
		tok = read_token(s, &i);
		if (!tok)
			return (free_strv(vec.v), NULL);
		if (vec_push(&vec, tok) < 0)
			return (free(tok), free_strv(vec.v), NULL);
		skip_set(s, &i);
	}
	if (!vec.v && vec_push(&vec, NULL) < 0)
		return (NULL);
	return (vec.v);
}

#include <stdio.h>

int	main(int ac, const char **av)
{
	int i = 0;
	char **mem;

	mem = split_shell(av[1]);

	if (ac == 2)
	{
		while (mem[i])
		{
			printf("%d : %s\n", i, mem[i]);
			i++;
		}
	}
	return (0);
}