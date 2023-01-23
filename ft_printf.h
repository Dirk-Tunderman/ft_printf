/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunderm <dtunderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:38:49 by dtunderm          #+#    #+#             */
/*   Updated: 2022/12/05 14:02:08 by dtunderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int					ft_print_p(unsigned long long int c);
int					ft_print_x(unsigned int c);
int					ft_put_char(int a);
int					ft_put_str(const char *str);
int					ft_put_int(int c);
int					ft_unsigned_toa(unsigned int c);
int					ft_print_type(va_list args, char c, int *i);
int					ft_printf(const char *string, ...);
int					ft_print_xx(unsigned int c);
int					ft_put_u(unsigned int c);
int					ft_put_perc(void);
char				*ft_itoa_u(unsigned int n);

#endif
