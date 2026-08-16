*This project has been created as part of the 42 curriculum by ygtdmr.*

# Webserv

## Description
Webserv is a custom HTTP server written from scratch in C++ 98. The primary goal of this project is to understand the inner workings of the HTTP protocol, non-blocking I/O operations, and socket programming. It is capable of serving static websites, handling file uploads, processing chunked requests, and executing CGI scripts (e.g., PHP, Python). The server is designed to be fully non-blocking and resilient, handling multiple client connections concurrently using a single `poll()` (or equivalent) loop.

Key features include:
- Support for `GET`, `POST`, and `DELETE` HTTP methods.
- Non-blocking I/O for all socket operations.
- Serving static files and providing directory listings.
- CGI execution based on file extensions (with full environment variable support).
- Configuration through a custom configuration file (inspired by NGINX).
- Support for multiple virtual servers listening on different ports/interfaces.
- Custom default error pages and configurable maximum client body sizes.
- HTTP redirection support.

## Instructions

### Compilation
The project includes a `Makefile` to compile the source code. The following standard rules are available:
- `make` or `make all`: Compiles the executable `webserv`.
- `make clean`: Removes the object files.
- `make fclean`: Removes the object files and the executable.
- `make re`: Recompiles the entire project.

To compile the server, simply run:
```bash
make
```

### Execution
The server requires a configuration file to run.

Run the server with:
```bash
./webserv [path/to/configuration_file]
```
Example:
```bash
./webserv configs/default.conf
```

Once running, you can connect to the server using a standard web browser, `curl`, `telnet` at the host and port specified in your configuration file (e.g., `http://localhost:8080`).

## Resources
- [RFC 1945 - Hypertext Transfer Protocol -- HTTP/1.0](https://datatracker.ietf.org/doc/html/rfc1945)
- [RFC 2616 - Hypertext Transfer Protocol -- HTTP/1.1](https://datatracker.ietf.org/doc/html/rfc2616)
- [RFC 3875 - The Common Gateway Interface (CGI) Version 1.1](https://datatracker.ietf.org/doc/html/rfc3875)
- [NGINX Documentation](https://nginx.org/en/docs/)
- [Beej's Guide to Network Programming](https://beej.us/guide/bgnet/)

### AI Usage
During this project, Artificial Intelligence tools were utilized in accordance with the 42 curriculum guidelines:
- **Concept Explanations:** AI was used to clarify complex networking concepts, such as non-blocking I/O multiplexing with `poll()`, socket states, and the specific environment variables required for CGI scripts.
- **Brainstorming:** AI assisted in generating ideas for structuring the configuration file parser and architecting the core server loop.
- **Debugging Assistance:** AI tools provided insights into potential causes of socket leaks or hanging connections without writing the final implementation code.
AI was used during this repository reorganization to inspect the HTTP, parser, CGI, and Makefile sources; verify the documented build and launch commands; and prepare this README. The server implementation remains the checked-in project code, and no claim is made that it was AI-generated.
