/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_precis_for_f.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jczech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:30:35 by jczech            #+#    #+#             */
/*   Updated: 2020/02/22 17:32:57 by jczech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char	*preciz_part2(char *tmp, int ct)
{
	if (ct >= 6)
	{
		increm_s(tmp, ct);
		while (ct > 6)
		{
			tmp = ft_strjoin_free(tmp, "0");
			ct--;
		}
	}
	if (ct <= 6)
	{
		increm_s(tmp, ct);
		ct = 6 - ct;
		tmp = ft_strsub_free(tmp, 0, ft_strlen(tmp) - ct);
		return (tmp);
	}
	return (tmp);
}

char		*step_precis_for_f(t_flag *flag, char *tmp)
{
	int ct;

	if (flag->precision == 0 && (flag->prec == 1))
	{
		if (locate_char_index(tmp, '.') != -41)
		{
			if (tmp[locate_char_index(tmp, '.') + 1] >= '5')
				increm_s(tmp, 1);
		}
		if (flag->flag_hash == 1)
			tmp = ft_strsub_free(tmp, 0, locate_char_index(tmp, '.') + 1);
		else
			tmp = ft_strsub_free(tmp, 0, locate_char_index(tmp, '.'));
	}
	else if (flag->precision > 0)
	{
		ct = flag->precision;
		tmp = preciz_part2(tmp, ct);
	}
	return (tmp);
}
