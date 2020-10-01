/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 13:35:14 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/03 13:35:31 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char					*ft_uitoa_ull(unsigned long long int nb)
{
	char	*str;
	int		s;
	int		i;

	i = 0;
	s = ((unsigned int)ft_int_len_ulli(nb) + 1);
	if (!(str = (char*)malloc(sizeof(char) * (s))))
		return (0);
	i--;
	str[--s] = '\0';
	while (--s != i)
	{
		str[s] = (char)('0' + nb % 10);
		nb = nb / 10;
	}
	return (str);
}

char					*ft_uitoa_ul(unsigned long int nb)
{
	char	*str;
	int		s;
	int		i;

	i = 0;
	s = ((unsigned int)ft_int_len_uli(nb) + 1);
	if (!(str = (char*)malloc(sizeof(char) * (s))))
		return (0);
	i--;
	str[--s] = '\0';
	while (--s != i)
	{
		str[s] = (char)('0' + nb % 10);
		nb = nb / 10;
	}
	return (str);
}

char					*ft_uitoa(unsigned int nb)
{
	char	*str;
	int		s;
	int		i;

	i = 0;
	s = ((unsigned int)ft_int_len_ui(nb) + 1);
	if (!(str = (char*)malloc(sizeof(char) * (s))))
		return (0);
	i--;
	str[--s] = '\0';
	while (--s != i)
	{
		str[s] = (char)('0' + nb % 10);
		nb = nb / 10;
	}
	return (str);
}
