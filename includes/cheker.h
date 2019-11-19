/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:23:32 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/05/07 17:23:35 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHEKER_H
# define CHEKER_H

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

typedef struct s_lst_nb
{
    struct s_lst_nb *prev;
    int             nb;
    int             size;
    struct s_lst_nb *next;
}t_lst_nb;

typedef struct s_lst_instr
{
    struct s_lst_instr  *prev;
    int                 flag;
    struct s_lst_instr  *next;
}t_lst_instr;

typedef struct s_save
{
    char           str[4];
    int             i;
    int             j;
}t_save;

int         ft_verif_arg(char **av, int ac);
t_lst_nb    *ft_cheker(t_lst_nb *lst_nb);
t_lst_nb    *ft_verif_instr(t_lst_instr *ptr_instr, t_lst_nb *lst_a);
void        ft_result(t_lst_nb *lst_nb, int size);
t_lst_nb    *ft_creat_nb(t_lst_nb *lst_nb, int i, int size);
t_lst_instr *ft_creat_instr(t_save  save, t_lst_instr *lst_instr);
t_lst_nb    *ft_lst_prev(t_lst_nb *ptr);
t_lst_nb    *ft_lst_next(t_lst_nb *ptr);
void        ft_makeS(int flag,t_lst_nb *lst_a,t_lst_nb *lst_b);
void        ft_makeP(int flag,t_lst_nb *lst_a,t_lst_nb *lst_b);
void        ft_makeR(int flag,t_lst_nb *lst_a,t_lst_nb *lst_b);
void        ft_makeRR(int flag,t_lst_nb *lst_a,t_lst_nb *lst_b);
void        ft_verifS(char c, t_lst_instr *instr);
void        ft_verifP(char c, t_lst_instr *instr);
void        ft_verifR(char c, t_lst_instr *instr);
void        ft_verifRR(char c, t_lst_instr *instr);
#endif
