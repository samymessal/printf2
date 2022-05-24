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

    len = 1;
    while (num >= 16)
    {
        num /= 16;
        len++;
    }
    return (len);
}
/*
int main(void)
{
    printf("%d",ft_len_pointer(42));
}
*/