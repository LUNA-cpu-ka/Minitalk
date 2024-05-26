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
// void *check_msg(char *msg)
// {
//     int i;
//     i = 0;
//     if(msg[i] > 65 && msg[i] < 90)
//     {
//         while (msg[i])
//             i++;
//     }
    
    
// }
// bool check_dip(char *dip)
// {
//     int i;
//     i = 0;
//     while (dip[i] != '\0')
//     {
//         while (dip[i] < '0' || dip[i] > '9')
//             return false;
//         i++;
//     }

//     return true;
// }

// int main(int ac, char **av)
// {
//     char *dip;
//     // char *message;
//     dip = av[1];
//     int pad;
//     pad = getpid();
//     printf("this is the pad: %d\n", pad);

//     if (ac != 3)
//         printf("ARGUMENT ERROR 😑");
//     else if( !check_dip(dip))
//         printf("YOU NEED A DIP code  😑");
//     else 
//         printf("Koulchi howa hadak ! ✅");
//     return(0);
// }

#include "minitalk.h"
void send_char(int pid, char c)
{
    for (int i = 0; i < 8; i++)
    {
        if (c & (1 << i))
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(100);  // Sleep for a short period to ensure the signal is processed
    }
}

int main(int argc, char **argv)
{
    // ft_printf("ft_printf raha 5dama:");
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <PID> <message>\n", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);
    char *message = argv[2];

    while (*message)
    {
        send_char(pid, *message);
        message++;
    }
    return 0;
}
