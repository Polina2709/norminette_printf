/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jczech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:43:10 by jczech            #+#    #+#             */
/*   Updated: 2020/02/22 17:47:52 by jczech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char	*non_dec_char_pos(long double f,
		long double nb, char *non_dec)
{
	int i;

	i = 0;
	while (f >= 1)
	{
		while (ct_ndec_digit(f) == ct_ndec_digit(nb))
		{
			f = f - nb;
			non_dec[i]++;
		}
		i++;
		nb /= 10;
		if (nb == 0)
			break ;
	}
	return (non_dec);
}

static char	*non_dec_char_neg(long double f,
		long double nb, char *non_dec)
{
	int i;

	i = 0;
	while (f <= -1)
	{
		while (ct_ndec_digit(f) == ct_ndec_digit(nb))
		{
			f = f + nb;
			non_dec[i]++;
		}
		i++;
		nb /= 10;
		if (nb == 0)
			break ;
	}
	return (non_dec);
}

char		*non_dec_char(long double f)
{
	char		*non_dec;
	int			count;
	long double	nb;

	if (ct_ndec_digit(f) == 0 && f != 0)
		return (ft_strdup("0"));
	if (!(non_dec = (char *)malloc(sizeof(char) *
				(ct_ndec_digit(f)) + 1)))
		return (NULL);
	nb = 1;
	ft_memset(non_dec, '0', (size_t)ct_ndec_digit(f));
	non_dec[ct_ndec_digit(f)] = 0;
	count = ct_ndec_digit(f);
	while (count != 1)
	{
		nb = nb * 10;
		count--;
	}
	if (f > 0)
		return (non_dec_char_pos(f, nb, non_dec));
	else if (f < 0)
		return (non_dec_char_neg(f, nb, non_dec));
	free(non_dec);
	return (NULL);
}

int			ct_ndec_digit(long double f)
{
	int count;

	count = 0;
	if (f > 0)
		while (f >= 1)
		{
			f /= 10;
			count++;
		}
	else if (f < 0)
		while (f <= -1)
		{
			f /= 10;
			count++;
		}
	return (count);
}
