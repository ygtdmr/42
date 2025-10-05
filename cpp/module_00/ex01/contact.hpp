/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:32:54 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/05 16:20:47 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

# define CONTACT_NAME_MAX 10

class Contact
{
public:
	Contact();
	Contact
	(
	const std::string	&firstName,
	const std::string	&lastName,
	const std::string	&nickname,
	const std::string	&phoneNumber,
	const std::string	&darkestSecret
	);
	const std::string	&getFirstName() const;
	const std::string	&getLastName() const;
	const std::string	&getNickname() const;
	const std::string	&getPhoneNumber() const;
	const std::string	&getDarkestSecret() const;
private:
	std::string	firstName_;
	std::string	lastName_;
	std::string	nickname_;
	std::string	phoneNumber_;
	std::string	darkestSecret_;
};

#endif
