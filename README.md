*This project has been created as part of the 42 curriculum by yidemir.*

## Description
This project aims to broaden system administration knowledge by setting up a small infrastructure using Docker. The mandatory infrastructure consists of NGINX, WordPress with PHP-FPM, and MariaDB, each running in separate containers based on Alpine Linux. The project introduces the concepts of containerization, service orchestration, and secure communication.

Additionally, as part of the bonus requirements, this infrastructure includes:
* **FTP Server:** A vsftpd server securely pointing to the WordPress volume.
* **Static Website:** A lightweight, non-PHP static website hosted via Lighttpd.
* **Adminer:** A fast, lightweight database management tool.
* **phpSysInfo:** A custom, resource-efficient monitoring service to track the host system's hardware health (CPU, RAM, Disk) in real-time.

### Architectural Choices & Comparisons

* **Virtual Machines vs Docker:** 
Virtual Machines require a full, separate guest operating system to run applications, which consumes significant system resources and takes longer to boot. Docker, on the other hand, containerizes applications by sharing the host machine's operating system kernel. This makes Docker containers incredibly lightweight, fast to start, and highly resource-efficient compared to VMs.

* **Secrets vs Environment Variables:** 
Storing sensitive information like database passwords or credentials directly in `.env` files or standard environment variables poses a massive security risk, and pushing them to a Git repository will lead to a direct failure of the project. Instead, Docker Secrets are strongly recommended and used in this project to securely inject confidential data into containers. Secrets keep sensitive data hidden from the source code and general environment, ensuring maximum security.

* **Docker Network vs Host Network:** 
Using the host network removes the isolation between the container and the host machine, which is strictly forbidden in this architecture. Instead, a custom, isolated Docker network is established. This private bridge network allows the containers to communicate securely with each other using their service names, without exposing internal ports to the outside world.

* **Docker Volumes vs Bind Mounts:** 
Bind mounts heavily rely on the host machine's specific directory structure, which can cause permission and portability issues. Additionally, bind mounts are explicitly not allowed for this project's persistent storage. Therefore, Docker named volumes are utilized. Named volumes are fully managed by Docker, providing a much safer, more robust, and isolated way to persist the WordPress files and MariaDB database even if the containers crash or are recreated.

## Instructions
To start the project, simply navigate to the root directory and run:
`make`

To run the project with all bonus services included:
`make bonus`

To stop the services and clean the environment (including containers and networks):
`make down`

To completely remove the containers, networks, images, and clear all persistent volume data:
`make fclean`

## Resources
* Docker Documentation: https://docs.docker.com/
* NGINX Documentation: https://nginx.org/en/docs/
* MariaDB Documentation: https://mariadb.com/kb/en/
* WordPress Documentation: https://wordpress.org/documentation/
* **AI Usage:** Artificial Intelligence tools were utilized to understand system administration concepts, debug Docker connection issues, configure the NGINX SSL setup, structure the Makefile rules, and draft the required documentation files.
