/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s <jpedro-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:58:48 by jpedro-s          #+#    #+#             */
/*   Updated: 2022/05/15 02:13:34 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_type(va_list args, const char *format)
{
	char	type;

	type = *ft_strchr("cspdiuxX%", *format);
	if (type == 'c')
		return (ft_type_c(va_arg(args, int)));
	if (type == 's')
		return (ft_type_s(va_arg(args, char *)));
	if (type == 'p')
		return (ft_type_p(va_arg(args, unsigned long int)));
	if (ft_strchr("diu", type))
		return (ft_type_diu(va_arg(args, int), type));
	if (ft_strchr("Xx", type))
		return (ft_type_x(va_arg(args, int), type));
	if (type == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%' && ft_strchr("cspudixX%", *(format + 1)))
		{
			format++;
			len += ft_type(args, format);
			format++;
		}
		else
		{
			len += write(1, format, 1);
			format++;
		}
	}
	va_end(args);
	return (len);
}
