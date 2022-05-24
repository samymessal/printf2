/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:06:12 by smessal           #+#    #+#             */
/*   Updated: 2022/05/24 12:19:19 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>

int ft_printf(const char *str, ...);
int ft_p_char(char c);
int ft_p_str(char *str);
void ft_p_pointer(unsigned long long int num);
void    ft_p_num(int num);

#endif