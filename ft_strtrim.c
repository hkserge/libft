/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:15:00 by khelegbe          #+#    #+#             */
/*   Updated: 2020/12/10 23:36:54 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_set(const char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static char	*ft_new_str(const char *str, int start, int end)
{
	char			*tmp;
	unsigned int	i;
	int				len;

	i = 0;
	len = end - start + 1;
	if (end < 0)
		return (0);
	if (!(tmp = malloc(sizeof(char) * len + 1)))
		return (0);
	while (len > 0)
	{
		tmp[i] = str[start + i];
		i++;
		len--;
	}
	tmp[i] = '\0';
	return (tmp);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_check_set(s1[start], set))
		start++;
	while (ft_check_set(s1[end], set))
		end--;
	return (ft_new_str(s1, start, end));
}
