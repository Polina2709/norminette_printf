/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:00:38 by tmyrcell          #+#    #+#             */
/*   Updated: 2019/09/14 15:17:50 by tmyrcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tolower(int c)
{
	if (c >= 97 && c <= 122)
		return (c);
	if (c >= 65 && c <= 90)
		return (c - 65 + 97);
	return (c);
}
