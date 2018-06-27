/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_script.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:53:49 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/22 15:47:13 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"
#include <stdio.h>

static int			create_pty_pair(t_var *var)
{
	if ((var->master = ft_posix_openpt(O_RDWR)) == -1)
		return (ft_exit());
	if (ft_grantpt(var->master) == -1)
		return (ft_exit());
	if (ft_ptsname(var->master) == EXIT_FAILURE)
		return (ft_exit());
	if (ft_unlockpt(var->master) == -1)
		return (ft_exit());
	if ((var->slave = open(var->ft_ptsbuf, O_RDWR)) == -1)
		return (ft_exit());
	return (EXIT_SUCCESS);
}

int					ft_script(t_var *var)
{
	pid_t		pid;
	int			ret;

	ret = EXIT_SUCCESS;
	if (create_pty_pair(var) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	signal(SIGCHLD, ft_sigchld);
	if ((pid = fork()) == -1)
		return (ft_exit());
	else if (!pid)
	{
		close(var->master);
		close(var->file_fd);
		ret = child(var);
	}
	else if (pid)
	{
		close(var->slave);
		ret = father(var);
	}
	return (ret);
}
