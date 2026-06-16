/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dschwab <dschwab@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 11:48:54 by dschwab           #+#    #+#             */
/*   Updated: 2026/06/13 11:49:06 by dschwab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	solve(int grid[4][4], int *views, int pos)
{
	int	row;
	int	col;
	int	value;

	if (pos == 16)
		return (check_finished(grid, views));
	row = pos / 4;
	col = pos % 4;
	value = 1;
	while (value <= 4)
	{
		if (is_unique_row(grid, row, value)
			&& is_unique_col(grid, col, value))
		{
			grid[row][col] = value;
			if (col != 3 || check_row(grid, views, row))
			{
				if (solve(grid, views, pos + 1))
					return (1);
			}
			grid[row][col] = 0;
		}
		value++;
	}
	return (0);
}
