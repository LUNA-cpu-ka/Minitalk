// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   client.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*All Hallows’ Eve Plus
//    By: saait-si <saait-si@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/05/22 09:42:13 by saait-si          #+#    #+#             */
// /*   Updated: 2024/05/22 10:55:37 by saait-si         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "minitalk.h"
// #include "pri/ft_printf.h"
// int ft_isdigit(char *str)
// {
//     int i;
//     i = 0;
//     while (str[i])
//     {
//         if (str[i] >= '0' && str[i]  <= '9')
//             return (0);
//         i++;
//     }
//     return(1);
// }
// void set_bit(int pid,char byte)
// {
//     int i;
//     i = 0;
//     while (i < 8)
//     {
//         if ((byte >> i) & 1)
//             kill(pid, SIGUSR1);
//         else
//             kill (pid, SIGUSR2);
//         i++;
//     }
// }
// int main(int ac, char *av[])
// {
//     char *mesg;
//     int pid;
//     int i;

//     mesg = av[2];
//     i = 0;
//     pid = atoi(av[1]);

//     if(ac != 3 || !ft_isdigit(av[1]))
//         ft_printf("CHECK YOUR ARGUMENTS 👾");

//     while (mesg[i])
//     {
//         set_bit(pid, mesg[i]);
//         i++;
//     }
//     return(0);
// }

































/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiyari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:37:11 by ktiyari           #+#    #+#             */
/*   Updated: 2024/05/04 16:37:15 by ktiyari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"
int	ft_isdigit(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

void	send_signal(int pid, char byte)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((byte >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(400);
		i--;
	}
}

int	main(int argc, char *argv[])
{
	char	*msg;
	int		pid;
	int		i;

    
	if (argc != 3 || !ft_isdigit(argv[1]))
    {
        ft_printf("CHECK YOUR ARGUMENTS 👾");
    
    }
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	i = 0;
	while (msg[i])
	{
		send_signal(pid, msg[i]);
		i++;
	}
}

