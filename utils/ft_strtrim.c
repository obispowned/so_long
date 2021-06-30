/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:27:55 by agutierr          #+#    #+#             */
/*   Updated: 2021/06/30 20:17:22 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/utils.h"

static	char	*ft_substr2(char *s, int start, int len)
{
	int		i;
	char		*result;
	int		size;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(0));
	size = (ft_strlen(s + start) > len) ? len : ft_strlen(s + start);
	if (!(result = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size && *s)
	{
		result[i] = s[i + start];
		i++;
	}
	result[i] = 0;
	return (result);
}

char			*ft_strtrim(char *s1, char *set)
{
	char		*ret;
	size_t		len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (len && ft_strchr(set, s1[len]))
		len--;
	ret = ft_substr2(s1, 0, len + 1);
	return (ret);
}
