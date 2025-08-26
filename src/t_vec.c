/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vec.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 20:14:33 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/26 21:04:42 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_shell.h"

int	vec_grow(t_vec *v, size_t need)
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

int	vec_push(t_vec *v, char *s)
{
	if (vec_grow(v, v->len + 1) < 0)
		return (-1);
	v->v[v->len++] = s;
	v->v[v->len] = NULL;
	return (0);
}