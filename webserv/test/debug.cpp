#include "debug.hpp"

std::ostream	&operator<<( std::ostream &os, ServerConfig const &sc )
{
	os	<< "server:\n\t["
		<< "host=" << sc.host
		<< ", port=" << sc.port
		<< ", clientMaxBodySize=" << sc.clientMaxBodySize;
	std::map<int, std::string>::const_iterator	error_page_it( sc.errorPages.begin() );
	while ( error_page_it != sc.errorPages.end() )
	{
		os
			<< ", error_page=["
			<< (*error_page_it).first
			<< "=>"
			<< (*error_page_it).second
			<< "]";
		error_page_it++;
	}
	os	<< "]" << std::endl;
	std::vector<LocationConfig>::const_iterator	location_it( sc.locations.begin() );
	while ( location_it != sc.locations.end() )
	{
		os	<< "\t\tlocation:\n\t\t\t["
		<< "path=" << (*location_it).path
		<< ", root=" << (*location_it).root
		<< ", index=" << (*location_it).index
		<< ", autoindex=" << (*location_it).autoindex
		<< ", redirect=(" << (*location_it).redirect.first << " => " << (*location_it).redirect.second << ")"
		<< ", allow_methods=";

		std::vector<std::string>::const_iterator	allow_methods_it( (*location_it).allowMethods.begin() );
		while ( allow_methods_it != (*location_it).allowMethods.end() )
			os << *allow_methods_it++ << " ";
		std::cout << "]" << std::endl;
		location_it++;
	}
	return ( os );
}
