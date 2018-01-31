/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_func.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:44:23 by rowong            #+#    #+#             */
/*   Updated: 2018/01/29 14:44:26 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef UTIL_FUNC_H
# define UTIL_FUNC_H
# include <unistd.h>


void	putstrs(char *str);

int		ft_atoi(char *str);
int		check_map(char *str, int leg[4], int col_check);
int		check_line_legend(char *str, int leg[4]);
int		ft_atoi(char *str);

#endif
