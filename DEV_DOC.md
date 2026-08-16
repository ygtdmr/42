# Developer Documentation

## Environment Setup
Before building the project, ensure your host environment is properly configured:
1. **Domain Redirection:** Update your `/etc/hosts` file to point `yidemir.42.fr` to the local loopback address `127.0.0.1`.
2. **Data Directories:** Ensure the required host directories for data persistence are created. The project expects `/home/yidemir/data/mariadb` and `/home/yidemir/data/wordpress` to be available.
3. **Environment Variables and Secrets:** A valid `.env` file must be present in the `srcs/` directory containing non-sensitive variables like `DOMAIN_NAME`. Additionally, ensure all necessary password files (`credentials.txt`, `db_password.txt`, `db_root_password.txt`) are created and populated inside the root `secrets/` directory.

## Building and Launching
The infrastructure is fully orchestrated using the provided `Makefile`, which acts as a wrapper for the `docker-compose` commands. 
To build the required images from the Alpine base and launch the mandatory containers in detached mode, run:
`make`

To build and launch the infrastructure along with all the additional bonus services (FTP, Static Site, Adminer, phpSysInfo) using `docker-compose_bonus.yml`, run:
`make bonus`

## Managing Containers and Volumes
* **View live logs of a specific container:** `docker logs <container_name>` (e.g., `docker logs wordpress`)
* **Access a running container's shell:** `docker exec -it <container_name> sh`
* **Stop all services gracefully:** `make down`
* **Clean the environment:** Run `make clean` to remove stopped containers and unused networks, or `make fclean` to completely wipe out all containers, images, and the persistent volume data on the host machine.

## Data Persistence
All persistent data in this architecture is stored using Docker named volumes to comply with the project guidelines. The physical paths on the host machine where these volumes are stored are:
* **MariaDB Database:** `/home/yidemir/data/mariadb`
* **WordPress Files:** `/home/yidemir/data/wordpress`
