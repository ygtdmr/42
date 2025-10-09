/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileManager.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/09 16:26:59 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_MANAGER_HPP
# define FILE_MANAGER_HPP

# include <string>
# include <fstream>

class FileManager
{
public:
	FileManager();
	~FileManager();
	void	setInOutName(const std::string &in, const std::string &out);
	bool	replace( const std::string &from, const std::string &to );
private:
	bool	read( void );
	bool	write( void );
	std::fstream	file_in_;
	std::fstream	file_out_;
	std::string		filename_in_;
	std::string		filename_out_;
	std::string		*content_;
};

#endif
