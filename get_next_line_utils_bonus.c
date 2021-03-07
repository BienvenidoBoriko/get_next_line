/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboriko- <bboriko-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:48:39 by bboriko-          #+#    #+#             */
/*   Updated: 2021/02/28 20:46:11 by bboriko-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char *ref;

	ref = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ref);
}

int		ft_strlen(const char *str)
{
	int len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*ft_strdup(const char *str1)
{
	char *ref;

	ref = malloc(ft_strlen(str1) * sizeof(char) + 1);
	if (ref == NULL)
		return (NULL);
	else
		return (ft_strcpy(ref, str1));
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;
	int		t_len;
	int		s_len;

	if (s1 != NULL && s2 != NULL)
	{
		t_len = ft_strlen(s1);
		s_len = ft_strlen(s2);
		join = (char *)malloc(((t_len + s_len) * sizeof(char)) + 1);
		if (join == NULL)
			return (NULL);
		join[0] = '\0';
		ft_strcat(join, s1);
		ft_strcat(join, s2);
		return (join);
	}
	else if (s1 == NULL)
		return ((char*)s2);
	else
		return ((char*)s1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ref;
	size_t	cont;

	if (s == NULL)
		return (NULL);
	cont = 0;
	if (((int)start) > ft_strlen(s))
	{
		ref = ft_substr("\0", 0, 1);
		return (ref);
	}
	if (!(ref = malloc(len * sizeof(char) + 1)))
		return (NULL);
	while (cont < len)
	{
		ref[cont] = s[start + cont];
		cont++;
	}
	ref[cont] = '\0';
	return (ref);
}

char	*ft_strcat(char *dest, const char *src)
{
	char	*c_s1;

	c_s1 = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (c_s1);
}
