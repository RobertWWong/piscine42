
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

// #include "include/util_func.h"
// #include "include/file_ops.h"
#include "util_func.h"
#include "file_ops.h"

#include <stdio.h>

/*
* Fun with arrays, we will be using them to keep track of our legends
*
*
*
*/
int main()
{
	int		legend[4];
	int 	fd;
	char 	buff[1024];

	fd = open ("maps/map1", O_RDONLY);
	write_to_buffer(fd, buff, sizeof(buff) - 1);

	printf("%s\nPerl map gen has newline already. It us our responsibility to check if they follow that conventions for all other maps\n", buff);

	printf("Line legend checking %d\n", check_line_legend(buff, legend) );
	printf("What is my global values? %d\n", legend[0]);

	//time for some bastardization of record keeping.
	for (int i = 0; i < 4; ++i)
	{
		
		printf("%c\n", (char)legend[i]);
	}
	close (fd);
	return 0;
}
