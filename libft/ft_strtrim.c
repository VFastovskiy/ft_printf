/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:33:29 by blakeish          #+#    #+#             */
/*   Updated: 2019/09/23 18:24:04 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*str;

	if (s)
	{
		len = ft_strlen(s);
		while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
			len--;
		i = -1;
		while (s[++i] == ' ' || s[i] == '\t' || s[i] == '\n')
			len--;
		if (len <= 0)
			len = 0;
		if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		s += i;
		i = -1;
		while (++i < len)
			str[i] = *s++;
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
