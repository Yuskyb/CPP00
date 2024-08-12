/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:50:07 by yususato          #+#    #+#             */
/*   Updated: 2024/07/31 20:42:34 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cout <<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
        return (0);
    }
    for (int i = 1; av[i] != NULL; i++)
    {
        for (int j = 0; av[i][j] != '\0'; j++)
        {
            std::cout << (char)toupper(av[i][j]);
        }
        std::cout << " ";
    }
    std::cout << std::endl;
    return (0);
}