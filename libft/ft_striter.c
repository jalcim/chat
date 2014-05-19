/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbahri <nbahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:01:48 by nbahri            #+#    #+#             */
/*   Updated: 2013/12/01 16:08:56 by nbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_striter(char *s, void (*f) (char *))
{
	int	i;

	i = 0;
	while (s[i])
		f(&s[i++]);
}
