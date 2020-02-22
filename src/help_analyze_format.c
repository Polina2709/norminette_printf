/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_analyze_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jczech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 13:10:08 by jczech            #+#    #+#             */
/*   Updated: 2020/02/22 13:10:26 by jczech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void			init_width_star(t_flag *flag, va_list ap, int sign_pres)
{
	int wid;

	wid = (int)va_arg(ap, int);
	if (wid < 0)
	{
		flag->flag_minus = 1;
		wid *= -1;
	}
	if (sign_pres == 1)
		flag->width = wid;
	else if (sign_pres == 2)
		flag->precision = wid;
}

void			analyze_precision(char **stringformat, t_flag *flag, va_list ap)
{
	if (**stringformat != '.')
		return ;
	(*stringformat)++;
	flag->prec = 1;
	if (**stringformat == '*')
	{
		init_width_star(flag, ap, 2);
		(*stringformat)++;
		return ;
	}
	flag->precision = ft_atoi(*stringformat);
	while (ft_isdigit(**stringformat))
		(*stringformat)++;
}

void			analyze_flags(char stringformat, t_flag *flag, va_list ap)
{
	if (stringformat == '#')
		flag->flag_hash = 1;
	if (stringformat == '+')
		flag->flag_plus = 1;
	if (stringformat == ' ')
		flag->flag_space = 1;
	if (stringformat == '0')
		flag->flag_zero = 1;
	if (stringformat == '-')
		flag->flag_minus = 1;
	if (stringformat == '*')
		init_width_star(flag, ap, 1);
}

int				analyze_specifiers(char *stringformat, t_flag *flag)
{
	if (ft_strchr(SPECIFIERS, *stringformat))
	{
		if (*stringformat == 'i')
			*stringformat = 'd';
		(flag->format)[0] = *stringformat;
		return (1);
	}
	return (0);
}
