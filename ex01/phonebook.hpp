/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:59:00 by yususato          #+#    #+#             */
/*   Updated: 2024/08/12 21:04:55 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

class Contact {
    private:
        std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string phone_number;
        std::string darkest_secret;

    public:
    
    Contact() {}
        std::string get_first_name() {
            return first_name;
        }
        std::string get_last_name() {
            return last_name;
        }
        std::string get_nick_name() {
            return nick_name;
        }
        std::string get_phone_number() {
            return phone_number;
        }
        std::string get_darkest_secret() {
            return darkest_secret;
        }
        void set_first_name(const std::string& firstname)
        {
            this->first_name = firstname;
        }
        void set_last_name(const std::string& lastname)
        {
            this->last_name = lastname;
        }
        void set_nick_name(const std::string& nickname)
        {
            this->nick_name = nickname;
        }
        void set_phone_number(const std::string& phonenumber)
        {
            this->phone_number = phonenumber;
        }
        void set_darkest_secret(const std::string& darkestsecret)
        {
            this-> darkest_secret = darkestsecret;
        }
        Contact(std::string first_name, std::string last_name, \
                std::string nick_name,  std::string phone_number, \
                std::string darkest_secret)
            : first_name(first_name), last_name(last_name), nick_name(nick_name),
                phone_number(phone_number), darkest_secret(darkest_secret){}
};

class PhoneBook {
    private:
        int _index;
        Contact _phonebook[8];
        bool    status_flag;
        bool    max_flag;

    public :
        PhoneBook() : _index(0), status_flag(false), max_flag(false) {}
    

    bool    get_status()
    {
        return status_flag;
    }

    void    set_status()
    {
        this->status_flag = true;
        return ;
    }

    void    set_max_flag()
    {
        this->max_flag = true;
        return ;
    }
        
    void ADD(Contact Person) {
        _phonebook[_index] = Person;
        if (_index == 7)
            set_max_flag();
        _index = (_index + 1) % 8;
    }

    std::string ten_strlen(std::string information)
    {
        if (information.length() > 10) {
            return (information.substr(0, 9) + ".");
        }
        else {
            return (std::string(10 - information.length(), ' ') + information);
        }
    }

    void    display()
    {
        int count;
        int index;
        std::string first;
        std::string last;
        std::string nick;    
        
        index = 0;
        if (max_flag == true)
            count = 8;
        else
            count = _index;
        while (index < count)
        {
            std::cout << "index" << index + 1 << "|";
            first = ten_strlen(_phonebook[index].get_first_name());
            last = ten_strlen(_phonebook[index].get_last_name());
            nick = ten_strlen(_phonebook[index].get_phone_number());
            
            std::cout << "first_name:" << first << "|";
            std::cout << "last_name:" << last << "|";
            std::cout << "phone_number:" << nick << std::endl;
            index++;
        }
    }

    void SEARCH(int index)
    {
        int         count;
        std::string first;
        std::string last;
        std::string nick;

        if (max_flag == true)
            count = 8;
        else
            count = _index;   
        
        if (index < 0 || index >= count) {
            throw std::out_of_range("Index out of range");
        }
        std::cout << "index" << index + 1 << "|";
        first = ten_strlen(_phonebook[index].get_first_name());
        last = ten_strlen(_phonebook[index].get_last_name());
        nick = ten_strlen(_phonebook[index].get_phone_number());
            
        std::cout << "first_name:" << first << "|";
        std::cout << "last_name:" << last << "|";
        std::cout << "phone_number:" << nick << std::endl;
    }

    void    EXIT() {
        exit(0);
    }
};

# endif