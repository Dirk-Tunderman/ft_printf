/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunderm <dtunderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:37:33 by dtunderm          #+#    #+#             */
/*   Updated: 2022/11/28 17:47:24 by dtunderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	ft_x_len(unsigned long c)
{
	int		i;

	i = 0;
	if (c == 0)
		return (1);
	while (c > 0)
	{
		c = c / 16;
		i++;
	}
	return (i);
}

static char	*transform_x(int len, char *dst, unsigned int src)
{
	char	temp;
	int		temp2;

	dst[len--] = '\0';
	while (len >= 0)
	{
		temp2 = (src % 16);
		src = src / 16;
		if (temp2 > 9)
			temp = temp2 + 87;
		else
			temp = temp2 + '0';
		dst[len--] = temp;
	}
	return (dst);
}

int	ft_print_x(unsigned int c)
{	
	char	*num;
	int		len;
	int		error;

	len = ft_x_len(c);
	num = malloc(sizeof(char) * (len + 1));
	if (!num)
		return (-1);
	num = transform_x(len, num, c);
	if (!num)
		return (free(num), -1);
	error = ft_put_str(num);
	if (error < 0)
		return (free(num), -1);
	free(num);
	return (len);
}
