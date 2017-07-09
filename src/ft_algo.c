/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddevico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 10:01:03 by ddevico           #+#    #+#             */
/*   Updated: 2016/05/10 11:58:21 by ddevico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int g_max_depth;

void			dijkstra(t_room *room, int distance)
{
	t_voisin	*voisin;

	if (room != NULL)
	{
		voisin = room->next_voisin;
		while (voisin != NULL)
		{
			if (voisin->room != NULL
				&& (voisin->room->distance == -1
					|| voisin->room->distance > distance + 1))
			{
				if (distance + 1 > g_max_depth)
					g_max_depth = distance + 1;
				voisin->room->distance = distance + 1;
				dijkstra(voisin->room, distance + 1);
			}
			voisin = voisin->next;
		}
	}
}

static t_room	*next_room(t_room *tmp, t_room *room)
{
	tmp = room;
	room = next_voisin(room)->room;
	return (room);
}

void			display_step(t_room *room, int number_ant,
				t_parcouru *parcouru, t_room *tmp3)
{
	t_room		*tmp;
	int			i;
	int			j;
	int			k;
	int			tmp2;

	i = -1;
	j = 0;
	tmp = NULL;
	while (++i != number_ant)
	{
		if (parcouru[g_max_pass - 1].ant[i] != 1)
		{
			k = -1;
			room = tmp2 == i ? next_room(tmp, room) : tmp3;
			tmp2 = i;
			while (parcouru[++k].ant[i] == 1)
				room = next_room(tmp, room);
			ft_printf("L%d-%s ", j + 1, room->name);
			parcouru[k].ant[i] = 1;
		}
		j++;
	}
}

void			display_algo(t_room *room, t_room *destination,
				t_parcouru *parcouru)
{
	int			i;
	t_room		*tmp;
	t_room		*tmp2;
	t_room		*tmp3;

	i = 1;
	tmp2 = room;
	tmp3 = next_voisin(room)->room;
	while (tmp2 != destination)
	{
		tmp = tmp2;
		tmp2 = next_voisin(tmp2)->room;
		g_max_pass++;
	}
	while (1)
	{
		display_step(room, i, parcouru, tmp3);
		ft_printf("\n");
		if (i < g_ant_count)
			i++;
		if (parcouru[g_max_pass - 1].ant[g_ant_count - 1])
			break ;
	}
}
