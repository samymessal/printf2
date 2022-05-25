/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:23:16 by smessal           #+#    #+#             */
/*   Updated: 2022/05/24 12:23:26 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int nbr, char *base)
{
	unsigned int	len_base;
	unsigned char	val;

	len_base = 0;
	while (base[len_base])
		len_base++;
	if (nbr >= len_base)
	{
		ft_putnbr_base(nbr / len_base, base);
		ft_putnbr_base(nbr % len_base, base);
	}
	else
	{
		val = base[nbr];
		write(1, &val, 1);
	}
	return ;
}