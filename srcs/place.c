/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 10:53:26 by cfarjane          #+#    #+#             */
/*   Updated: 2018/11/05 10:53:31 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** Vérifie le nombre d'étoiles en commun.
** Dois faire la somme sur la map d'int en parralèle et ne garder que si
** count == 1 et new < prev.
*/

static int		ft_player(t_map *map, t_coord coord, t_num *num, t_coord c)
{
	if ((map->shape[coord.x + c.x][coord.y + c.y] == 'o' ||
		map->shape[coord.x + c.x][coord.y + c.y] == 'O') && num->player == 1)
		return (1);
	if (((map->shape[coord.x + c.x][coord.y + c.y] == 'x' ||
		map->shape[coord.x + c.x][coord.y + c.y] == 'X') && num->player == 2))
		return (2);
	return (0);
}

static int		ft_count(t_piece *p, t_map *map, t_coord coord, t_num *num)
{
	t_coord	c;
	int		count;

	count = 0;
	c.x = -1;
	while (++c.x < p->size.x)
	{
		c.y = -1;
		while (++c.y < p->size.y)
		{
			if (coord.y + c.y >= map->size.y || coord.x + c.x >= map->size.x ||
					(map->numbers[coord.x + c.x][coord.y + c.y] <= 2 &&
					p->shape[c.x][c.y] == '*'))
				return (0);
			if (ft_player(map, coord, num, c) == 1 && p->shape[c.x][c.y] == '*')
				count++;
			if (ft_player(map, coord, num, c) == 2 && p->shape[c.x][c.y] == '*')
				count++;
		}
	}
	if (count == 1)
		return (1);
	return (0);
}

/*
** Parcours en même temps les map et la pièce depuis les coordonnées valables
** (count == 1) données par place. À chaque avancement tant que piece y && x
** existe, on ajoute à somme le numéro de chaleur de la map->numbers.
** Cette somme est stockée et réutilisée par place pour définir si la position
** de la pièce est la plus adaptée.
*/

static void		ft_somme(t_piece *piece, t_map *map, int x, int y)
{
	int i;
	int j;
	int y2;

	piece->somme = 0;
	i = 0;
	while (i < piece->size.x && x < map->size.x)
	{
		y2 = y;
		j = 0;
		while (j < piece->size.y && y < map->size.y)
		{
			if (piece->shape[i][j] == '*' && map->numbers[x][y2] > 2)
				piece->somme += map->numbers[x][y2];
			j++;
			y2++;
		}
		i++;
		x++;
	}
}

/*
** Parse tous les sens de la map char et cherche count == 1.
** Si count == 1, cherche l'équivalent sur la map int pour récupérer la
** distance correspondante et la stocker si elle est inférieure à la précédente.
*/

int				place(t_piece *piece, t_map *map, t_num *num)
{
	t_coord coord;

	coord.x = -1;
	piece->prev = 0;
	piece->coord.x = 0;
	piece->coord.y = 0;
	while (++coord.x < map->size.x)
	{
		coord.y = -1;
		while (++coord.y < map->size.y)
		{
			if (ft_count(piece, map, coord, num) == 1)
			{
				ft_somme(piece, map, coord.x, coord.y);
				if (piece->somme < piece->prev || piece->prev == 0)
				{
					piece->prev = piece->somme;
					piece->coord.x = coord.x;
					piece->coord.y = coord.y;
				}
			}
		}
	}
	ft_print_coords(piece);
	return (0);
}
