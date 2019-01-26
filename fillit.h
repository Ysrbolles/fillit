/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 18:37:26 by ybolles           #+#    #+#             */
/*   Updated: 2019/01/26 20:57:08 by ybolles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H
# include "libft/libft.h"

typedef struct	s_var
{
	char		*dest;
	char		ch;
	int			k;
	int			l;
	int			i;
}				t_var;

char			**separatetetri(char *str);
char			**checktetri(char **str);
char			**solving(char **str);
char			*allocnumber(int i);
int				place(int **cordx, int **cordy, int count, int j);
int				arrange(int *cord);
int				is_safe(char *dest, int *cordx, int *cordy, int j);
int				c_c(int j, int *cord);
int				ft_remove(char *dest, int *cordx, int *cordy, int j);
int				reset_cord(int *z);
int				reset(int **cordx, int **cordy, int i);
t_var			recur(t_var va, int ***cx, int ***cy);
t_var			put(t_var va, int **cx, int **cy, int j);
t_var			res_rem(t_var va, int ***cx, int ***cy);
t_var			inti(t_var va, int j);

#endif
