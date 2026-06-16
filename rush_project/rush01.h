/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dschwab <dschwab@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 10:22:00 by dschwab           #+#    #+#             */
/*   Updated: 2026/06/13 11:55:16 by dschwab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>

void	init_grid(int grid[4][4]);
int		parse_input(char *str, int *views);
int		solve(int grid[4][4], int *views, int pos);
void	print_grid(int grid[4][4]);
void	print_error(void);
int		is_unique_row(int grid[4][4], int row, int value);
int		is_unique_col(int grid[4][4], int col, int value);
int		count_left(int *line);
int		count_right(int *line);
int		check_row(int grid[4][4], int *views, int row);
int		check_col(int grid[4][4], int *views, int col);
int		check_finished(int grid[4][4], int *views);

#endif
