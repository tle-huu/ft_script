/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 09:08:25 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/22 16:00:16 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

static int		stdin_to_pty(t_var *var)
{
	char		buf[BUF_SIZE];
	int			reader;

	if ((reader = read(STDIN_FILENO, buf, BUF_SIZE)) < 0)
		return (EXIT_SUCCESS);
	if (write(var->master, buf, reader) != reader)
		return (ft_exit());
	return (EXIT_SUCCESS);
}

static int		pty_to_stdout_and_file(t_var *var)
{
	char		buf[BUF_SIZE];
	int			reader;

	if ((reader = read(var->master, buf, BUF_SIZE)) < 0)
		return (EXIT_SUCCESS);
	if (write(STDOUT_FILENO, buf, reader) != reader)
		return (ft_exit());
	if (write(var->file_fd, buf, reader) != reader)
		return (ft_exit());
	return (EXIT_SUCCESS);
}

int				father(t_var *var)
{
	fd_set		in_fds;

	if (set_tty_raw(&(var->term)) == EXIT_FAILURE)
		return (ft_exit());
	signal(SIGWINCH, ft_sigwinch);
	signal(SIGUSR1, ft_sigusr1);
	ft_sigwinch(0);
	while (1)
	{
		FD_ZERO(&in_fds);
		FD_SET(STDIN_FILENO, &in_fds);
		FD_SET(var->master, &in_fds);
		if (select(var->master + 1, &in_fds, NULL, NULL, NULL) == -1)
			return (ft_exit());
		if (FD_ISSET(STDIN_FILENO, &in_fds))
			if (stdin_to_pty(var) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		if (FD_ISSET(var->master, &in_fds))
			if (pty_to_stdout_and_file(var) == EXIT_FAILURE)
				return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int				child(t_var *var)
{
	char		*argv[3];

	if (setsid() == -1)
		return (ft_exit());
	signal(SIGUSR1, ft_sigusr1);
	if (ioctl(var->slave, TIOCSCTTY, NULL) == -1)
		return (ft_exit());
	if (dup2(var->slave, STDIN_FILENO) != STDIN_FILENO
					|| dup2(var->slave, STDOUT_FILENO) != STDOUT_FILENO
					|| dup2(var->slave, STDERR_FILENO) != STDERR_FILENO)
		return (ft_exit());
	if (close(var->slave) == -1)
		return (ft_exit());
	argv[0] = var->shell;
	argv[1] = "-i";
	argv[2] = 0;
	if ((execve(var->shell, argv, var->env)) == -1)
		return (ft_exit());
	return (EXIT_SUCCESS);
}
