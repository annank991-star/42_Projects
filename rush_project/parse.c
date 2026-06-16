/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dschwab <dschwab@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 10:24:09 by dschwab           #+#    #+#             */
/*   Updated: 2026/06/13 10:24:25 by dschwab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	parse_input(char *str, int *views)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (j >= 16)
			return (0);
		if (str[i] < '1' || str[i] > '4')
			return (0);
		views[j] = str[i] - '0';
		j++;
		i++;
		if (j < 16)
		{
			if (str[i] != ' ')
				return (0);
			i++;
		}
	}
	if (j != 16)
		return (0);
	return (1);
}
