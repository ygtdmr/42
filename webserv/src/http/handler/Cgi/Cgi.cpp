/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cgi.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 19:01:23 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 22:40:51 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/hpp/http/handler/Cgi.hpp"
#include "../../../../inc/hpp/http/Client.hpp"

namespace webserv
{
namespace http
{

namespace handler
{

Cgi::Cgi( http::Client* client )
	: Handler( client ), pipeInFd( -1 ), pipeOutFd( -1 ), pid_( -1 ), bodySent( 0 ), envStr_(), env_()
{}

Cgi::Cgi( Cgi const& other ) : Handler( other )
{
	*this = other;
}

Cgi::~Cgi()
{
	if ( pipeInFd != -1 )
		client->controller->removePollfd(pipeInFd);
	if ( pipeOutFd != -1 )
		client->controller->removePollfd(pipeOutFd);
}

Cgi& Cgi::operator=( Cgi const& other )
{
	Handler::operator=( other );
	if ( this != &other )
	{
		pipeInFd = other.pipeInFd;
		pipeOutFd = other.pipeOutFd;
		pid_ = other.pid_;
		bodySent = other.bodySent;
		envStr_ = other.envStr_;
		env_.clear();
		for (size_t i = 0; i < envStr_.size(); i++)
			env_.push_back( const_cast<char *>( envStr_[i].c_str() ) );
		env_.push_back(0);
	}
	return *this;
}

Handler* Cgi::clone( http::Client* client )
{
	Cgi *clone(new Cgi(*this));
	clone->client = client;
	return clone;
}

}  // namespace handler

}  // namespace http

}  // namespace webserv
