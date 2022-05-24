/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:06:02 by smessal           #+#    #+#             */
/*   Updated: 2022/05/24 12:22:39 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
    va_list args;
    int     i;
    int     len;

    va_start(args, str);
    i = 0;
    len = 0;
    while (str[i])
    {
       if (str[i + 1] && str[i] == '%' && str[i + 1] == 'c')
        {
            ft_p_char(va_arg(args, int));
            i = i + 2;
        }
        else if (str[i + 1] && str[i] == '%' && str[i + 1] == 's')
        {
            ft_p_str(va_arg(args, char *));
            i = i + 2;
        }
        else if (str[i + 1] && str[i] == '%' && str[i + 1] == 'p')
        {
            write(1, "0x", 2);
            ft_p_pointer(va_arg(args, unsigned long long int));
            i = i + 2;
        }
        else if (str[i + 1] && str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
        {
            ft_p_num(va_arg(args, int));
            i = i + 2;
        }
        else if (str[i + 1] && str[i] == '%' && str[i + 1] == 'u')
        {
            ft_p_num(va_arg(args, int));
            i = i + 2;
        }
        ft_p_char(str[i++]);
    }
    return (len);
}

int main(void)
{
    char *test = NULL;
    ft_printf("lol jai %p boire %d lol", &test, 5875);
    printf("\nlol jai %p boire %d lol", &test, 5875);
}