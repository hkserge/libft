/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:15:00 by khelegbe          #+#    #+#             */
/*   Updated: 2020/12/08 16:44:04 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_set(char c, const char *set)
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
	char	*tmp;

	if (end < start)
	{
		if (!(tmp = malloc(sizeof(str) * 1)))
			return (0);
		tmp[0] = '\0';
		return (tmp);
	}
	if (!(tmp = malloc(sizeof(str) * (end - start) + 2)))
		return (0);
	ft_strlcpy(tmp, str + start, (end - start) + 2);
	return (tmp);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int end;

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
