/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileManager.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:46:06 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/10 06:58:17 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileManager.hpp"

FileManager::FileManager()
{
	content_ = new std::string;
}

FileManager::~FileManager()
{
	if (file_in_.is_open())
		file_in_.close();
	if (file_out_.is_open())
		file_out_.close();
	delete content_;
}

void	FileManager::setInOutName( const std::string &in, const std::string &out )
{
	filename_in_ = in;
	filename_out_ = out;
}

bool	FileManager::read( void )
{
	char	buffer[1024];

	if (file_in_.is_open())
		file_in_.close();
	file_in_.open(filename_in_.c_str(), std::ios_base::in);
	if (file_in_.fail())
		return (false);
	while (!file_in_.eof())
	{
		file_in_.read(buffer, 1024);
		content_->append(buffer, file_in_.gcount());
	}
	return (file_in_.eof() || file_in_.fail());
}

bool	FileManager::write( void )
{
	if (file_out_.is_open())
		file_out_.close();
	file_out_.open(filename_out_.c_str(), std::ios_base::out);
	if (file_out_.fail())
		return (false);
	file_out_.write(content_->c_str(), content_->size());
	return (!file_out_.fail());
}

bool	FileManager::replace( const std::string &from, const std::string &to )
{
	size_t		i_start;
	size_t		i_found;
	std::string	*str;

	if (!read() || from.empty())
		return (false);
	i_start = 0;
	i_found = 0;
	str = new std::string;
	while (1)
	{
		i_found = content_->find(from, i_start);
		if (i_found == std::string::npos)
		{
			*str += content_->substr(i_start);
			break ;
		}
		else
			*str += content_->substr(i_start, i_found - i_start);
		*str += to;
		i_start = i_found + from.size();
	}
	delete content_;
	content_ = str;
	return (write());
}
