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
* This is a util function return 1 if the lines present in the map have
* the correct characters, matching amounts of columns and rows, a newline
* at the end of every row, or if the map is a column or row vector.
* It will also create a 2d matrix to be return later
*/
int		check_map(char *str, int leg[4], int col_ck)
{	
	int row;
	int col;
	int offset;
	int line_ck;
	int char_ck;
	printf("%s\n", str);

	line_ck = 0;
	row = 0;
	col = -1;
	offset = 0;
	while (str[offset] != '\n')
		offset++;
	while ((char_ck = str[row + ++col + offset + 1]) != '\0')
	{	
		printf("Char = %c 	Near perfection = %d\n", char_ck , col);
		if (char_ck == '\n')
		{
			line_ck++;
			row += col + 1;
			if (!col_ck)
				col_ck = col;
			if (col != col_ck)
				return (-1);
			// printf("row char = %d\n", row);
			col = - 1;
		}
		else if (!(char_ck == leg[1] || char_ck == leg[2] || char_ck == leg[2]))
			{
				printf("Char = %c 	resulting col = %d\n", char_ck , col);
				return (-3);
			}
		// if (row >1550)
		// 	printf("Column = %d\n", col);

 	}
 	printf("Line cking = %d\n", line_ck);
 	printf("legs says = %d\n", leg[0]);
 	printf("Amount of characters counted = %d\n", row);
	if (line_ck != leg[0])
		return (-2);
 	return (1);
}
