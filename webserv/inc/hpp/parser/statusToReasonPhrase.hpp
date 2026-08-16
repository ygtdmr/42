/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statusToReasonPhrase.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 21:57:14 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 12:01:07 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_PARSER_STATUS_TO_REASON_PHRASE_HPP
#define WEBSERV_PARSER_STATUS_TO_REASON_PHRASE_HPP

namespace webserv
{
namespace parser
{
char const* statusToReasonPhrase( int short status );
}  // namespace parser
}  // namespace webserv

#endif
