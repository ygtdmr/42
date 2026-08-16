/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:43:52 by yidemir           #+#    #+#             */
/*   Updated: 2026/03/12 15:36:38 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>

class RPN
{
public:
	RPN( void );
	RPN( const RPN &other );
	~RPN();
	RPN	&operator=( const RPN &other );
	int	calc( const std::string &input );
private:
	std::stack<int>	numbers_;

	bool	isOperator( const char &c );
};

#endif
