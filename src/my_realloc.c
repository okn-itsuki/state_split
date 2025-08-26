/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:04:57 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/27 06:21:20 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_shell.h"

void	my_meta_free(void *ptr)
{
	t_block	*block;

	if (!ptr)
		return ;
	block = ((t_block *)ptr) - 1;
	free(block);
}

static void	*meta_malloc(size_t size)
{
	t_block	*block;

	block = malloc(sizeof(t_block) + size);
	block->size = size;
	return ((void *)(block + 1));
}

char	*my_realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	size_t	old_size;
	t_block	*old_block;

	if (ptr == NULL)
		return (meta_malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	old_block = ((t_block *)ptr) - 1;
	old_size = old_block->size;
	new_ptr = meta_malloc(size);
	if (!new_ptr)
		return (NULL);
	if (old_size < size)
		my_memcpy(new_ptr, ptr, old_size);
	else
		my_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}
