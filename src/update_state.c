/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 20:12:42 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/27 10:21:58 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_shell.h"

int	update_state(int state, char c)
{
	if (state & STATE_ESC)
		return (state & ~STATE_ESC);
	if (c == '\\' && !(state & STATE_SQUOTE))
		return (state | STATE_ESC);
	if (c == '\'' && !(state & STATE_DQUOTE))
		return (state ^ STATE_SQUOTE);
	if (c == '\"' && !(state & STATE_SQUOTE))
		return (state ^ STATE_DQUOTE);
	return (state);
}
