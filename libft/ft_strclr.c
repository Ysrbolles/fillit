/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:08:09 by nhamid            #+#    #+#             */
/*   Updated: 2018/10/10 17:21:43 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	char	i;

	i = '\0';
	if (s != NULL)
	{
		while (*s != '\0')
		{
			*s = i;
			s++;
		}
	}
}