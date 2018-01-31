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
#include <stdio.h>
int		open_file(char *str)
{
	return(open(str, O_RDONLY));
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
* Function will read from a file_descriptor to a local buffer the content of said file
* This will allow us to read character in a steadily manner. Will change the buffer size
* accordingly as well.
*/
char	*write_to_buffer(int file_desc)
{
	char	*buffer;
	char	*old_buff;
	size_t	nread;
	size_t	cur_size;
	size_t	buffer_size;

	buffer_size = 1;
	cur_size = 0;
	buffer = (char *)malloc(sizeof(char) * (buffer_size + 1));
	while((nread = read(file_desc, buffer + cur_size, buffer_size)) > 0)
	{
		cur_size += nread;
		if (cur_size > buffer_size)
			buffer_size *= 2;
		buffer[cur_size] = '\0';
		old_buff = buffer;
		buffer = (char *)malloc(sizeof(char) * (cur_size + buffer_size + 1));
		ft_strcpy(buffer, old_buff);
		free(old_buff);
	}
	return (buffer);
}

//When will i need to use malloc, realloc, and calloc? figure that out
// char	*ft_realloc()