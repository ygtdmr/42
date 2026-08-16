# User Documentation

## Services Provided
This stack provides a fully configured WordPress website using PHP-FPM, backed by a secure MariaDB database. The entire infrastructure is served over a secure HTTPS connection via an NGINX web server. 

Additionally, the stack includes several bonus services:
* **Redis:** Object caching for the WordPress site.
* **FTP Server:** File transfer access to the WordPress content.
* **Static Site:** A lightweight HTML/CSS portfolio served via Lighttpd.
* **Adminer:** A web-based database management interface.
* **phpSysInfo:** A web-based hardware monitoring tool for the host machine.

## How to Start and Stop
* **Start Mandatory Services:** Open your terminal, navigate to the root directory of the project, and run the command `make`. This will automatically build and start all necessary services in the background.
* **Start With Bonus Services:** To start the infrastructure including all the additional bonus features mentioned above, run `make bonus`.
* **Stop:** To safely stop the services without losing any of your data, run the command `make down`.

## How to Access the Website and Panels
* **Main Website:** Once the services are running, open a web browser and navigate to `https://yidemir.42.fr`. Due to the self-signed certificate, your browser might show a security warning. You can safely proceed by clicking "Advanced" and then "Proceed to yidemir.42.fr".
* **WordPress Administration Panel:** To manage the website, navigate to `https://yidemir.42.fr/wp-admin`. Here you can log in using the administrator credentials.
* **Adminer Panel:** Navigate to `http://yidemir.42.fr:8080` to manage the MariaDB database visually.
* **Static Website:** Navigate to `http://yidemir.42.fr:8081` to view the non-PHP static website.
* **System Monitor (phpSysInfo):** Navigate to `http://yidemir.42.fr:8082` to monitor the host machine's CPU, RAM, and disk usage.
* **FTP Access:** Connect via any FTP client (like FileZilla) to `yidemir.42.fr` on port 21 using the FTP credentials.

## Managing Credentials
All sensitive credentials, including the database passwords, FTP user, and the WordPress administration password, are securely stored locally inside the `secrets/` directory. For security reasons, these files are ignored by version control and must not be shared.

## Checking Service Status
You can verify that the services are actively running by executing the following command in your terminal:
`docker ps`
This will list all currently running containers (nginx, wordpress, mariadb, and any bonus containers if launched).
