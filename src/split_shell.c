/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 03:28:41 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/27 13:57:28 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// split_shell.c
#include "split_shell.h"

char	**split_shell(const char *s)
{
	size_t	i;
	t_vec	vec;
	char	*tok;

	if (!s)
		return (NULL);
	if (!balanced_quotes(s))
		return (error_mes(_EINVAL), NULL);
	i = 0;
	vec.vec = NULL;
	vec.idx = 0;
	vec.cap = 0;
	skip_set(s, &i);
	while (s[i])
	{
		tok = read_token(s, &i);
		if (!tok)
			return (all_free(vec.vec), NULL);
		if (vec_push(&vec, tok) < 0)
			return (my_meta_free(tok), all_free(vec.vec), NULL);
		skip_set(s, &i);
	}
	if (!vec.vec && vec_push(&vec, NULL) < 0)
		return (NULL);
	return (vec.vec);
}
