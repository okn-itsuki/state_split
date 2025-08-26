/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_visible.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 20:14:23 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/26 20:21:33 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_shell.h"

int	is_set(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
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
