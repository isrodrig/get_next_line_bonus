/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrodrig <isrodrig@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:37:09 by isrodrig          #+#    #+#             */
/*   Updated: 2023/04/03 16:47:10 by isrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != c && *str != '\0')
		str++;
	if (*str == c)
		return (str);
	else
		return (NULL);
}

char	*ft_strjoin_prepare_s1(char *s1)
{
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	return (s1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*u;

	i = 0;
	s1 = ft_strjoin_prepare_s1(s1);
	if (!s1)
		return (NULL);
	u = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!u)
	{
		free(s1);
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		u[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		u[i++] = s2[j++];
	u[i] = '\0';
	free(s1);
	return (u);
}
