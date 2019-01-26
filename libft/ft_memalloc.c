/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 23:30:02 by nhamid            #+#    #+#             */
/*   Updated: 2018/10/10 16:23:31 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*tab;

	tab = (size_t*)malloc(size * sizeof(size_t));
	if (tab == NULL)
		return (NULL);
	ft_memset(tab, 0, size);
	return (tab);
}
