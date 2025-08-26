/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 20:12:42 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/26 20:13:02 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_shell.h"

int	update_state(int st, char c)
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
