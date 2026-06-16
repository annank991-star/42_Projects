/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dschwab <dschwab@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 10:21:00 by dschwab           #+#    #+#             */
/*   Updated: 2026/06/13 11:23:15 by dschwab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	main(int argc, char **argv)
{
	int	views[16];
	int	grid[4][4];

	if (argc != 2)
	{
		print_error();
		return (1);
	}
	init_grid(grid);
	if (!parse_input(argv[1], views))
	{
		print_error();
		return (1);
	}
	if (!solve(grid, views, 0))
	{
		print_error();
		return (1);
	}
	print_grid(grid);
	return (0);
}
