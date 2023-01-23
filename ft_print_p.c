/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunderm <dtunderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:37:14 by dtunderm          #+#    #+#             */
/*   Updated: 2022/11/28 17:45:37 by dtunderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	ft_p_len(unsigned long c)
{
	int	i;

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

static char	*transform_p(int len, char *dst, unsigned long long int src)
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

int	ft_print_p(unsigned long long int c)
{	
	char	*num;
	int		len;
	int		count;
	int		error;

	count = 0;
	len = ft_p_len(c);
	num = malloc(sizeof(char) * (len + 1));
	if (!num)
		return (-1);
	num = transform_p(len, num, c);
	if (!num)
		return (free(num), -1);
	error = write (1, "0x", 2);
	if (error < 0)
		return (free(num), -1);
	count += ft_put_str(num);
	if (count < 0)
		return (free(num), -1);
	free(num);
	return (count + 2);
}
