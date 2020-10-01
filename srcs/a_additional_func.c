/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_additional_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <blakeish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 18:33:02 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/04 15:44:10 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_append(char *str, char c)
{
	size_t	len;
	char	*str2;

	len = 0;
	if (str)
		len = ft_strlen(str);
	if (!(str2 = (char*)malloc(len + 1 + 1)))
		return (NULL);
	if (str)
		ft_strcpy(str2, str);
	str2[len] = c;
	str2[len + 1] = '\0';
	return (str2);
}

char	*ft_revappend(char c, char *str)
{
	char	*str2;
	size_t	len;

	len = ft_strlen(str);
	if (!(str2 = (char*)malloc(sizeof(char) * (len + 1 + 1))))
		return (NULL);
	str2[0] = c;
	if (str && str2)
		str2 = ft_strcat(str2, str);
	str2[len + 1] = '\0';
	return (str2);
}

void	check_precision(t_print *printf, int i)
{
	printf->prec = printf->precision;
	if (printf->itoa[0] == '-')
		i--;
	if (printf->precision - i >= 0)
		printf->precision -= i;
	else
		printf->precision = 0;
}
