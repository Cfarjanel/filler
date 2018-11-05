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
	int x;
	int y;

	x = 0;
	right(map, num);
	up(map);
	left(map);
	down(map);
	while (x < map->size.x)
	{
		y = 0;
		while (y < map->size.y)
		{
			ft_putnbr_fd(map->numbers[x][y], 2);
			ft_putstr_fd("  ", 2);
			y++;
		}
		ft_putstr_fd("\n", 2);
		x++;
	}
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
		// if (place(&piece, &map, &num) == 1)
		// {
		place(&piece, &map, &num);
		ft_putendl_fd("test 6", 2);
		// ft_printf("%d %d\n", piece.coord.x, piece.coord.y);
			ft_print_coords(&piece);
			// break ;
		// }
	}
	return (0);
}
