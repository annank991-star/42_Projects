/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unique.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dschwab <dschwab@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 11:49:35 by dschwab           #+#    #+#             */
/*   Updated: 2026/06/13 11:49:54 by dschwab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	is_unique_row(int grid[4][4], int row, int value)
{
	int	col;

	col = 0;
	while (col < 4)
	{
		if (grid[row][col] == value)
			return (0);
		col++;
	}
	return (1);
}

int	is_unique_col(int grid[4][4], int col, int value)
{
	int	row;

	row = 0;
	while (row < 4)
	{
		if (grid[row][col] == value)
			return (0);
		row++;
	}
	return (1);
}
