/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*All Hallows’ Eve Plus
   By: saait-si <saait-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:42:13 by saait-si          #+#    #+#             */
/*   Updated: 2024/05/22 10:55:37 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minitalk.h"
// int	ft_isdigit(char *str)
// {
// 	while (*str)
// 	{
// 		if (*str < '0' || *str > '9')
// 			return (0);
// 		str++;
// 	}
// 	return (1);
// }

// void	send_signal(int pid, char c)
// {
// 	int	i;

// 	i = 7;
// 	while (i >= 0)
// 	{
// 		if ((c >> i) & 1)
// 			kill(pid, SIGUSR1);
// 		else
// 			kill(pid, SIGUSR2);
// 		usleep(400);
// 		i--;
// 	}
// }

// int	main(int argc, char *argv[])
// {
// 	char	*msg;
// 	int		pid;
// 	int		i;

// 	if (argc != 3 || !ft_isdigit(argv[1]))
// 	{
// 		printf("\nError accured! Either too muh arguments or invalid PID\n");
// 		return (0);
// 	}
// 	pid = atoi(argv[1]);
// 	msg = argv[2];
// 	i = 0;
// 	while (msg[i])
// 	{
// 		send_signal(pid, msg[i]);
// 		i++;
// 	}
// }









#include "minitalk.h"
#include "pri/ft_printf.h"

int main()
{
    // if (argc == 3)
    // {
    //     printf("Dyalhom");
    // }
    // else
        printf("testos");
}






























// int main
// check how many args you have they have to be just 3 of them 
// if there is more or less return a perror
// check if the arg[1] is number 
// store the masssage in arg[2] of the user
// create a function that take the 2 or 3 parameter as you want to send the message and crept it

























































