/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:46:34 by tmyrcell          #+#    #+#             */
/*   Updated: 2020/02/22 17:12:32 by jczech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	recording_process(const char *input, va_list ap, char **result)
{
	size_t	len;
	size_t	index;
	int		local_size;
	int		offset;
	char	*output;

	output = NULL;
	index = 0;
	len = 0;
	while (input[index])
	{
		if (input[index] == '%')
		{
			*result = ft_str_concat_unsafe(*result, input, len, index);
			len += index;
			input += index + 1;
			index = 0;
			local_size = ft_find_format(&input, &output, ap, &offset);
			if (local_size != -1)
			{
				*result = ft_str_concat_unsafe(*result, output, len, local_size);
				ft_strdel(&output);
				len += local_size;
				input += offset;
			}
			else
			{
				ft_strdel(result);
				return (ft_strlen(input));
			}
		}
		else
			index++;
	}
	local_size = ft_strlen(input);
	*result = ft_str_concat_unsafe(*result, input, len, local_size);
	len += local_size;
	return (len);
}

int			ft_printf(const char *format, ...)
{
	char	*ret;
	va_list	ap;
	size_t	len;

	ret = NULL;
	va_start(ap, format);
	len = recording_process(format, ap, &ret);
	if (ret)
	{
		write(1, ret, len);
		free(ret);
	}
	va_end(ap);
	return (len);
}

static char	*ft_strncpy_unsafe(char *dst, const char *src, size_t n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char		*ft_str_concat_unsafe(char *left, const char *right, size_t offset,
		size_t count)
{
	char *result;

	result = ft_strnew(offset + count);
	if (!result)
		return (NULL);
	if (left)
	{
		ft_strncpy_unsafe(result, left, offset);
		free(left);
	}
	ft_strncpy_unsafe(result + offset, right, count);
	return (result);
}
