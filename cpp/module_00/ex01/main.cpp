/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 06:22:31 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/04 06:08:16 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <cstdlib>

static void	exit_phonebook()
{
	if (std::cin.eof())
		std::cout << std::endl;	
	std::cout << "exiting..." << std::endl;
	exit(0);
}

static std::string	get_contact_field(const char *name, bool isNumber)
{
	std::string	line;

	while (line.empty())
	{
		std::cout << "enter " << name << ": ";
		if (!std::getline(std::cin, line))
			exit_phonebook();
		else if (line.empty())
			std::cout << name << " should not empty." << std::endl;
		else if(isNumber)
		{
			for (size_t i = 0; line[i]; i++)
			{
				if (!isdigit(line[i]))
				{
					std::cout << name << " should be only numbers." << std::endl;
					line = "";
					break ;
				}
			}
		}
	}
	return (line);
}

static void	table_put_name(const char *name)
{
	int		blen;
	int		len;
	int		sp;
	bool	limit;

	len = 0;
	blen = 0;
	limit = false;
	while (name[blen] && len < (CONTACT_NAME_MAX - 1))
	{
		blen += mblen(name + blen, MB_CUR_MAX);
		len++;
		if (len == 9)
			limit = true;
	}
	sp = CONTACT_NAME_MAX - len;
	while (!limit && sp--)
		std::cout << " ";
	std::cout << std::string(name, blen);
	if (limit)
		std::cout << ".";
}

static void prompt_search(PhoneBook *phonebook)
{
	int			index;
	int			lenArrContact;
	std::string	line;
	Contact		*arrContact;

	std::cout << "enter index: ";
	if (!std::getline(std::cin, line))
		exit_phonebook();
	else if (line.empty())
		std::cout << "index should not empty." << std::endl;
	else
	{
		for (size_t i = 0; line[i]; i++)
		{
			if (!isdigit(line[i]))
			{
				std::cout << "index should be only numbers." << std::endl;
				return ;
			}
		}
		lenArrContact = phonebook->getLenArrContact();
		index = std::atoi(line.c_str());
		if (index > (lenArrContact - 1))
			std::cout << "entered wrong index." << std::endl;
		else
		{
			arrContact = phonebook->getArrContact();
			std::cout << "First Name: " << arrContact[index].getFirstName() << std::endl;
			std::cout << "Last Name: " << arrContact[index].getLastName() << std::endl;
			std::cout << "Nickname: " << arrContact[index].getNickname() << std::endl;
			std::cout << "Phone Number: " << arrContact[index].getPhoneNumber() << std::endl;
			std::cout << "Darkest Secret: " << arrContact[index].getDarkestSecret() << std::endl;
		}
	}
}

static void	handle_search(PhoneBook *phonebook)
{
	int		lenArrContact;
	Contact	contact;
	Contact	*arrContact;

	lenArrContact = phonebook->getLenArrContact();
	if (!lenArrContact)
	{
		std::cout << "phonebook is empty." << std::endl;
		return ;
	}
	arrContact = phonebook->getArrContact();
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	for (int i = 0; i < lenArrContact; i++)
	{
		contact = arrContact[i];
		std::cout << "|         " << i << "|";
		table_put_name(contact.getFirstName().c_str());
		std::cout << "|";
		table_put_name(contact.getLastName().c_str());
		std::cout << "|";
		table_put_name(contact.getNickname().c_str());
		std::cout << "|" << std::endl;
		std::cout << "|-------------------------------------------|" << std::endl;
	}
	prompt_search(phonebook);
}

static void	handle_prompt(PhoneBook *phonebook, std::string prompt)
{
	if (prompt == "ADD")
		phonebook->addContact
		(
			get_contact_field("darkest secret", false),
			get_contact_field("phone number", true),
			get_contact_field("nickname", false),
			get_contact_field("last name", false),
			get_contact_field("first name", false)
		);
	else if (prompt == "SEARCH")
		handle_search(phonebook);
	else if (prompt == "EXIT")
		exit_phonebook();
	else
		std::cout << "entered wrong prompt, please try again." << std::endl;
}

int	main(void)
{
	PhoneBook	phonebook;
	std::string	line;

	setlocale(LC_ALL, "");
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
