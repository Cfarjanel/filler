/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:10:27 by cfarjane          #+#    #+#             */
/*   Updated: 2018/10/04 18:02:29 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** Défini J1 et J2.
*/

void		players(t_num *number)
{
	char		*line;

	get_next_line(0, &line);
	if (ft_strstr(line, "cfarjane.filler"))
		number->player = ft_atoi(&line[10]);
	if (number->player == 1)
		number->bot = 2;
	else
		number->bot = 1;
}

/*
** Taille map.
*/

void			size_map(t_map *map)
{
	char	*line;

	line = NULL;
	get_next_line(0, &line);
	if (!line)
		exit (1);
	if (ft_strstr(line, "Plateau ") && *line)
	{
		while (!ft_isdigit(*line))
			line++;
		map->size.x = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
		while (!ft_isdigit(*line))
			line++;
		map->size.y = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
	}
	get_next_line(0, &line);
}

/*
** Récupération forme map.
*/
void		get_map(t_map *map)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	line = NULL;
	if (!(map->shape = ft_memalloc(sizeof(char*) * (map->size.x))))
		return ;
	if (!(map->numbers = ft_memalloc(sizeof(int*) * (map->size.x))))
		return ;
	while (i < map->size.x)
	{
		get_next_line(0, &line);
		if (!line)
			exit (1);
		j = 0;
		while ((ft_isdigit(line[j]) || line[j] == ' ') && line[j])
			j++;
		if (!(map->shape[i] = ft_strdup(line + j)))
			return ;
		if (!(map->numbers[i] = ft_memalloc(sizeof(int) * (map->size.y))))
			return ;
		i++;
	}
}

/*
** Taille pièce.
*/
  
void			size_piece(t_piece *piece)
{
	char	*line;

	line = NULL;
	get_next_line(0, &line);
	if (!line)
		exit (1);
	if (ft_strstr(line, "Piece ") && line)
	{
		while (!ft_isdigit(*line) && line)
			line++;
		piece->size.x = ft_atoi(line);
		while (ft_isdigit(*line) && line)
			line++;
		while (!ft_isdigit(*line) && line)
			line++;
		piece->size.y = ft_atoi(line);
		while (ft_isdigit(*line) && line)
			line++;
	}
}

/*
** Récupération forme pièce.
*/

void		get_piece(t_piece *piece)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	if (!(piece->shape = ft_memalloc(sizeof(char*) * (piece->size.x + 1))))
		return ;
	while (i < piece->size.x)
	{
		get_next_line(0, &line);
		if (!line)
			exit (1);
		piece->shape[i] = line;
		i++;
	}
}