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
	std::map<std::string, LocationConfig>::const_iterator	location_it( sc.locations.begin() );

	while ( location_it != sc.locations.end() )
	{
		LocationConfig const	&location( location_it->second );

		os	<< "\t\tlocation:\n\t\t\t["
		<< "path=" << location_it->first
		<< ", root=" << location.root
		<< ", upload_dir=" << location.uploadDir
		<< ", cgi_path=" << location.cgiPath
		<< ", cgi_extension=" << location.cgiExtension
		<< ", index=" << location.index
		<< ", autoindex=" << location.autoindex
		<< ", redirect=(" << location.redirect.first << " => " << location.redirect.second << ")"
		<< ", allow_methods=";

		std::vector<std::string>::const_iterator	allow_methods_it( location.allowMethods.begin() );
		while ( allow_methods_it != location.allowMethods.end() )
			os << *allow_methods_it++ << " ";
		std::cout << "]" << std::endl;
		location_it++;
	}
	return ( os );
}

void printSevers( std::vector<ServerConfig> servers )
{
	for (size_t i = 0; i < servers.size(); i++)
	{
		std::cout << servers[i];
	}
}
