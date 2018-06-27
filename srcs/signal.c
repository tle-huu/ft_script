/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 08:58:52 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/22 16:21:18 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

void			ft_sigwinch(int sig)
{
	struct winsize		ws;

	sig = 0;
	if (ioctl(0, TIOCGWINSZ, &ws) != -1)
		ioctl(g_var->master, TIOCSWINSZ, &ws);
}

void			ft_sigchld(int sig)
{
	sig = 0;
	ft_end();
	exit(-1);
}

void			ft_sigusr1(int sig)
{
	sig = 0;
	ft_end();
	exit(-1);
}
