/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inscrem_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jczech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:12:59 by jczech            #+#    #+#             */
/*   Updated: 2020/02/22 17:14:37 by jczech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		part_2(char *tmp, int precis, unsigned int i)
{
	int flag;

	flag = 1;
	while (flag == 1)
	{
		if (tmp[i + precis] == '.')
			i--;
		if (tmp[i + precis] == '9')
		{
			tmp[i + precis] = '0';
			flag = 1;
		}
		else
		{
			tmp[i + precis]++;
			flag = 0;
		}
		i--;
	}
}

void			increm_s(char *tmp, int precis)
{
	unsigned int i;

	i = 0;
	while (tmp[i] != '.')
		i++;
	if (ft_strlen(tmp) == i)
		return ;
	if (tmp[i + precis + 1] >= '5')
	{
		if (tmp[i + precis] == '.')
			i--;
		if (tmp[i + precis] + 1 < '9')
			tmp[i + precis]++;
		else
			part_2(tmp, precis, i);
	}
}
