/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:26:14 by mbeaujar          #+#    #+#             */
/*   Updated: 2020/09/20 22:31:52 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string_dot(char *s, t_flags flags)
{
	int print;

	print = 0;
	if (flags.dot >= 0)
	{
		print += ft_print(flags.dot, ft_strlen(s), ' ');
		print += ft_printstr(s, flags.dot);
	}
	else
		print += ft_printstr(s, ft_strlen(s));
	return (print);
}

int	ft_print_string(char *s, t_flags flags)
{
	int print;

	print = 0;
	if (!s)
		s = "(null)";
	if (flags.dot >= 0 && (flags.dot > ft_strlen(s)))
		flags.dot = ft_strlen(s);
	if (flags.less == 1)
		print += ft_print_string_dot(s, flags);
	if (flags.dot >= 0)
		print += ft_print(flags.width, flags.dot, flags.zero);
	else
		print += ft_print(flags.width, ft_strlen(s), flags.zero);
	if (flags.less == 0)
		print += ft_print_string_dot(s, flags);
	return (print);
}
