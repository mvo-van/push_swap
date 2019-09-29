/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:50:39 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/05/24 17:50:41 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

# define FLAG_SA (1 << 0)      
# define FLAG_SB (1 << 1)      
# define FLAG_PA (1 << 2)       
# define FLAG_PB (1 << 3)      
# define FLAG_RA (1 << 4)       
# define FLAG_RB (1 << 5)       
# define FLAG_RRA (1 << 6)      
# define FLAG_RRB (1 << 7)      

typedef struct s_lst_gp
{
    struct s_lst_gp *prev;
    int             nb;
    int             groupe;
    int             petit;
    int             grand;
    int             size;
    int             piv;
    struct s_lst_gp *next;
} t_lst_gp;

typedef struct s_lst_instr
{
    struct s_lst_instr  *prev;
    int                 flag;
    struct s_lst_instr  *next;
}t_lst_instr;

typedef struct s_ptr_list
{
    int             *tab;
    t_lst_gp        *lst_a;
    t_lst_gp        *lst_b;
    t_lst_instr     *instr;
    int             nb_gp;
}t_ptr_list;



t_ptr_list            ft_push_swap(t_ptr_list list);
int             ft_make_groupe(t_lst_gp *lst_a);
t_ptr_list      ft_divise_gp(t_ptr_list list, int nb_gp);
t_ptr_list      ft_fusion_gp(t_ptr_list list);
void            ft_makeS_gp(int flag,t_lst_gp *lst_a,t_lst_gp *lst_b);
t_ptr_list      ft_makeP_gp(int flag,t_ptr_list list);
void            ft_makeR_gp(int flag,t_lst_gp *lst_a,t_lst_gp *lst_b);
void            ft_makeRR_gp(int flag,t_lst_gp *lst_a,t_lst_gp *lst_b);
t_lst_gp        *ft_creat_gp(t_lst_gp *lst_nb, int i, int size);
t_lst_instr     *ft_creat_instr(int  flag, t_lst_instr *lst_instr);
t_lst_gp        *ft_lst_prev_gp(t_lst_gp *lst_a);
t_lst_gp        *ft_lst_next_gp(t_lst_gp *lst_a);
void            ft_lst_zero(t_lst_gp *lst_a);
int             ft_verif_arg(char **av, int ac);
t_lst_instr     *ft_sup_P(t_lst_instr *instr);
t_lst_instr     *ft_print_instr(t_lst_instr *instr);
void            ft_free_instr(t_lst_instr *ptr, int nb);
t_lst_instr     *ft_prev_instr(t_lst_instr *instr);
//t_ptr_list      ft_goupe_fusion(t_ptr_list list);

#endif
