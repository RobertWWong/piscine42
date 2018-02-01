/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 20:28:19 by rowong            #+#    #+#             */
/*   Updated: 2018/01/31 20:28:21 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H
# include "util_func.h"

typedef struct	s_best_sq
{
	int row;
	int col;
	int length;
}				t_best_sq;

int				solve_bsq(char **map, t_map *info);
int				dp_sq(char **map, t_map *info, int **sq_val);
int				get_min(int **sq_val, int row, int col);
int				find_max(int **sq_val, t_map *info, t_best_sq bsq);
int				then_fill(int **sq_val, t_map *info, t_best_sq bsq);

#endif
