/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 01:46:52 by nhamid            #+#    #+#             */
/*   Updated: 2018/10/17 22:58:46 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tab;
	int		len;

	len = (int)size;
	tab = (char*)malloc((len + 1) * sizeof(char));
	if (tab == NULL)
		return (NULL);
	ft_memset(tab, 0, len + 1);
	return (tab);
}
