/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func_for_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jczech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 13:16:22 by jczech            #+#    #+#             */
/*   Updated: 2020/02/22 13:21:49 by jczech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int				is_dec(long double f)
{
	if (f > 0)
		if (get_dec(f) > 0)
			return (1);
	if (f < 0)
		if (get_dec_neg(f) > 0)
			return (1);
	return (0);
}

long double		get_dec_neg(long double f)
{
	int			count;
	long double	nb;

	nb = -1;
	count = ct_ndec_digit(f);
	if (count == 0)
		return (-f);
	while (count != 1)
	{
		nb = nb * 10;
		count--;
	}
	while (f <= -1)
	{
		while (ct_ndec_digit(f) == ct_ndec_digit(nb))
			f = f - nb;
		nb /= 10;
		if (nb == 0)
			break ;
	}
	if (f == 0)
		return (0);
	return (-f);
}

long double		get_dec(long double f)
{
	int			count;
	long double	nb;

	nb = 1;
	count = ct_ndec_digit(f);
	if (count == 0)
		return (f);
	while (count != 1)
	{
		nb = nb * 10;
		count--;
	}
	while (f >= 1)
	{
		while (ct_ndec_digit(f) == ct_ndec_digit(nb))
			f = f - nb;
		nb /= 10;
		if (nb == 0)
			break ;
	}
	if (f == 0)
		return (0);
	return (f);
}

void			correct_back_ad01(char *s)
{
	int i;

	i = 0;
	while (s[i] != '.')
		i++;
	i++;
	s[i]--;
	return ;
}

char			*dec_char(long double f)
{
	long int nb;

	nb = 0;
	if (f > 0 && get_dec(f) < 0.1)
		nb = prec_ftoi(get_dec(f) + 0.1);
	else if (f < 0 && get_dec_neg(f) < 0.1)
		nb = prec_ftoi(get_dec_neg(f) + 0.1);
	else if (f > 0)
		nb = prec_ftoi(get_dec(f));
	else if (f < 0)
		nb = prec_ftoi(get_dec_neg(f));
	return (ft_ldtoa(nb));
}
