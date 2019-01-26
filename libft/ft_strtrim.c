/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 07:50:54 by nhamid            #+#    #+#             */
/*   Updated: 2018/10/16 07:25:49 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*change(char *dest, char const *s, int i, int j)
{
	int k;

	k = 0;
	while (k < j)
		dest[k++] = s[i++];
	dest[k] = '\0';
	return (dest);
}

static char	*zero(char *dest)
{
	if ((dest = (char*)malloc(1 * sizeof(char))) == NULL)
		return (NULL);
	dest[0] = '\0';
	return (dest);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*dest;

	dest = NULL;
	i = 0;
	if (s == NULL)
		return (NULL);
	j = (ft_strlen(s) - 1);
	if (s[0] == ' ' || s[0] == '\n' || s[0] == '\t')
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
			i++;
	if (s[i] == '\0')
		return (zero(dest));
	else
	{
		while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && s[j] != '\0')
			j--;
		j = j - i + 1;
		if ((dest = (char*)malloc((j + 1) * sizeof(char))) == NULL)
			return (NULL);
		change(dest, s, i, j);
	}
	return (dest);
}
