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
	if (!line)
		return ;
	if (ft_strstr(line, "cfarjane.filler"))
		number->player = ft_atoi(&line[10]);
	if (number->player == 1)
		number->bot = 2;
	else
		number->bot = 1;
	free(line);
}

/*
** Taille map.
*/

void			size_map(t_map *map)
{
	char	*line;
	int i;

	i = 0;
	line = NULL;
	while (!line || !*line)
	{
		get_next_line(0, &line);
		dprintf(2, "1 %s\n", line);
	}
	if (!line)
		exit (1);
	if (ft_strstr(line, "Plateau "))
	{
		while (!ft_isdigit(line[i]) && line[i])
			i++;
		map->size.x = ft_atoi(line + i);
		while (ft_isdigit(line[i]))
			i++;
		while (!ft_isdigit(line[i]) && line[i])
			i++;
		map->size.y = ft_atoi(line + i);
		while (ft_isdigit(line[i]))
			i++;
	}
	ft_strdel(&line);
	get_next_line(0, &line);
		dprintf(2, "2 %s\n", line);
	free(line);
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
	if (!(map->shape))
	if (!(map->shape = ft_memalloc(sizeof(char*) * (map->size.x))))
		return ;
	if (!(map->numbers))
	if (!(map->numbers = ft_memalloc(sizeof(int*) * (map->size.x))))
		return ;
	while (i < map->size.x)
	{
		get_next_line(0, &line);
		// dprintf(2, "+ %s\n", line);
		dprintf(2, "* %s\n", line);

		if (!line)
			ft_putendl("exit (1);");
		j = 0;
		while ((ft_isdigit(line[j]) || line[j] == ' ') && line[j])
			j++;
		if (!(map->shape[i] = ft_strdup(line + j)))
			return ;
		if (!(map->numbers[i] = ft_memalloc(sizeof(int) * (map->size.y))))
			exit(1) ;
		// dprintf(2, "- %s - %d\n", map->shape[i], map->size.y);
		i++;
		ft_strdel(&line);
	}
}

/*
** Taille pièce.
*/
  
void			size_piece(t_piece *piece)
{
	char	*line;
	int i;

	i = 0;
	line = NULL;
	get_next_line(0, &line);
		dprintf(2, "s %s\n", line);
	if (!line)
		exit (1);
	if (ft_strstr(line, "Piece "))
	{
		while (!ft_isdigit(line[i]) && &(line[i]))
			i++;
		piece->size.x = ft_atoi(&(line[i]));
		while (ft_isdigit(line[i]) && &(line[i]))
			i++;
		while (!ft_isdigit(line[i]) && &(line[i]))
			i++;
		piece->size.y = ft_atoi(&(line[i]));
		while (ft_isdigit(line[i]) && &(line[i]))
			i++;
	}
	free(line);
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
		dprintf(2, "g %s\n", line);

		if (!line)
			exit (1);
		piece->shape[i] = line;
		// dprintf(2, "{ %s\n", piece->shape[i]);
		i++;
		line = NULL;
	}
	// free(line);
}
