/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:53:45 by chahan            #+#    #+#             */
/*   Updated: 2022/04/10 16:25:49 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*temp;
	const char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	s = src;
	temp = dest;
	if (dest <= src)
	{
		while (n--)
			*temp++ = *s++;
	}
	else
	{
		s += n;
		temp += n;
		while (n--)
			*--temp = *--s;
	}
	return (dest);
}
