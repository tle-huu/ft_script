/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 17:02:12 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/22 16:42:02 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

static int		compare(char *str, t_var *var)
{
	if (ft_strequ("-q", str))
		var->q = 1;
	else if (ft_strequ("-a", str))
		var->a = 1;
	else if (ft_strequ("-aq", str) || ft_strequ("-qa", str))
	{
		var->q = 1;
		var->a = 1;
	}
	else
		return (0);
	return (1);
}

int				parser(int argc, char **argv, t_var *var)
{
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (compare(argv[i], var))
			continue ;
		else if (argv[i][0] == '-')
		{
			usage();
			return (EXIT_FAILURE);
		}
		else
		{
			var->filename = argv[i];
			if (argv[i + 1])
			{
				usage();
				return (EXIT_FAILURE);
			}
		}
	}
	return (EXIT_SUCCESS);
}
