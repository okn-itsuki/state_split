/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 21:06:10 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/26 21:15:22 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_shell.h"
#include <stdio.h>

int	main(int ac, const char **av)
{
	int		i;
	char	**mem;

	i = 0;
	if (ac == 2)
	{
		mem = split_shell(av[1]);
		while (mem[i])
		{
			printf("%d : %s\n", i, mem[i]);
			i++;
		}
	}
	return (EXIT_SUCCESS);
}
