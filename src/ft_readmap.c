/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddevico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 10:01:03 by ddevico           #+#    #+#             */
/*   Updated: 2016/01/19 11:58:21 by ddevico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	room(char *line)
{
	char		**token;
	t_room		room;
	int			test;

	test = 0;
	token = ft_strsplit(line, ' ');
	room.name = token[0];
	room.x = ft_atoi(token[1]);
	room.y = ft_atoi(token[2]);
	room.distance = -1;
	room.next = NULL;
	room.id = g_id;
	room.next_voisin = NULL;
	g_id = 0;
	room_push_front(&g_room_list, &room);
	ft_printf("%s %d %d\n", room.name, room.x, room.y);
	g_case_count++;
}

void	way(char *line)
{
	char	**token;
	t_room	*left;
	t_room	*right;

	token = ft_strsplit(line, '-');
	left = room_exist(g_room_list, token[0]);
	right = room_exist(g_room_list, token[1]);
	if (left == NULL || right == NULL)
	{
		ft_error("Error");
		exit(1);
	}
	voisin_push_front(&left->next_voisin, right);
	voisin_push_front(&right->next_voisin, left);
	ft_printf("%s-%s\n", left->name, right->name);
}

void	hashtag(char *line)
{
	int drap;

	drap = 0;
	if (ft_strcmp(line, "##start") == 0 && g_id_start != 1)
	{
		g_id_start = 1;
		g_id = 1;
		drap = 1;
	}
	if (ft_strcmp(line, "##end") == 0 && g_id_end != 1)
	{
		g_id_end = 1;
		g_id = 2;
		drap = 1;
	}
	if (drap == 0)
		ft_error("Error");
	ft_printf("%s\n", line);
}
