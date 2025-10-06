/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 06:22:31 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/06 17:46:01 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <cstdlib>

static void	exit_phonebook( void )
{
	if (std::cin.eof())
		std::cout << std::endl;	
	std::cout << "exiting..." << std::endl;
	std::exit(0);
}

static bool	str_isascii( std::string str )
{
	const char	*c_str;

	c_str = str.c_str();
	while (*c_str)
	{
		if ((unsigned char)*c_str++ > 127)
			return (false);
	}
	return (true);
}

static bool	str_isdigit( std::string str )
{
	for (size_t i = 0; str[i]; i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

static std::string	get_contact_field( const char *name, char type )
{
	std::string	line;

	while (line.empty())
	{
		std::cout << "enter " << name << ": ";
		if (!std::getline(std::cin, line))
			exit_phonebook();
		else if (line.empty())
			std::cout << name << " should not empty." << std::endl;
		else if(type == 'd' && !str_isdigit(line))
		{
			std::cout << name << " should be only numbers." << std::endl;
			line = "";
		}
		else if (type == 'a' && !str_isascii(line))
		{
			std::cout << name << " should be only ASCII value." << std::endl;
			line = "";
		}
	}
	return (line);
}

static void	table_put_name( std::string name )
{
	int		len;
	int		sp;
	bool	limit;

	len = name.length();
	limit = (len > CONTACT_NAME_MAX);
	sp = (CONTACT_NAME_MAX - len);
	while (!limit && sp--)
		std::cout << " ";
	if (len > CONTACT_NAME_MAX)
		len = (CONTACT_NAME_MAX - 1);
	std::cout << name.substr(0, len);
	if (limit)
		std::cout << ".";
}

static void prompt_search( PhoneBook *phonebook )
{
	int			index;
	std::string	line;
	Contact		*contact;

	std::cout << "enter index: ";
	if (!std::getline(std::cin, line))
		exit_phonebook();
	else if (line.empty())
		std::cout << "index should not empty." << std::endl;
	else if (!str_isdigit(line))
		std::cout << "index should be only numbers." << std::endl;
	else
	{
		index = std::atoi(line.c_str());
		contact = phonebook->getContact(index);
		if (!contact)
			std::cout << "entered wrong index." << std::endl;
		else
		{
			std::cout << "First Name: " << contact->getFirstName() << std::endl;
			std::cout << "Last Name: " << contact->getLastName() << std::endl;
			std::cout << "Nickname: " << contact->getNickname() << std::endl;
			std::cout << "Phone Number: " << contact->getPhoneNumber() << std::endl;
			std::cout << "Darkest Secret: " << contact->getDarkestSecret() << std::endl;
		}
	}
}

static void	handle_add( PhoneBook *phonebook )
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

	firstName = get_contact_field("first name", 'a');
	lastName = get_contact_field("last name", 'a');
	nickname = get_contact_field("nickname", 'a');
	phoneNumber = get_contact_field("phone number", 'd');
	darkestSecret = get_contact_field("darkest secret", 0);
	phonebook->addContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
}

static void	handle_search( PhoneBook *phonebook )
{
	int		lenArrContact;
	Contact	*contact;

	lenArrContact = phonebook->getLenArrContact();
	if (!lenArrContact)
	{
		std::cout << "phonebook is empty." << std::endl;
		return ;
	}
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	for (int i = 0; i < lenArrContact; i++)
	{
		contact = phonebook->getContact(i);
		std::cout << "|         " << i << "|";
		table_put_name(contact->getFirstName());
		std::cout << "|";
		table_put_name(contact->getLastName());
		std::cout << "|";
		table_put_name(contact->getNickname());
		std::cout << "|" << std::endl;
		std::cout << "|-------------------------------------------|" << std::endl;
	}
	prompt_search(phonebook);
}

static void	handle_prompt( PhoneBook *phonebook, std::string prompt )
{
	if (prompt == "ADD")
		handle_add(phonebook);
	else if (prompt == "SEARCH")
		handle_search(phonebook);
	else if (prompt == "EXIT")
		exit_phonebook();
	else
		std::cout << "entered wrong prompt, please try again." << std::endl;
}

int	main( void )
{
	PhoneBook	phonebook;
	std::string	line;

	while (1)
	{
		std::cout << "> ";
		if (!std::getline(std::cin, line))
			exit_phonebook();
		else if (line.empty())
			std::cout << "prompt should not empty." << std::endl;
		else
			handle_prompt(&phonebook, line);
	}
	return (0);
}
