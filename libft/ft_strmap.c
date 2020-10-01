/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:28:59 by blakeish          #+#    #+#             */
/*   Updated: 2019/09/23 18:21:35 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		k;
	char	*new;

	if (s && f)
	{
		i = 0;
		k = ft_strlen(s);
		new = (char*)malloc(sizeof(char) * (k + 1));
		if (new == NULL)
			return (NULL);
		while (s[i])
		{
			new[i] = f(s[i]);
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
