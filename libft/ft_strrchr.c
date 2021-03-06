/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbahri <nbahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:38:32 by nbahri            #+#    #+#             */
/*   Updated: 2014/03/22 05:46:29 by nbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	int		i;

	i = 0;
	while (s[i + 1])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}
