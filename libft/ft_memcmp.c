/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:44:46 by blakeish          #+#    #+#             */
/*   Updated: 2019/09/11 23:31:09 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int							ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t					l;
	const unsigned char		*p1;
	const unsigned char		*p2;

	l = 0;
	p1 = (const unsigned char*)s1;
	p2 = (const unsigned char*)s2;
	while (l < n)
	{
		if (p1[l] != p2[l])
			return (p1[l] - p2[l]);
		l++;
	}
	return (0);
}
