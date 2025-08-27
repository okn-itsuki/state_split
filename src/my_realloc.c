/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:04:57 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/27 10:19:24 by iokuno           ###   ########.fr       */
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

	if (size == 0)
		return (NULL);
	block = malloc(sizeof(t_block) + size);
	if (!block)
		return (error_mes(_ENOMEM), NULL);
	block->size = size;
	return ((void *)(block + 1));
}

void	*my_realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	size_t	old_size;
	t_block	*old_block;

	if (ptr == NULL)
		return (meta_malloc(size));
	if (size == 0)
	{
		my_meta_free(ptr);
		return (NULL);
	}
	old_block = ((t_block *)ptr) - 1;
	old_size = old_block->size;
	new_ptr = meta_malloc(size);
	if (!new_ptr)
		return (error_mes(_ENOMEM), NULL);
	if (old_size < size)
		my_memcpy(new_ptr, ptr, old_size);
	else
		my_memcpy(new_ptr, ptr, size);
	my_meta_free(ptr);
	return (new_ptr);
}
