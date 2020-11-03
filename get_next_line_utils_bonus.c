/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 15:41:36 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/09/17 17:00:12 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t		i;
	char		*s2;

	i = 0;
	if (!(s2 = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s2;
	unsigned int	i;
	size_t			j;

	i = 0;
	j = 0;
	if (!(s2 = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < start)
		i++;
	while (j < len)
	{
		s2[j] = s[i];
		j++;
		i++;
	}
	s2[j] = '\0';
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(str = (char*)malloc(sizeof(*s1) * ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[i] != '\0')
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	sym;

	str = (char*)s;
	sym = (char)c;
	while (*str)
	{
		if (*str == sym)
			return (str);
		str++;
	}
	if (sym == '\0')
		return (str);
	return (NULL);
}
