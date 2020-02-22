/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:46:15 by tmyrcell          #+#    #+#             */
/*   Updated: 2020/02/21 11:48:12 by tmyrcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_dtoa(double d)
{
	char			*s;
	long double		f;

	f = d;
	if (f == 0)
		return (ft_strdup("0"));
	s = non_dec_char(f);
	if (is_dec(f) == 1)
	{
		s = ft_strjoin_free(s, ".");
		s = ft_strjoin_free(s, dec_char(f));
		if ((get_dec(f) > 0 && get_dec(f) < 0.1) ||
				(get_dec_neg(f) > 0 && get_dec_neg(f) < 0.1))
			correct_back_ad01(s);
	}
	if (f < 0)
		s = ft_strjoin_free2("-", s);
	return (s);
}
