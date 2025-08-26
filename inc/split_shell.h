/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_shell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 03:26:48 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/26 19:12:19 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_SHELL_H
# define SPLIT_SHELL_H

# include <errno.h>
# include <stdbool.h>
# include <stdlib.h>

enum		e_states
{
	STATE_DEFAULT = 0x00,
	STATE_SQUOTE = 0x01,
	STATE_DQUOTE = 0x02,
	STATE_ESC = 0x04
};

typedef struct s_buf
{
	char	*ptr;
	size_t	len;
	size_t	cap;
}			t_buf;

typedef struct s_vec
{
	char	**v;
	size_t	len;
	size_t	cap;
}			t_vec;

void		free_strv(char **v);
int			is_set(char c);
void		skip_set(const char *s, size_t *i);
bool		is_visible(int st_before, char c);
int			is_delim_top(int st, char c);
#endif