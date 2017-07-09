/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddevico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 10:01:03 by ddevico           #+#    #+#             */
/*   Updated: 2016/01/19 11:58:21 by ddevico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					g_ant_count;
int					g_id;
int					g_case_count;
int					g_max_pass;
int					g_id_start;
int					g_id_end;
t_room				*g_room_list;

static void			test_arg(void)
{
	if (g_ant_count <= -1)
		ft_error("Error");
}

static void			parse(int fd)
{
	char			*line;

	while ((get_next_line(fd, &line) > 0) && ft_strlen(line) > 0)
	{
		if (line[0] == '#' && line[1] == '#')
			hashtag(line);
		else if (line[0] == '#')
			ft_printf("%s\n", line);
		else if (countstr(line, ' ') == 2)
			room(line);
		else if (countstr(line, ' ') == 0 && ft_strchr(line, '-'))
			way(line);
		else if (countstr(line, ' ') == 0 && ft_strisnum(line))
		{
			if (g_ant_count == -1)
				g_ant_count = ft_atoi(line);
			else
				ft_error("Error");
			ft_printf("%d\n", g_ant_count);
		}
		ft_strdel(&line);
	}
}

static t_parcouru	*init_struct_parcours(t_room *room)
{
	int				i;
	int				j;
	t_room			*tmp;
	t_parcouru		*parcouru;

	i = 0;
	parcouru = (t_parcouru*)malloc((g_case_count - 1) * sizeof(t_parcouru));
	while (i != g_case_count - 1)
	{
		j = 0;
		tmp = room;
		room = next_voisin(room)->room;
		parcouru[i].name = room->name;
		parcouru[i].ant = (int*)malloc((g_ant_count) * sizeof(int));
		while (j != g_ant_count)
		{
			parcouru[i].ant[j] = 0;
			j++;
		}
		i++;
	}
	return (parcouru);
}

int					main(int argc, char **argv)
{
	int				fd;
	t_room			*start;
	t_room			*end;
	t_parcouru		*parcouru;

	g_ant_count = -1;
	if (argc != 2)
		ft_error("Error");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("Error");
	parse(fd);
	test_arg();
	ft_printf("\n");
	start = find_room_hashtag(g_room_list, 1);
	end = find_room_hashtag(g_room_list, 2);
	parcouru = init_struct_parcours(start);
	if (start == NULL || end == NULL || !g_ant_count)
		ft_error("Error");
	end->distance = 0;
	dijkstra(end, 0);
	display_algo(start, end, parcouru);
	return (0);
}
