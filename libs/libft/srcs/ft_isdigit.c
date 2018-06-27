/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 21:40:31 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/12 19:15:09 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isdigit(int c)
{
	return (c <= '9' && c >= '0');
}

int		ft_isnumber(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str && str[i])
	{
		if (str[0] != '-' && !ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
