/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_func.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 14:43:27 by rowong            #+#    #+#             */
/*   Updated: 2018/01/31 14:43:29 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_FUNC_H
# define UTIL_FUNC_H
# include <unistd.h>
# include <stdlib.h>

/*
** Custom struct to keep track of map attributes:
** row total, column iterator, column total,
** offset from reading first line legend,
** legend describing row length,
** empty, obstacle, and fill characters.
*/

typedef struct	s_map
{
	int row;
	int col;
	int col_ck;
	int offset;
	int leg[4];

}				t_map;

void	putstrs(char *str);
int		ft_atoi(char *str);
int		check_map(char *str, t_map *map);
int		check_map_util(char *str, int offset, t_map *map);
int		check_line_legend(char *str, t_map *map);

#endif
