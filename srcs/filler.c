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

void		ft_print_result(t_piece *piece)
{
	ft_putnbr(piece->coord.x);
	ft_putstr(" ");
	ft_putnbr(piece->coord.y);
	ft_putstr("\n");
}

void			ft_count(t_piece *piece, t_map *map)
{
	int x;
	int y;
	int i;
	int j;

	i = piece->coord.x;
	piece->count = 0;
	x = 0;
	while (x < piece->size.x && i < map->size.x)
	{
		j = piece->coord.y;
		y = 0;
		while (y < piece->size.y && j < map->size.y)
		{
			if ((map->shape[i][j] == 'o' || map->shape[i][j] == 'O') &&
					piece->shape[x][y] == '*')
				piece->count++;
			if ((map->shape[i][j] == 'x' || map->shape[i][j] == 'X') &&
					piece->shape[x][y] == '*')
				piece->count++;
			j++;
			y++;
		}
		i++;
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
	size_map(&map);
	get_map(&map);
	size_piece(&piece);
	get_piece(&piece);
	diffusion(&map, &num);
	return (0);
}
