/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 00:48:32 by soksak            #+#    #+#             */
/*   Updated: 2023/12/11 02:02:44 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	charHandler(int signum)
{
	static int i = 0;
	static char c = 0;
	if (signum == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	printf("%d", signum);
}

int main()
{
	signal(SIGUSR1, charHandler);
	signal(SIGUSR2, charHandler);
	printf("Server pid = %d\n", getpid());
	while(1)
	{
		pause();
	}
}
