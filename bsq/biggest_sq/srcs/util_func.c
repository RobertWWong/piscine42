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
* Return -1 if amount of character legs is not met
* Return -2 if more characters than necessary are present on the first line
*/

int		check_line_legend(char *str, int leg[4])
{
	int i;

	i = 0;
	leg[0] = ft_atoi(str);
	while (str[i] != '\n' && str[i])
	{
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] == '\n' || str[i + 1] == '\n' || str[i + 2] == '\n')
			return (-1);
		leg[1] = str[i];
		leg[2] = str[i + 1];
		leg[3] = str[i + 2];
		i += 3;
		if (str[i] != '\n')
			return (-2);
	}
	return (1);
}

/*
* Check map util function that will compare map char to their specific legend
* Returns -1 if the amount of column read is not consisent
* Return -2 if there are unexpected characters inside the map.
* Return the amount of rows read on a successful map reading.
*/
int		check_map_util(char *str, int leg[4], int offset, int char_ck)
{
	int row;
	int col;
	int line_ck;
	int col_ck;

	col_ck = 0;
	line_ck = 0;
	row = 0;
	col = 0;
	while ((char_ck = str[row + ++col + offset + 1]) != '\0')
	{	
		if (char_ck == '\n')
		{
			line_ck++;
			row += col + 1;
			if (!col_ck)
				col_ck = col;
			if (col != col_ck || (line_ck == leg[0] && *(str + row + offset) != '\n'))
				return (-1);
			col = - 1;
		}
		else if (!(char_ck == leg[1] || char_ck == leg[2] || char_ck == leg[2]))
				return (-2);
 	}
 	return (line_ck);
}

/*
* This function checks if the lines present in the map have
* the correct characters, matching amounts of columns and rows, or a newline
* at the end of every row.
* It calls a util function that will check each character for matching symbols
* and returns the amount of rows read.
* 
* Return 1 for a valid map
* Return -3 if the amount of rows read are not equal to the legend.
*/
int		check_map(char *str, int leg[4])
{	
	int offset;
	int line_ck;

	offset = 0;
	while (str[offset] != '\n')
		offset++;
	line_ck = check_map_util(str, leg, offset, 0);
	if (line_ck < 0)
		return (line_ck);
	else if (line_ck != leg[0])
		return (-3);
 	return (1);
}
