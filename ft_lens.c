/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lens.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:52:44 by smessal           #+#    #+#             */
/*   Updated: 2022/05/24 11:07:22 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_len_pointer(unsigned long long int num)
{
    int len;

    len = 3;
    while (num >= 16)
    {
        num /= 16;
        len++;
    }
    return (len);
}

int ft_lenuns(unsigned int num)
{
    int len;

    len = 0;
    while (num)
    {
        num /= 10;
        len++;
    }
    return (len);
}

int ft_len_hexa(unsigned int num)
{
    int len;

    len = 1;
    while (num >= 16)
    {
        num /= 16;
        len++;
    }
    return (len);
}

int ft_strlen(char *str)
{
    int len;

    len = 0;
    if (!str)
        return (6);
    while (str[len])
    {
        len++;
    }
    return (len);
}

int ft_lennum(int num)
{
    int             len;
    long long int   nbr;
    
    len = 0;
    nbr = num;
    if (nbr < 0)
    {
        len++;
        nbr *= -1;
    }
    else if (nbr == 0)
        return (1);
    while (nbr > 0)
    {
        nbr /= 10;
        len++;
    }
    return (len);
}