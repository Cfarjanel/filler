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

static int			ft_count(t_piece *piece, t_map *map, int i, int j, t_num *num)
{
	int x;
	int y;
    int count;

	count = 0;
	x = 0;
    while (x < piece->size.x)
    {
        y = 0;
   		while (y < piece->size.y)
   		{
            if(j + y >= map->size.y || i + x >= map->size.x || (map->numbers[i + x][j + y] <= 2 && piece->shape[x][y] == '*') ) 
                return (0);    
   			if (((map->shape[i + x][j + y] == 'o' || map->shape[i + x][j + y] == 'O') &&
                    num->player == 1) && piece->shape[x][y] == '*') 
 			    count++;
   			if (((map->shape[i + x][j + y] == 'x' || map->shape[i + x][j + y] == 'X') &&
                    num->player == 2) && piece->shape[x][y] == '*')
   				count++;
   		    y++;
   		}
        x++;
    }
    if (count == 1)
        return (1);
    return (0);
}

/*
** Parcours en même temps les map et la pièce depuis les coordonnées valables (count == 1)
** données par place. À chaque avancement tant que piece y && x existe, on ajoute à somme
** le numéro de chaleur de la map->numbers.
** Cette somme est stockée et réutilisée par place pour définir si la position de la pièce est la plus adaptée.
*/

static void        ft_somme(t_piece *piece, t_map *map, int x, int y)
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
** Si count == 1, cherche l'équivalent sur la map int pour récupérer la distance
** correspondante et la stocker si elle est inférieure à la précédente.
*/

int         place(t_piece *piece, t_map *map, t_num *num)
{
    int x;
    int y;

    x = 0;
    piece->prev = 0;
    piece->coord.x = 0;
    piece->coord.y = 0;
    while (x < map->size.x)
    {
        y = 0;
        while (y < map->size.y)
        {
            if (ft_count(piece, map, x, y, num) == 1)
            {
                ft_somme(piece, map, x, y);
                if (piece->somme < piece->prev || piece->prev == 0)
                {
                    piece->prev = piece->somme;
                    piece->coord.x = x;
                    piece->coord.y = y;
                }
            }
            y++;
        }
        x++;
    }
    ft_print_coords(piece);
    return (0);
}