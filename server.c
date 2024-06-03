/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:47:10 by saait-si          #+#    #+#             */
/*   Updated: 2024/05/27 17:54:28 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	function(int sig_end)
{
	static int	bit;
	static char	character;

	character <<= 1;
	if (sig_end == SIGUSR1)
		character |= 1;
	bit++;
	
	if (character && bit == 8) // !c 
	{
		write(1, &character, 1);   //write(1,\n,1)
		bit = 0;                  // bit = 0;
		character = 0;// c = 0
	}
}

int	main(void)
{
	int		pid;

	pid = getpid();
	ft_printf("YOUR SERVER PID'S: %d\n", pid);
	ft_printf("Please wait for client to write the message for you 👻\n");
	signal(SIGUSR1, function);
	signal(SIGUSR2, function);
	while (1)
	{
		pause();
	}
	return (0);
}
