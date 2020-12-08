/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:15:00 by khelegbe          #+#    #+#             */
/*   Updated: 2020/12/08 21:21:17 by khelegbe         ###   ########.fr       */
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
	char	*tmp;
	int		size;

	if (end < start)
		size = 1;
	else
		size = (end - start) + 2;
	if (!(tmp = malloc(sizeof(char) * size)))
		return (0);
	if (end < start)
		tmp[size] = '\0';
	else
		ft_strlcpy(tmp, (char *)str + start, size);
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
