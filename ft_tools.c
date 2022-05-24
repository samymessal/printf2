/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:15:09 by smessal           #+#    #+#             */
/*   Updated: 2022/05/24 12:19:36 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_strlen(char *str)
{
    int len;

    len = 0;
    while (str[len])
    {
        len++;
    }
    return (len);
}

int ft_p_char(char c)
{
    c = (unsigned char)c;
    write(1, &c, 1);
    return (1);
}

int ft_p_str(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}

void    ft_p_pointer(unsigned long long int num)
{
    char    *base;

    base = "0123456789abcdef";
    if (num >= ft_strlen(base))
    {
        ft_p_pointer(num / 16);
        ft_p_pointer(num % 16);
    }
    else
        ft_p_char(base[num]);
}

void    ft_p_num(int num)
{
    long long int   nbr;

    nbr = num;
    if (nbr < 0)
    {
        nbr *= - 1;
        write(1, "-", 1);
    }
    if (nbr >= 9)
    {
        ft_p_num(nbr / 10);
        ft_p_num(nbr % 10);
    }
    else
        ft_p_char(nbr + '0');
    
}
/*
int  main()
{
    ft_p_num(INT_MIN);
}
*/