/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 14:17:50 by cfarjane          #+#    #+#             */
/*   Updated: 2018/10/09 14:17:53 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int		bot(t_map *m, t_num *n, int x, int y)
{
	if (((m->shape[x][y] == 'o' || m->shape[x][y] == 'O') && n->bot == 1) ||
	((m->shape[x][y] == 'x' || m->shape[x][y] == 'X') && n->bot == 2))
		return (1);
	return (0);
}

/*
** Parse tous les sens de la map char et cherche count == 1.
** Si count == 1, cherche l'équivalent sur la map int pour récupérer la distance
** correspondante et la stocker si elle est inférieure à la précédente.
*/

void		right(t_map *map, t_num *num)
{
	int x;
	int y;

	x = 0;
	while (x < map->size.x)
	{
		y = 0;
		while (y < map->size.y)
		{
			if (bot(map, num, x, y) == 1)
				map->numbers[x][y] = 1;
			if (map->numbers[x][y] != 0) 
			{
				if (map->numbers[x][y + 1] == 0)
					map->numbers[x][y + 1] = map->numbers[x][y] + 1;
			}
			y++;
		}
		x++;
	}
}

void		up(t_map *map)
{
	int x;
	int y;

	y = map->size.y - 1;
	while (y >= 0)
	{
		x = map->size.x - 1;
		while (x >= 0)
		{
			if (map->numbers[x][y] != 0)
			{
				if (x > 0 && map->numbers[x - 1][y] == 0)
					map->numbers[x - 1][y] = map->numbers[x][y] + 1;
			}
			x--;
		}
		y--;
	}
}

void		left(t_map *map)
{
	int x;
	int y;

	x = map->size.x - 1;
	while (x >= 0)
	{
		y = map->size.y - 1;	
		while (y >= 0)
		{
			if (map->numbers[x][y] != 0)
			{
				if (y > 0 && map->numbers[x][y - 1] == 0)
					map->numbers[x][y - 1] = map->numbers[x][y] + 1;
			}
			y--;
		}
		x--;
	}
}

void		down(t_map *map)
{
	int x;
	int y;

	y = 0;
	while (y < map->size.y)
	{
		x = 0;
		while (x < map->size.x)
		{
			if (map->numbers[x][y] != 0)
			{
				if (x + 1 < map->size.x && map->numbers[x + 1][y] == 0)
					map->numbers[x + 1][y] = map->numbers[x][y] + 1;
			}
			x++;
		}
		y++;
	}
}

void		diffusion(t_map *map, t_num *num)
{
	int x;
	int y;

	x = 0;
	right(map, num);
	up(map);
	left(map);
	down(map);
	// while (x < map->size.x)
	// {
	// 	y = 0;
	// 	while (y < map->size.y)
	// 	{
	// 		ft_putnbr_fd(map->numbers[x][y], 2);
	// 		ft_putstr_fd("  ", 2);
	// 		y++;
	// 	}
	// 	x++;
	// }
}