/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:23:32 by mvo-van-          #+#    #+#             */
/*   Updated: 2020/01/10 14:30:59 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"

# define FLAG_SA	1
# define FLAG_SB	2
# define FLAG_PA	4
# define FLAG_PB	8
# define FLAG_RA	16
# define FLAG_RB	32
# define FLAG_RRA	64
# define FLAG_RRB	128

typedef struct	s_lst_gp
{
	struct s_lst_gp	*prev;
	int				nb;
	int				groupe;
	int				petit;
	int				grand;
	int				size;
	struct s_lst_gp	*next;
}				t_lst_gp;

typedef struct	s_lst_instr
{
	struct s_lst_instr	*prev;
	int					flag;
	struct s_lst_instr	*next;
}				t_lst_instr;

typedef struct	s_ptr_list
{
	t_lst_gp		*lst_a;
	t_lst_gp		*lst_b;
	t_lst_instr		*instr;
	int				nb_gp;
}				t_ptr_list;

typedef struct	s_save
{
	char		str[4];
	int			i;
	int			j;
}				t_save;

int				ft_verif_arg (int *tab, int x, char *str);
t_lst_gp		*ft_checker(t_lst_gp *lst_nb, int ac);
t_lst_gp		*ft_verif_instr(t_lst_instr *i, t_lst_gp *la, int ac);
t_lst_gp		*ft_result(t_lst_gp *lst_a, int size, t_lst_gp *lb);
t_lst_gp		*ft_creat_gp(t_lst_gp *lst_nb, int i, int size);
t_lst_instr		*ft_creat_instr(t_save save, t_lst_instr *i, int ret, char *t);
t_lst_gp		*ft_lst_prev_gp(t_lst_gp *ptr);
t_lst_gp		*ft_lst_next_gp(t_lst_gp *ptr);
void			ft_makes_gp(int flag, t_lst_gp *lst_a, t_lst_gp *lst_b);
void			ft_maker_gp(int flag, t_lst_gp *lst_a, t_lst_gp *lst_b);
void			ft_makerr_gp(int flag, t_lst_gp *lst_a, t_lst_gp *lst_b);
t_ptr_list		ft_makep_gp(int flag, t_ptr_list list);
int				ft_verifs(char c, t_lst_instr *instr);
int				ft_verifp(char c, t_lst_instr *instr);
int				ft_verifr(char c, t_lst_instr *instr);
int				ft_verifrr(char c, t_lst_instr *instr);
void			ft_reduce_makes(t_lst_gp *lst);
void			ft_reduce_maker(t_lst_gp *lst);
void			ft_reduce_makerr(t_lst_gp *lst);
t_ptr_list		ft_reduce_makep(int f, t_lst_gp *d, t_lst_gp *r, t_ptr_list l);
t_lst_gp		*ft_free_gp(t_lst_gp *lst_b);
void			ft_fail(char *buff, t_lst_instr *ptr_instr);
int				ft_free(int *tab, int sav, char **av, int ac);

#endif
