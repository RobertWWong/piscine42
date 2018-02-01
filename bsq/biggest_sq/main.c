/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:19:37 by rowong            #+#    #+#             */
/*   Updated: 2018/01/29 17:19:48 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/util_func.h"
#include "include/file_ops.h"
#include "include/map_creator.h"
// #include "util_func.h"
// #include "file_ops.h"
// #include "map_creator.h"
#include <stdio.h>

/*
** Fun with arrays, we will be using them to keep track of our legends
** HEY, THERE'S ONLY ONE MAP PER FILE
*/

// void	parse_arg(char *str )


int		main(int argc, char **argv)
{
	int count;
	int	fd;

	count = 0;
	
	if (argc > 1)
		fd = open(argv[1], O_RDONLY);
	else
		fd = open("maps/map4", O_RDONLY);
	buff = write_to_buffer(fd);
	return (0);
}
