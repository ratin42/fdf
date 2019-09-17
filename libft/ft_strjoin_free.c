/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 14:06:30 by ratin             #+#    #+#             */
/*   Updated: 2018/11/26 11:58:33 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strjoin_free(char const *s1, char const *s2, int string)
{
	char	*str;

	if (s1 && s2)
	{
		if ((str = (char *)ft_memalloc(sizeof(char) *
		(ft_strlen(s1) + ft_strlen(s2) + 1))) == NULL)
		{
			free((void *)s1);
			free((void *)s2);
			return (0);
		}
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
		if (string == 1)
			free((void *)s1);
		else if (string == 2)
			free((void *)s2);
		else if (string == 3)
		{
			free((void *)s1);
			free((void *)s2);
		}
		return (str);
	}
	return (NULL);
}
