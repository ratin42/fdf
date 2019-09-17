/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:19:44 by saouas            #+#    #+#             */
/*   Updated: 2018/11/21 20:20:59 by saouas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strnew(size_t size)
{
	size_t		i;
	char		*ret_str;

	i = 0;
	if (!(ret_str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size + 1)
	{
		ret_str[i] = '\0';
		i++;
	}
	return (ret_str);
}
