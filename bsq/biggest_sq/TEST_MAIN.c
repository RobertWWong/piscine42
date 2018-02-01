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
#include <stdio.h>

// void	test_and_stuff(int c, char **argv)
// {
// 	int		fd;
// 	char	*buff;

// 	if (c > 1)
// 		fd = open(argv[1], O_RDONLY);
// 	else
// 		fd = open("maps/map4", O_RDONLY);
// 	buff = write_to_buffer(fd);
// 	printf("Is my file okay == %d\n", fd);
// 	printf("%s\nPerl map gen has newline already. It us our responsibility to check if\
// 	they follow that conventions for all other maps\n", buff);
// 	printf("Line legend checking %d\n", check_line_legend(buff, legend));
// 	printf("What is my global values? %d\n", legend[0]);
// 	close(fd);
// 	(void)c;
// 	(void)argv;
// }

void	create_2d_arr(void)
{
	int		fd;
	char	*buff;
	int		valid_map;
	t_map	*map_val;
	char	**arr;

	arr = NULL;

	fd = open("maps/map4", O_RDONLY);
	buff = write_to_buffer(fd);
	map_val = (t_map *)malloc(sizeof(t_map));
	if (!check_line_legend(buff, map_val) && !close(fd))
		return ;
	printf("Should be a valid map = %d\n", valid_map = check_map(buff, map_val));
	printf("\n\nAmount of rows in this map = %d\nAmount of Columns in this Map = %d\n", map_val->row, map_val->col_ck);
	
	arr = init_2d_map(map_val);
	arr[0][0] = 'a';
	arr[0][1] = 'b';
	arr[0][3] = 'c';
	arr[0][2] = 'd';
	printf("%s\n", arr[0]);
	// arr[0][0] = 'd';
	// arr[0][1] = 'e';
	// arr[0][3] = 'q';
	// arr[0][2] = 't';
	// printf("%s\n", arr[0]);

}

int		main(int argc, char **argv)
{
	// test_and_stuff(c, argv);
	create_2d_arr();
	(void)argc;
	(void)argv;
	return (0);
}
