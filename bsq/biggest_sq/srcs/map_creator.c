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

void	print_map(t_map *map, char **arr, int i)
{
	while (++i < map->row)
		{
			putstrs(arr[i]);
			putstrs("\n");
		}
}

/*
** Creates and returns 2d char array for recording our map values.
*/
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

/*
** Parse from a contiguous string to a 2d char array the values of each str char
** A valid map must be given, else this function returns a -1
** prints the 2d map and return a 1 upon completion
*/

int		parse_to_map(t_map *mv, char **map_arr, char *str)
{
	int row;
	int col;
	int char_v;
	int valid_string;

	valid_string = 0;
	while (str[valid_string])
		valid_string++;
	if (valid_string != (mv->row * (mv->col_ck + 1) + mv->offset + 1))
	{
		return (-1);
	}
	row = 0;
	col = -1;
	while((char_v = str[mv->offset + 1 + row + ++col]))
	{
		if (char_v == '\n' && (row = row + col + 1))
			{
				map_arr[row % mv->row][col] = '\0';
				col = -1;
			}
		else
			map_arr[row % mv->row][col] = char_v;
	}
	print_map(mv, map_arr, -1);
	return (1);
}

/*
** FREE YOUR ARR, FREE YOUR ARR, FREEE YOUR GOD DAMN ARR
*/

void	free_map_arr(char **map_arr, t_map *info)
{
	while (info->row)
		free(map_arr[info->row--]);
	free(map_arr);
}
