/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:36:43 by blakeish          #+#    #+#             */
/*   Updated: 2019/09/23 18:10:25 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	l;

	l = 0;
	while (l < n)
	{
		((unsigned char*)dst)[l] = ((unsigned char*)src)[l];
		if (((unsigned char*)src)[l] == ((unsigned char)c))
			return (&dst[l + 1]);
		l++;
	}
	return (NULL);
}
