/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 00:48:32 by soksak            #+#    #+#             */
/*   Updated: 2023/12/12 14:15:28 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	charhandler(int signum)
{
	static int		i = 0;
	static char		c = 0;

	if (signum == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	signal(SIGUSR1, charhandler);
	signal(SIGUSR2, charhandler);
	ft_printf("Server Pid = %d\n", pid);
	while (1)
	{
		pause();
	}
}
