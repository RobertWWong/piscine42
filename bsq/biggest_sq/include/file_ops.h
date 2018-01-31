/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ops.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 20:22:23 by rowong            #+#    #+#             */
/*   Updated: 2018/01/29 20:22:40 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_OPS_H
# define FILE_OPS_H
# define STDIN_FILENO 0
# define STDOUT_FILENO 1
# define STDERR_FILENO 2
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int		open_file(char *str);
int		write_to_buffer(int file_desc, char *buffer, size_t buff_size);


#endif
