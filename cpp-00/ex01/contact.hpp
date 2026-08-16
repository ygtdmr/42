/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:32:54 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/06 06:32:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

# define CONTACT_NAME_MAX 10

class Contact
{
public:
	Contact( void );
	Contact
	(
	const std::string	&firstName,
	const std::string	&lastName,
	const std::string	&nickname,
	const std::string	&phoneNumber,
	const std::string	&darkestSecret
	);
	const std::string	&getFirstName( void ) const;
	const std::string	&getLastName( void ) const;
	const std::string	&getNickname( void ) const;
	const std::string	&getPhoneNumber( void ) const;
	const std::string	&getDarkestSecret( void ) const;
private:
	std::string	firstName_;
	std::string	lastName_;
	std::string	nickname_;
	std::string	phoneNumber_;
	std::string	darkestSecret_;
};

#endif
