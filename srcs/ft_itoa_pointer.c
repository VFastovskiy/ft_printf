/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <blakeish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 20:05:02 by blakeish          #+#    #+#             */
/*   Updated: 2020/08/03 21:23:48 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_pointer(unsigned long n, t_ibb *p)
{
	if (n % 16 > 9)
	{
		p->x = ft_choose_letter(n % 16, 'x');
		p->str[p->size] = p->x;
	}
	else
	{
		p->c = ft_itoa(n % 16);
		p->str[p->size] = *p->c;
		ft_strdel(&p->c);
	}
}

char		*ft_pointer_itoa(unsigned long n)
{
	t_ibb p;

	p.tmp2 = n;
	p.size = 0;
	while (p.tmp2 /= 16)
		p.size++;
	p.i = p.size + 1;
	p.str = ft_strnew(p.size + 1);
	while (n >= 0 && p.size > -1)
	{
		ft_pointer(n, &p);
		p.size--;
		n /= 16;
	}
	p.str[p.i] = '\0';
	return (p.str);
}
