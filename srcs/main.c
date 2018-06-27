/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:54:57 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/22 15:46:48 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_script.h"

static int		init_var(t_var *var, char **env)
{
	if (!var || !env)
		return (EXIT_FAILURE);
	var->master = 0;
	var->slave = 0;
	var->q = 0;
	var->a = 0;
	var->file_fd = 0;
	ft_bzero(var->ft_ptsbuf, BUF_SIZE);
	var->env = env;
	var->filename = NULL;
	var->pwd = ft_getenv(env, "PWD");
	var->shell = ft_getenv(env, "SHELL");
	if (!var->shell)
		var->shell = "/bin/sh";
	return (EXIT_SUCCESS);
}

int				main(int argc, char **argv, char **env)
{
	t_var		var;

	if (init_var(&var, env) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	g_var = &var;
	if (parser(argc, argv, &var) == EXIT_FAILURE)
		return (ft_exit());
	if (start_message() == EXIT_FAILURE)
		return (ft_exit());
	if (ft_script(&var) == EXIT_SUCCESS)
		return (ft_end());
	return (ft_exit());
}
