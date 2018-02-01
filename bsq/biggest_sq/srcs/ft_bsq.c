/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rowong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 20:27:51 by rowong            #+#    #+#             */
/*   Updated: 2018/01/31 20:28:03 by rowong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

/*
** Takes a 2d char array and its respective map info in order to find the 
** biggest possible square according to the info's legend.
** Will also instantiate and free a 2d int matric after atempting to solve it
*/

int		solve_bsq(char **map, t_map *info)
{	
	int	i;
	int col;
	int row;
	int	**sq_val;

	sq_val = (int **)malloc(sizeof(int *) * info->row + ((i = -1) * 0));
	while (++i < info->row)
		sq_val[i] = (int *) malloc(sizeof(int) * info->col_ck);
	col = -1;
	while (++col < info->col_ck)
		sq_val[0][col] = (map[0][col] == info->leg[1] ? 1 : 0);
	row = -1;
	while (++row < info->row)
		sq_val[row][0] = (map[row][0] == info->leg[1] ? 1 : 0);
	dp_sq(map, info, sq_val);
	return (1);
}

/*
** Dynamic programming approach for solving the biggest square within constrains
** Will use an int array to keep track of largest sq sum value
*/

int		dp_sq(char **map, t_map *info, int **sq_val)
{
	int			col;
	int			row;
	t_best_sq 	bsq;

	bsq.row = 0;
	bsq.col = 0;
	bsq.length = 0;
	row = 0;
	while (++row < info->row)
	{
		col = 0;
		while (++col < info->col_ck)
		{
			if (map[row][col] == info->leg[1])
				sq_val[row][col] = 1 + get_min(sq_val, row, col);
			else
				sq_val[row][col] = 0;
		}
	}
	return (find_max(sq_val, info, bsq));
}

/*
** Min function to find the smallest cumulative square sum at a given position
** this will help determine whether a spot is adjacent to an obstacle 
** or has an empty spot
*/

int		get_min(int **sq_val, int row, int col)
{
	int left;
	int top_left;
	int top;

	left = sq_val[row][col - 1];
	top_left = sq_val[row - 1][col - 1];
	top = sq_val[row - 1][col];
	if (left < top_left)
		return ((left < top ? left : top));
	return ((top_left < top ? top_left : top));
}

/*
** Return -1 if no solution can be found at all
** Otherwise, change the array starting at the given bsq->row positions
*/

int		find_max(int **sq_val, t_map *info, t_best_sq bsq)
{
	int row;
	int col;

	bsq.length = sq_val[0][0];
	row = -1;
	while (++row < info->row)
	{
		col = -1;
		while (++col < info->col_ck)
			if (bsq.length < sq_val[row][col])
			{
				bsq.length = sq_val[row][col];
				bsq.row = row;
				bsq.col = col;
			}
	}
	if (!bsq.length)
		return (-1);
	then_fill(sq_val, info, bsq);
	return (1);
}

int		then_fill(int **sq_val, t_map *info, t_best_sq bsq)
{
	int length;
	int row;
	int col;
	int stop_here;

	stop_here = bsq.length + 1;
	row = bsq.row;
	while (--stop_here && (length = bsq.length))
	{
		col = bsq.col;
		while (length)
		{
			sq_val[bsq.row][col] = info->leg[3];
			length--;
		}
		bsq.row--;
	}
	return (1);
}

