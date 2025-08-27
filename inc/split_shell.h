/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_shell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 03:26:48 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/27 13:57:46 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_SHELL_H
# define SPLIT_SHELL_H

// library
# include <errno.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

// error messege
# define _EINVAL "Invalid argument"
# define _ENOMEM "Memory allocation failed."

// buf size
# define BUFSIZE 16

// quote
enum		e_states
{
	STATE_DEFAULT = 0b0000,
	STATE_SQUOTE = 0b0001,
	STATE_DQUOTE = 0b0010,
	STATE_ESC = 0b0100
};

typedef struct s_buf
{
	char	*ptr;
	size_t	len;
	size_t	cap;
}			t_buf;

typedef struct s_vec
{
	char	**vec;
	size_t	idx;
	size_t	cap;
}			t_vec;

typedef struct s_block
{
	size_t	size;
}			t_block;

// all_free.c
void		all_free(char **mem);

// balanced_quotes.c
int			balanced_quotes(const char *s);

// is_delim_top.c
int			is_delim_top(int st, char c);

// is_visible.c
int			is_set(char c);
bool		is_visible(int st_before, char c);

// read_token.c
char		*read_token(const char *s, size_t *i);

// skip_set.c
void		skip_set(const char *s, size_t *i);

// split_shell.c
char		**split_shell(const char *s);

// t_buf.c
int			buf_grow(t_buf *b, size_t need);
int			buf_push(t_buf *b, char c);

// t_vec.c
int			vec_grow(t_vec *v, size_t need);
int			vec_push(t_vec *v, char *s);

// update_state.c
int			update_state(int st, char c);

// error_mes.c
void		error_mes(char *mes);

// my_realloc.c
void		my_meta_free(void *ptr);
void		*my_realloc(void *ptr, size_t size);

// my_memcpy.c
void		*my_memcpy(void *dest, const void *src, size_t n);

#endif