/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   balanced_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 20:09:56 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/26 20:20:17 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_shell.h"

int	balanced_quotes(const char *s)
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
