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
// #include "util_func.c"

char	**init_2d_map(t_map *map_val)
{
	int c;
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * map_val->row);
	c = -1;
	while (++c < map_val->col_ck)
		arr[c] = (char *)malloc(sizeof(char) * map_val->col_ck);
	printf("good to go\n");
	// free(arr);
	return (arr);
}

