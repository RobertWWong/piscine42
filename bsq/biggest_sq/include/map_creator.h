/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 14:47:27 by rowong            #+#    #+#             */
/*   Updated: 2018/01/31 14:47:29 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CREATOR_H
# define MAP_CREATOR_H
# include "util_func.h"
# include <stdio.h>

void	print_map(t_map *map, char **arr, int i);
char	**init_2d_map(t_map *map_val);
int		parse_to_map(t_map *mv, char **map_arr, char *str);
void	free_map_arr(char **map_arr, t_map *info);

#endif
