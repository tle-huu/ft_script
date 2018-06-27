/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pty_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 18:45:07 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/22 15:45:57 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

/*
** The grantpt(), ptsname(), unlockpt(), and posix_openpt()
** functions allow access to pseudo-terminal devices.
** The first three functions accept a file descriptor that references the master
** half of a pseudo-terminal pair.
** this file descriptor is created with posix_openpt().
*/

/*
** grantpt call for cloning pty implementation.
** Change UID and GID of slave pty associated with master pty whose
** fd is provided, to the real UID and real GID of the calling thread.
*/

int				ft_grantpt(int fd)
{
	return (ioctl(fd, TIOCPTYGRANT));
}

/*
** ptsname call for cloning pty implementation.
** NOTE: Returns a pointer to a static buffer, which will be overwritten on
** subsequent calls.
*/

int				ft_ptsname(int fd)
{
	int				error;
	int				retval;
	struct stat		sbuf;

	retval = EXIT_FAILURE;
	error = ioctl(fd, TIOCPTYGNAME, g_var->ft_ptsbuf);
	if (error != -1)
	{
		if (stat(g_var->ft_ptsbuf, &sbuf) == 0)
			retval = EXIT_SUCCESS;
	}
	return (retval);
}

/*
** unlockpt call for cloning pty implementation.
** Unlock the slave pty associated with the master to which fd refers.
*/

int				ft_unlockpt(int fd)
{
	return (ioctl(fd, TIOCPTYUNLK));
}

int				ft_posix_openpt(int flags)
{
	int fd;

	fd = open("/dev/ptmx", flags);
	if (fd >= 0)
		return (fd);
	return (-1);
}
