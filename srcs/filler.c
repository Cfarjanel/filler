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

static void	init(t_map *map, t_piece *piece, t_num *number)
{
	ft_bzero(piece, sizeof(*piece));
	ft_bzero(map, sizeof(*map));
	ft_bzero(number, sizeof(*number));
}

void		ft_print_coords(t_piece *piece)
{
	ft_putnbr(piece->coord.x);
	ft_putstr(" ");
	ft_putnbr(piece->coord.y);
	ft_putstr("\n");
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

	init(&map, &piece, &num);
	players(&num);
	while (1)
	{
		size_map(&map);
		get_map(&map);
		size_piece(&piece);
		get_piece(&piece);
		diffusion(&map, &num);
		place(&piece, &map, &num);
		free_double_tab((void**)piece.shape, piece.size.x);
		free_double_tab((void**)map.shape, map.size.x);
		free_double_tab((void**)map.numbers, map.size.x);
		// while (1);
	}
	return (0);
}
