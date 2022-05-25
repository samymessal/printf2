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

static int	ft_nonvalid(char c)
{
	char	*test;
	int		i;

	i = 0;
	test = "csdipuxX";
	while (test[i])
	{
		if (test[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_getlen(char c, va_list args)
{
	int	len;
	int	p;
	
	len = 0;
	p = 0;
	if (c == 'c')
		len = 1;
	else if (c == 's')
		len = ft_strlen(va_arg(args, char *));
	else if (c == 'p')
	{
		p = va_arg(args, unsigned long long int);
		if (p)
			len = ft_len_pointer(p);
		else
			len = 5;
	}
	else if (c == 'd' || c == 'i')
		len = ft_lennum(va_arg(args, int));
	else if (c == 'u')
		len = ft_lenuns(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		len = ft_len_hexa(va_arg(args, unsigned int));
	return (len);
}

void	ft_printer(char c, va_list args)
{
	unsigned long long int	p;

	p = 0;
	if (c == 'c')
		ft_p_char(va_arg(args, int));
	else if (c == 's')
		ft_p_str(va_arg(args, char *));
	else if (c == 'p')
	{
		p = va_arg(args, unsigned long long int);
		if (p)
		{
			write(1, "0x", 2);
			ft_p_pointer(p);
		}
		else
			write(1, "(nil)", 5);
	}
	else if (c == 'd' || c == 'i')
		ft_p_num(va_arg(args, int));
	else if (c == 'u')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	else if (c == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
}

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
    	if (str[i] == '%' && ft_nonvalid(str[i + 1]))
		{
			ft_printer(str[++i], args);
			len += ft_getlen(str[i], args);
		}
		else if (str[i] == '%' && str[i + 1] == '%')
		{
			ft_p_char(str[++i]);
			len += 1;
		}
		else
		{
			ft_p_char(str[i]);
			len += 1;
		}
		i++;
    }
	va_end(args);
    return (len);
}

int main(void)
{
    char *test = NULL;
    int x = ft_printf("my ft_printf : [%i, %i, %i]\n", (int)-2147483648, (int)2147483647, 0);
	int y = printf("my ft_printf : [%i, %i, %i]\n", (int)-2147483648, (int)2147483647, 0);
	printf("\nmy: %d org: %d", x, y);
}