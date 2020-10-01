/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_charcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <blakeish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 21:05:32 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/03 20:26:44 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putstr_pf(const char *str, t_print *printf)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			ft_putchar_pf(str[i], printf);
			i++;
		}
	}
}

void	ft_putchar_pf(int c, t_print *printf)
{
	write(1, &c, 1);
	printf->count++;
}

void	ft_init(char **width, t_width *wt)
{
	wt->w = 0;
	wt->i = 0;
	wt->str = ft_strdup(*width);
	wt->tmp = wt->str;
}
