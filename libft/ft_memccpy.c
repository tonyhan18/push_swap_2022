/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:53:45 by chahan            #+#    #+#             */
/*   Updated: 2022/04/10 16:25:38 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*temp;
	unsigned char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	temp = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n--)
	{
		*temp = *s;
		if (*s == (unsigned char)c)
			return (temp + 1);
		temp++;
		s++;
	}
	return (NULL);
}
