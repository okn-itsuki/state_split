/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vec.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 20:14:33 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/27 10:16:35 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_shell.h"

int	vec_grow(t_vec *vec, size_t need)
{
	size_t	ncap;
	void	*tmp;

	if (vec->cap >= need)
		return (0);
	if (vec->cap == 0)
		ncap = 4;
	else
		ncap = vec->cap * 2;
	while (ncap < need)
		ncap *= 2;
	tmp = my_realloc(vec->vec, (ncap + 1) * sizeof(*vec->vec));
	if (!tmp)
	{
		error_mes(_ENOMEM);
		return (-1);
	}
	vec->vec = (char **)tmp;
	vec->cap = ncap;
	vec->vec[vec->idx] = NULL;
	return (0);
}

int	vec_push(t_vec *vec, char *s)
{
	if (vec_grow(vec, vec->idx + 1) < 0)
		return (-1);
	vec->vec[vec->idx++] = s;
	vec->vec[vec->idx] = NULL;
	return (0);
}
