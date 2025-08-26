/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 22:30:31 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/27 06:12:40 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_shell.h"

static size_t	ft_str_len(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static void	put_str_error(char *s)
{
	write(STDERR_FILENO, s, ft_str_len(s));
}

void	error_mes(char *mes)
{
	put_str_error(mes);
}
