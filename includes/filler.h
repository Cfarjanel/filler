/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:49:14 by cfarjane          #+#    #+#             */
/*   Updated: 2018/09/28 14:57:43 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
#include "../libft/includes/libft.h"

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_num
{
	int				player;
	int				bot;
}					t_num;

/*
** info map : taille, start, dernière pièce posée
*/

typedef struct		s_map
{
	t_coord			size;
	char			**shape;
	int				**numbers;
}					t_map;

/*
** info piece : start, coord
** shape = . + *
*/

typedef struct		s_piece
{
	t_coord			size;
	t_coord			coord;
	int				count;
	int				prev;
	int				somme;
	char			**shape;
}					t_piece;

/*
** parsing
*/

void				size_piece(t_piece *piece);
void				get_piece(t_piece *piece);
void				get_map(t_map *map);
void				size_map(t_map *map);
void				players(t_num *number);
int					ft_isplayer(t_map *m, t_num *n, int x, int y);
int					ft_isbot(t_map *m, t_num *n, int x, int y);

/*
** algo
*/

void				right(t_map *map, t_num *num);
void				up(t_map *map);
void				left(t_map *map);
void				down(t_map *map);
void				diffusion(t_map *map, t_num *num);
void				ft_print_coords(t_piece *piece);
int         		place(t_piece *piece, t_map *map, t_num *num);

#endif
