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

char	**init_2d_map(t_map *map_val);
void	parse_to_map(t_map *mv, char **map_arr, char *str);

#endif
