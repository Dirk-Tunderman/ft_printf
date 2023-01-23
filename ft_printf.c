/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunderm <dtunderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:37:38 by dtunderm          #+#    #+#             */
/*   Updated: 2022/12/14 14:45:34 by dtunderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int	ft_print_type(va_list args, char c, int *i)
{
	int		count;

	*i = *i + 1;
	count = 0;
	if (c == 'c')
		count = ft_put_char(va_arg(args, int));
	else if (c == 's')
		count = ft_put_str(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count = ft_put_int(va_arg(args, int));
	else if (c == 'u')
		count = ft_put_u(va_arg(args, unsigned int));
	else if (c == 'p')
		count = ft_print_p(va_arg(args, unsigned long long int));
	else if (c == 'x')
		count = ft_print_x(va_arg(args, int));
	else if (c == 'X')
		count = ft_print_xx(va_arg(args, int));
	else if (c == '%')
		count = ft_put_perc();
	return (count);
}

int	ft_printf(const char *string, ...)
{
	va_list		args;
	int			i;
	int			temp;
	int			total;

	va_start(args, string);
	i = 0;
	total = 0;
	while (string[i])
	{
		if (string[i] == '%')
		{
			if (string[i + 1] == '\0')
				temp = 0;
			else
				temp = ft_print_type(args, string[i + 1], &i);
		}
		else
			temp = ft_put_char(string[i]);
		if (temp < 0)
			return (-1);
		total = total + temp;
		i++;
	}
	return (va_end(args), total);
}

int main()
{
	int i = -12346;

	ft_printf("%x\n", i);
	//ft_printf("%d\n", i);	
	printf("%x\n", i);
	//printf("%d\n", i);
}

