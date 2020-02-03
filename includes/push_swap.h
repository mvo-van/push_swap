/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:50:39 by mvo-van-          #+#    #+#             */
/*   Updated: 2020/01/10 15:00:35 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define FLAG_SA	1
# define FLAG_SB	2
# define FLAG_PA	4
# define FLAG_PB	8
# define FLAG_RA	16
# define FLAG_RB	32
# define FLAG_RRA	64
# define FLAG_RRB	128

typedef struct	s_lst_nb
{
	struct s_lst_nb	*prev;
	int				gp;
	int				nb;
	struct s_lst_nb	*next;
}				t_lst_nb;

typedef struct	s_lst_instr
{
	struct s_lst_instr	*prev;
	int					flag;
	struct s_lst_instr	*next;
}				t_lst_instr;

typedef struct	s_ptr_lst
{
	t_lst_nb		*lst_a;
	t_lst_nb		*lst_b;
	t_lst_instr		*lst_flag;
	int				*deb_tab;
	int				*tab;
}				t_ptr_lst;

typedef struct	s_lst
{
	struct s_lst	*prev;
	t_lst_instr		*ptr;
	struct s_lst	*next;
}				t_lst;

typedef struct	s_ptr_lst_instr
{
	t_lst			*sa;
	t_lst			*sb;
	t_lst			*pa;
	t_lst			*pb;
	t_lst			*ra;
	t_lst			*rb;
	t_lst			*rra;
	t_lst			*rrb;
	t_lst_instr		*lst;
}				t_ptr_lst_instr;

char			**ft_strsplit2(char const *s, char c);
int				ft_verif (int *tab, int x, char *str);
int				ft_print_error(int *tab);
t_lst_nb		*ft_creat_lst_nb(t_lst_nb *lst_nb, int i);
t_lst_nb		*ft_lst_next_nb(t_lst_nb *ptr);
t_lst_nb		*ft_lst_prev_nb(t_lst_nb *ptr);
t_ptr_lst		ft_make_p_nb(int flag, t_ptr_lst list);
void			ft_make_s_nb(int flag, t_lst_nb *lst_a, t_lst_nb *lst_b);
void			ft_make_r_nb(int flag, t_lst_nb *lst_a, t_lst_nb *lst_b);
void			ft_make_rr_nb(int flag, t_lst_nb *lst_a, t_lst_nb *lst_b);
t_lst_instr		*ft_creat_lst_instr(t_lst_instr *lst_instr, int flag);
t_ptr_lst		ft_make_instr(t_ptr_lst ptr_lst, int flag);
t_ptr_lst		ft_save_a2(t_ptr_lst ptr);
t_ptr_lst		ft_save_a3(t_ptr_lst ptr);
t_ptr_lst		ft_save_a(t_ptr_lst ptr, int cmp);
t_ptr_lst		ft_save_b3(t_ptr_lst ptr);
t_ptr_lst		ft_save_b(t_ptr_lst ptr, int cmp);
int				ft_cmp_gp(t_lst_nb *lst);
t_ptr_lst		ft_divise_avb(t_ptr_lst ptr, int *tab);
t_ptr_lst		ft_divise_bva(t_ptr_lst ptr, int *tab);
t_ptr_lst		ft_push_swap(t_ptr_lst ptr);
void			ft_gp_zero(t_lst_nb *lst, int i);
t_ptr_lst		ft_make_instr_times(t_ptr_lst ptr, int flag, int times);
int				ft_odre(int a, int b, int c);
t_lst_instr		*ft_opti_instr(t_lst_instr *lst);
t_ptr_lst_instr	ft_opti_rrb(t_ptr_lst_instr sav);
t_ptr_lst_instr	ft_opti_rra(t_ptr_lst_instr sav);
t_ptr_lst_instr	ft_opti_rb(t_ptr_lst_instr sav);
t_lst_instr		*ft_lst_prev_instr(t_lst_instr *ptr);
t_ptr_lst_instr	ft_sav_zero(t_lst_instr *lst);
t_lst			*ft_creat(t_lst *lst, t_lst_instr *instr);
t_lst			*ft_free_lst(t_lst *lst);
t_ptr_lst_instr	ft_opti_sa(t_ptr_lst_instr sav);
t_ptr_lst_instr	ft_opti_sb(t_ptr_lst_instr sav);
t_ptr_lst_instr	ft_opti_pa(t_ptr_lst_instr sav);
t_ptr_lst_instr ft_opti_pb(t_ptr_lst_instr sav);
t_ptr_lst_instr ft_opti_ra(t_ptr_lst_instr sav);
int				ft_print_instr(t_ptr_lst ptr, int sav, char **av, int ac);
int				ft_cmp_lst_nb(t_lst_nb *lst);
t_ptr_lst		ft_t_ptr_lst_zero(int *tab);
t_ptr_lst		ft_save_b3_seul(t_ptr_lst ptr);
t_ptr_lst		ft_save_b_seul(t_ptr_lst ptr, int cmp);
t_ptr_lst		ft_save_a_seul(t_ptr_lst ptr, int cmp);
int				ft_cmp_lst_gp(t_lst_nb *lst);
t_ptr_lst		ft_save_a3_seul(t_ptr_lst ptr);
t_ptr_lst		ft_tri_petit(t_ptr_lst ptr);
t_lst_instr		*ft_free_opti(t_lst_instr *lst, t_ptr_lst_instr sav);
int				ft_free(int sav, char **av, int ac);

#endif
