/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 20:08:49 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/27 06:12:32 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_shell.h"

void	all_free(char **mem)
{
	size_t	i;

	if (!mem)
		return ;
	i = 0;
	while (mem[i])
	{
		my_meta_free(mem[i]);
		i++;
	}
	free(mem);
}
