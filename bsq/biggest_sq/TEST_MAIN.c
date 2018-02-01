/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:21:00 by rowong            #+#    #+#             */
/*   Updated: 2018/01/31 17:22:45 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/util_func.h"
#include "include/file_ops.h"
#include "include/map_creator.h"
#include "include/ft_bsq.h"

/*
** if (!(valid_map = check_map(buff, map_val)))
** return (valid_map);	
** solve_bsq(map_arr, map_val);
** free_map_arr(map_arr, map_val);
*/

int		lets_play(char *str)
{
	int		fd;
	char	*buff;
	int		valid_map;
	t_map	*map_val;
	char	**map_arr;

	map_arr = NULL;
	fd = open(str, O_RDONLY);
	buff = write_to_buffer(fd);
	close(fd);
	map_val = (t_map *)malloc(sizeof(t_map));
	if (!check_line_legend(buff, map_val))
		return (-1);

	(valid_map = check_map(buff, map_val));
	map_arr = init_2d_map(map_val);
	print_map(map_val, map_arr, -1);
	return (1);
}


int		main(int argc, char **argv)
{
	int	i;
	int error;

	i = 0;
	while (i < argc && argc > 1)
	{
		error = lets_play(argv[i++]);
		putstrs("\n");

	}
	if (argc < 2)
		lets_play("maps/map4");
	return (0);
}
