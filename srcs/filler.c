/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:05:05 by cfarjane          #+#    #+#             */
/*   Updated: 2018/10/08 17:14:04 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	init(t_map *map, t_piece *piece)
{
	ft_bzero(piece, sizeof(*piece));
	ft_bzero(map, sizeof(*map));
}

void		ft_print_coords(t_piece *piece)
{
	ft_putnbr(piece->coord.x);
	ft_putstr(" ");
	ft_putnbr(piece->coord.y);
	ft_putstr("\n");
}

void		ft_exito(t_piece *piece, t_map *map)
{
	free_double_tab((void**)piece->shape, piece->size.x);
	free_double_tab((void**)map->shape, map->size.x);
	free_double_tab((void**)map->numbers, map->size.x);
	exit(1);
}

/*
** Crée la map de chaleur autour de l'ennemi.
*/

void		diffusion(t_map *map, t_num *num)
{
	right(map, num);
	up(map);
	left(map);
	down(map);
}

int			main(void)
{
	t_piece	piece;
	t_map	map;
	t_num	num;

	ft_bzero(&num, sizeof(num));
	players(&num);
	while (1)
	{
		init(&map, &piece);
		piece.shape = NULL;
		map.numbers = NULL;
		map.shape = NULL;
		size_map(&map, &piece);
		get_map(&map, &piece);
		size_piece(&piece, &map);
		get_piece(&piece, &map);
		diffusion(&map, &num);
		place(&piece, &map, &num);
		free_double_tab((void**)piece.shape, piece.size.x);
		free_double_tab((void**)map.shape, map.size.x);
		free_double_tab((void**)map.numbers, map.size.x);
	}
	return (0);
}
