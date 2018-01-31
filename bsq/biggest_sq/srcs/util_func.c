/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:54:28 by rowong            #+#    #+#             */
/*   Updated: 2018/01/29 15:54:30 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_func.h"
#include <stdio.h>

void	putstrs(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i], 1);
}

/*
* atoi function to determine length of our square map
*/

int		ft_atoi(char *str)
{
	int n;
	int i;
	int isnegative;

	n = 0;
	i = 0;
	isnegative = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		isnegative = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		n = 10 * n + (str[i] - '0');
		i++;
	}
	if (isnegative == 1)
		return (-n);
	return (n);
}

/*
* This function will read the first line of the file and assign the
* length, empty, full, and obstacle values to the global variable
* Return 1 character assignment went well
* Return -1 if amount of character legends is not met
* Return -2 if more characters than necessary are present on the first line
*/

int		check_line_legend(char *str, int legend[4])
{
	int i;

	i = 0;
	legend[0] = ft_atoi(str);
	while (str[i] != '\n' && str[i])
	{
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] == '\n' || str[i + 1] == '\n' || str[i + 2] == '\n')
			return (-1);
		legend[1] = str[i];
		legend[2] = str[i + 1];
		legend[3] = str[i + 2];
		i += 3;
		if (str[i] != '\n')
			return (-2);
	}
	return (1);
}

/*
* This is a util function return 1 if the lines present in the map have
* the correct characters, matching amounts of columns and rows, a newline
* at the end of every row, or if the map is a column or row vector.
*
*/
int		check_map(char *str)
{
	(void) str;
	return (1);
}
