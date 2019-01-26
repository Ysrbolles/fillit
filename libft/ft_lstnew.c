/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 16:57:53 by nhamid            #+#    #+#             */
/*   Updated: 2018/10/15 04:53:22 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*dest;

	dest = NULL;
	dest = malloc(sizeof(t_list));
	if (dest == NULL)
		return (NULL);
	dest->next = NULL;
	if (content == NULL)
	{
		dest->content = NULL;
		dest->content_size = 0;
		return (dest);
	}
	dest->content = (t_list*)malloc(sizeof(t_list) * content_size);
	if (dest->content == NULL)
		return (NULL);
	dest->content = ft_strcpy(dest->content, content);
	dest->content_size = content_size;
	return (dest);
}
