/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:36:10 by blakeish          #+#    #+#             */
/*   Updated: 2019/09/23 19:12:23 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s1, unsigned int start, size_t len)
{
	char			*sub;
	int				i;
	unsigned int	y;

	i = 0;
	y = 0;
	if (s1)
	{
		sub = (char*)malloc(sizeof(char) * (len + 1));
		if (sub == NULL)
			return (NULL);
		while (y < start)
			y++;
		while (i < (int)len)
		{
			sub[i] = s1[y];
			i++;
			y++;
		}
		sub[i] = '\0';
		return (sub);
	}
	return (NULL);
}
