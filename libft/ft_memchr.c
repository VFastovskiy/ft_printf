/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 20:39:55 by blakeish          #+#    #+#             */
/*   Updated: 2019/09/11 23:35:32 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void					*ft_memchr(const void *s, int c, size_t n)
{
	size_t				l;
	const unsigned char	*p;

	l = 0;
	p = s;
	while (l < n)
	{
		if (p[l] == ((unsigned char)c))
			return (&((void*)p)[l]);
		l++;
	}
	return (NULL);
}
