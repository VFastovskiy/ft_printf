/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:58:44 by blakeish          #+#    #+#             */
/*   Updated: 2019/09/21 00:48:02 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	char	*dst;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	dst = (char*)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
