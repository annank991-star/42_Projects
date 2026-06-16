/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dschwab <dschwab@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 11:51:14 by dschwab           #+#    #+#             */
/*   Updated: 2026/06/13 11:51:39 by dschwab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_row(int grid[4][4], int *views, int row)
{
	int	line[4];
	int	col;

	col = 0;
	while (col < 4)
	{
		line[col] = grid[row][col];
		col++;
	}
	if (count_left(line) != views[8 + row])
		return (0);
	if (count_right(line) != views[12 + row])
		return (0);
	return (1);
}

int	check_col(int grid[4][4], int *views, int col)
{
	int	line[4];
	int	row;

	row = 0;
	while (row < 4)
	{
		line[row] = grid[row][col];
		row++;
	}
	if (count_left(line) != views[col])
		return (0);
	if (count_right(line) != views[4 + col])
		return (0);
	return (1);
}

int	check_finished(int grid[4][4], int *views)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_col(grid, views, i))
			return (0);
		i++;
	}
	return (1);
}
