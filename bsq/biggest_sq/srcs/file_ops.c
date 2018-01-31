/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 20:20:28 by rowong            #+#    #+#             */
/*   Updated: 2018/01/29 20:20:31 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_ops.h"

int		open_file(char *str)
{
	return(open(str, O_RDONLY));
}

/*
*
*/
int		write_to_buffer(int file_desc, char *buffer, size_t buff_size)
{
	size_t nread;

	while((nread = read(file_desc, buffer, buff_size - 1)) > 0)
	{
		buffer[nread] = '\0';
		write (file_desc, buffer, nread);
	}
	return (1);
}

//When will i need to use malloc, realloc, and calloc? figure that out
int		ft_realloc()