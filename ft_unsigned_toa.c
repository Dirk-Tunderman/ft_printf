/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_toa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunderm <dtunderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:37:55 by dtunderm          #+#    #+#             */
/*   Updated: 2022/11/28 13:18:58 by dtunderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	count_len(unsigned int c)
{
	int		i;

	i = 0;
	while (c > 0)
	{
		c = c / 10;
		i++;
	}
	return (i);
}

int	ft_unsigned_toa(unsigned int c)
{
	char	*num;
	int		count;
	int		len;

	count = count_len(c);
	num = malloc(sizeof(char) * count + 1);
	if (!(num))
		return (-1);
	num[count--] = '\0';
	len = count;
	while (count > 0)
	{
		num[count--] = (c % 10) + '0';
		c = c / 10;
	}
	return (ft_put_str(num));
}
