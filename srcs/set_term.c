/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_term.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:33:54 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/22 15:27:06 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

int		reset_tty(struct termios *tty)
{
	if (ioctl(STDIN_FILENO, TIOCSETA, tty) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int		set_tty_raw(struct termios *previous_term)
{
	struct termios		temp;

	if (ioctl(0, TIOCGETA, &temp) == -1)
		return (ft_exit());
	*previous_term = temp;
	temp.c_lflag &= ~(ICANON | ECHO | ISIG | IEXTEN);
	temp.c_iflag &= ~(IXON | INLCR | IGNCR | ICRNL);
	temp.c_oflag &= ~OPOST;
	temp.c_cc[VMIN] = 1;
	temp.c_cc[VTIME] = 0;
	if (ioctl(0, TIOCSETAF, &temp) == -1)
		return (ft_exit());
	return (EXIT_SUCCESS);
}
