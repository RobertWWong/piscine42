/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 14:48:15 by rowong            #+#    #+#             */
/*   Updated: 2018/01/31 14:48:15 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_creator.h"
#include <stdio.h>

char	**init_2d_map(t_map *map_val)
{
	int 	c;
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * map_val->row);
	c = -1;
	while (++c < map_val->col_ck)
		arr[c] = (char *)malloc(sizeof(char) * map_val->col_ck);
	return (arr);
}

void	parse_to_map(t_map *mv, char **map_arr, char *str)
{
	int row;
	int col;
	int char_v;

	row = 0;
	col = -1;
	while((char_v = str[mv->offset + 1 + row + ++col]))
	{
		if (char_v == '\n' && (row = row + col + 1))
			col = -1;
		else
			map_arr[row % mv->row][col] = char_v;
	}
	row = -1;
	while (++row < mv->row)
	{
		putstrs(map_arr[row]);	
		putstrs("\n");
	}
}

