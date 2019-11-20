/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:22:09 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/11/20 19:52:10 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_clst    t_clst;
typedef struct s_elem   t_elem;

struct  s_elem
{
    t_elem  *next;
    t_elem  *prev;
    int     v;
};

struct  s_clst
{
    char    name;
    int     size;
    t_elem  *head;
};

int		push_back(t_clst *lst, int value);
void	insert_elem(t_clst *lst, t_elem *elem);
int		*to_tab(t_clst *lst, int size);
void	clear_list(t_clst *lst);
t_elem	*pop_elem(t_clst *lst);
t_elem	*find_max(t_clst *lst);
t_elem	*find_min(t_clst *lst);


char	op_p(t_clst *from, t_clst *to);
char	op_rr(t_clst *lst);
char	op_r(t_clst *lst);
char	op_s(t_clst *lst);

#endif