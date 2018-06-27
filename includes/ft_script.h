/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_script.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:41:02 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/22 16:32:33 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCRIPT_H
# define FT_SCRIPT_H

# include "stdio.h"
# include "libft.h"
# include <termios.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <fcntl.h>
# include <sys/select.h>
# include <sys/time.h>
# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include <sys/stat.h>
# include <errno.h>

# define BUF_SIZE	128
# define MAX_SNAME	1000

typedef struct	s_var
{
	int					q;
	int					a;
	int					r;
	int					p;
	int					master;
	int					slave;
	pid_t				childpid;
	int					file_fd;
	char				*filename;
	char				ft_ptsbuf[BUF_SIZE];
	char				**env;
	char				*pwd;
	char				*shell;
	struct termios		term;
}				t_var;

t_var			*g_var;

/*
** PARSING
*/

int				parser(int argc, char **argv, t_var *var);

/*
** SET TERMINAL SETTINGS
*/
int				set_tty_raw(struct termios *prevtermios);
int				reset_tty(struct termios *tty);

/*
** FORKING
*/

/*
** SIGNAL HANDLING
*/
void			ft_sigwinch(int sig);
void			ft_sigchld(int sig);
void			ft_sigusr1(int sig);

/*
** FT_SCRIPT = DRIVER PROGRAM
*/
int				ft_script(t_var *var);

/*
** FORK
*/
int				father(t_var *var);
int				child(t_var *var);

/*
** UTILS
*/
char			*ft_getenv(char **env, char *key);
void			usage(void);
int				ft_exit(void);
int				ft_end(void);

/*
** PSEUDO TERMINAL ACCESS FUNCTIONS
*/
int				ft_posix_openpt(int flags);
int				ft_grantpt(int fd);
int				ft_ptsname(int fd);
int				ft_unlockpt(int fd);

/*
** MESSAGES
*/
int				start_message(void);
int				end_message(void);

#endif
