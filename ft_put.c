/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunderm <dtunderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:37:53 by dtunderm          #+#    #+#             */
/*   Updated: 2022/12/05 15:34:35 by dtunderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_put_char(int a)
{
	int	i;

	i = write(1, &a, 1);
	return (i);
}

int	ft_put_str(const char *str)
{
	int		i;
	int		error;

	i = 0;
	error = 0;
	if (str == NULL)
	{
		error = ft_put_str("(null)");
		if (error < 0)
			return (-1);
		return (6);
	}
	error = 0;
	while (str[i])
	{
		error = write (1, &str[i], 1);
		if (error < 0)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_put_int(int c)
{
	char	*a;
	int		count;

	a = ft_itoa(c);
	if (!a)
		return (free(a), -1);
	count = ft_put_str(a);
	free(a);
	return (count);
}

int	ft_put_u(unsigned int c)
{
	char	*a;
	int		count;

	count = 0;
	if (c == 0)
		count += ft_put_char('0');
	else
	{
		a = ft_itoa_u(c);
		if (!a)
			return (free(a), -1);
		count = ft_put_str(a);
		free(a);
	}
	return (count);
}

int	ft_put_perc(void)
{
	int	i;

	i = write(1, "%", 1);
	return (i);
}
