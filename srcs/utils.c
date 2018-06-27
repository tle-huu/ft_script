/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 17:10:12 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/22 15:44:20 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

static char		*ft_getenv_env_value(char *string)
{
	while (string && *string && *string != '=')
		string++;
	return (string + 1);
}

char			*ft_getenv(char **env, char *key)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strnequ(key, env[i], ft_strlen(key)))
			return (ft_getenv_env_value(env[i]));
		i++;
	}
	return (NULL);
}

void			usage(void)
{
	write(1, "ft_script: illegal option\n",
				ft_strlen("ft_script: illegal option\n"));
	write(1, "usage: ft_script [-aq] [file [command ...]]\n",
		ft_strlen("usage: ft_script [-aq] [file [command ...]]\n"));
}

int				ft_exit(void)
{
	close(g_var->master);
	close(g_var->slave);
	reset_tty(&(g_var->term));
	return (EXIT_FAILURE);
}

int				ft_end(void)
{
	ft_exit();
	return (end_message());
}
