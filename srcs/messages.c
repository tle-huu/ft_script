/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 10:56:54 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/22 16:29:18 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

int				start_message(void)
{
	struct timeval		temps;

	if ((g_var->file_fd = open(g_var->filename ? g_var->filename : "typescript",
			O_WRONLY | O_CREAT | (O_APPEND * g_var->a), 0644)) == -1
				|| gettimeofday(&temps, NULL) == -1)
		return (ft_exit());
	if (!(g_var->q))
	{
		ft_putstr_fd("Script started, outputfile is ", STDOUT_FILENO);
		if (g_var->filename)
			ft_putendl_fd(g_var->filename, STDOUT_FILENO);
		else
			ft_putendl_fd("typescript", STDOUT_FILENO);
		ft_putstr_fd("Script started on ", g_var->file_fd);
		ft_putstr_fd(ctime(&temps.tv_sec), g_var->file_fd);
	}
	return (EXIT_SUCCESS);
}

int				end_message(void)
{
	struct timeval		temps;

	if (gettimeofday(&temps, NULL) == -1)
		return (ft_exit());
	if (!(g_var->q))
	{
		ft_putstr_fd("\nScript done, outputfile is ", STDOUT_FILENO);
		if (g_var->filename)
			ft_putendl_fd(g_var->filename, STDOUT_FILENO);
		else
			ft_putendl_fd("typescript", STDOUT_FILENO);
		ft_putstr_fd("\nScript done on ", g_var->file_fd);
		ft_putstr_fd(ctime(&temps.tv_sec), g_var->file_fd);
	}
	close(g_var->file_fd);
	return (EXIT_SUCCESS);
}
