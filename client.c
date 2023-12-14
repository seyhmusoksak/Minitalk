/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 00:48:30 by soksak            #+#    #+#             */
/*   Updated: 2023/12/15 01:06:39 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		result;
	int		sign;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i]) && (str[i] == '\n' || str[i] == '\t' || str[i] == '\f'
			|| str[i] == '\v' || str[i] == '\r' || str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

void	pushsignal(int pid, char c)
{
	int	limit;

	limit = 0;
	while (limit < 8)
	{
		if ((c >> limit) & 1)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		limit++;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			pushsignal(pid, argv[2][i]);
			i++;
		}
	}
	else
		write(1, "An error occured", 16);
}
