/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qviguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 11:53:02 by qviguier          #+#    #+#             */
/*   Updated: 2016/01/07 16:53:43 by qviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "get_next_line.h"

typedef struct s_room		t_room;
typedef struct s_voisin		t_voisin;
typedef struct s_parcouru	t_parcouru;

struct						s_room
{
	char					*name;
	int						x;
	int						y;
	int						distance;
	int						use;
	int						id;
	t_room					*next;
	t_voisin				*next_voisin;
};

struct						s_voisin
{
	t_room					*room;
	t_voisin				*next;
};

struct						s_parcouru
{
	char					*name;
	int						*ant;
};

extern int					g_id;
extern int					g_ant_count;
extern int					g_case_count;
extern int					g_max_pass;
extern int					g_id_start;
extern int					g_id_end;
extern t_room				*g_room_list;

int							get_next_line(int const fd, char **line);

void						ft_error(char *s);
int							ft_strisnum(char *str);
int							countstr(char *str, char c);

void						room(char *line);
void						way(char *line);
void						hashtag(char *line);

void						room_push_front(t_room **room_head,
							t_room *room_to_copy);
t_room						*room_exist(t_room *room, char *name);
void						voisin_push_front(t_voisin **voisin, t_room *room);
t_room						*find_room_hashtag(t_room *room, int id);

void						display_step(t_room *room,
							int number_ant, t_parcouru *parcouru, t_room *tmp3);
void						dijkstra(t_room *room, int distance);
t_voisin					*next_voisin(t_room *room);
void						display_algo(t_room *room, t_room *destination,
							t_parcouru *parcouru);

#endif
