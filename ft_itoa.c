/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 18:22:40 by khelegbe          #+#    #+#             */
/*   Updated: 2020/12/15 18:43:58 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_str_rev(const char *s)
{
	char	*dest;
	size_t	len;

	len = ft_strlen(s);
	if (!(dest = malloc(sizeof(char) * (len + 1))))
		return (0);
	dest[len] = '\0';
	while (len--)
		dest[len] = *s++;
	return (dest);
}

static char		*ft_putnbr(int nb)
{
	long int	nbr;
	char		*str;

	if (!(str = malloc(sizeof(char) * 2)))
		return (0);
	str[1] = '\0';
	nbr = nb;
	if (nbr >= 10)
	{
		str[0] = nbr % 10 + '0';
		return (str);
	}
	if (nbr < 10)
	{
		str[0] = nbr % 10 + '0';
		return (str);
	}
	return (0);
}

char			*ft_itoa(int n)
{
	char	*dest;
	int		nb;

	nb = n;
	if (!(dest = malloc(sizeof(char) * 1)))
		return (0);
	if (nb == -2147483648)
		return (dest = ft_strjoin(dest, "-2147483648"));
	if (nb == 2147483647)
		return (dest = ft_strjoin(dest, "2147483647"));
	ft_strlcpy(dest, "", 2);
	if (nb == 0)
		dest = ft_strjoin(dest, "0");
	if (nb < 0)
		nb = nb * -1;
	while (nb)
	{
		dest = ft_strjoin(dest, ft_putnbr(nb));
		nb = nb / 10;
	}
	if (n < 0)
		dest = ft_strjoin(dest, "-");
	return (ft_str_rev(dest));
}
