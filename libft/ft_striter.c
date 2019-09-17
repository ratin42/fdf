/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:49:54 by saouas            #+#    #+#             */
/*   Updated: 2018/11/21 20:18:03 by saouas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_striter(char *s, void (*f)(char *))
{
	size_t i;

	i = 0;
	if (!s)
		return ;
	if (s && f)
	{
		while (s[i] != '\0')
		{
			f(&s[i]);
			i++;
		}
	}
}
