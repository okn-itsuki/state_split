/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   balanced_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 20:09:56 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/27 06:12:37 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_shell.h"

int	balanced_quotes(const char *s)
{
	size_t	i;
	int		state;

	i = 0;
	state = STATE_DEFAULT;
	while (s[i])
	{
		state = update_state(state, s[i]);
		i++;
	}
	return ((state & (STATE_SQUOTE | STATE_DQUOTE | STATE_ESC)) == 0);
}
