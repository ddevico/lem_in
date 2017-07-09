/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_managestruct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddevico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 10:01:03 by ddevico           #+#    #+#             */
/*   Updated: 2016/01/19 11:58:21 by ddevico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*find_room_hashtag(t_room *room, int id)
{
	while (room != NULL)
	{
		if (id == room->id)
		{
			return (room);
		}
		room = room->next;
	}
	return (NULL);
}

void			room_push_front(t_room **room_head, t_room *room_to_copy)
{
	t_room		*new_room;

	new_room = malloc(sizeof(*new_room));
	ft_memcpy(new_room, room_to_copy, sizeof(*room_to_copy));
	new_room->next = *room_head;
	*room_head = new_room;
}

t_room			*room_exist(t_room *room, char *name)
{
	while (room != NULL)
	{
		if (ft_strcmp(name, room->name) == 0)
		{
			return (room);
		}
		room = room->next;
	}
	return (NULL);
}

void			voisin_push_front(t_voisin **voisin, t_room *room)
{
	t_voisin	*new_voisin;

	new_voisin = malloc(sizeof(*new_voisin));
	new_voisin->room = room;
	new_voisin->next = *voisin;
	*voisin = new_voisin;
}

t_voisin		*next_voisin(t_room *room)
{
	t_voisin	*n;
	t_voisin	*closest;

	if (room == NULL)
		ft_error("Error");
	n = room->next_voisin;
	closest = n;
	while (n != NULL)
	{
		if (n->room != NULL && n->room->distance < closest->room->distance)
		{
			closest = n;
		}
		n = n->next;
	}
	if (closest == NULL)
		ft_error("Error");
	return (closest);
}
