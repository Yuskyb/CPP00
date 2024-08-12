/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:58:56 by yususato          #+#    #+#             */
/*   Updated: 2024/08/12 21:43:27 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void    search_phone(PhoneBook& phonebook, Contact& contact)
{
    std::string input;
    int number;
    
    if (phonebook.get_status() == false)
        return ;
    phonebook.display();
    std::cout << "コマンドを入力してください: ";
    std::getline(std::cin, input);
    std::stringstream ss(input);
    ss >> number;
    if (ss.fail() || !ss.eof())
    {
        std::cerr << "無効な入力です" << std::endl;
        return;
    }
    phonebook.SEARCH(number);
}

bool    chack_valid(std::string str)
{
    std::wstring_convert::<std::codecvt_utf8<wchar_t>> converter;
    std::wstring wstr = converter.from_bytes(str);
    
}

void    add_phone(PhoneBook& phonebook, Contact& contact)
{
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
    std::string darkest_secret;
    
    std::cout<< "first_nameを入力してください" <<std::endl;
    std::getline(std::cin, first_name);
    std::cout<< "last_nameを入力してください" <<std::endl;
    std::getline(std::cin, last_name);
    std::cout<< "nick_nameを入力してください" <<std::endl;
    std::getline(std::cin, nick_name);
    std::cout<< "phone_numberを入力してください" <<std::endl;
    std::getline(std::cin, phone_number);
    std::cout<< "darkest_secretを入力してください" <<std::endl;
    std::getline(std::cin, darkest_secret);
    std::cout<< "darkest_stを入力してください" <<std::endl;
    
    if (first_name.empty() || last_name.empty() || nick_name.empty() \
        || phone_number.empty() || darkest_secret.empty())
        return ;
    if (std::all_of(phone_number.begin(), phone_number.end(), ::isdigit))
        return ;
    if (std::all_of(first_name.begin(), first_name.end(), ::isalpha && check_valid(first_name)))
        return ;
    contact = Contact(first_name, last_name, nick_name, phone_number, darkest_secret);
    phonebook.ADD(contact);
    phonebook.set_status();
}

int main() {
    PhoneBook phonebook;
    Contact contact;
    std::string s;
    
    while (1) {
        std::cout << "コマンドを入力してください: ";
        std::getline(std::cin, s);
        if (s == "ADD")
            add_phone(phonebook, contact);
        else if (s == "search")
            search_phone(phonebook, contact);
        else if (s == "EXIT")
            exit(0);
        else
            continue ;
    }
}
