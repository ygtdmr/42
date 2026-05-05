# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/04 13:49:53 by yidemir           #+#    #+#              #
#    Updated: 2026/05/05 18:11:09 by yidemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPOSE_FILE		= srcs/docker-compose.yml
COMPOSE_FILE_BONUS	= srcs/docker-compose_bonus.yml

DATA_PATH_WP		= /home/yidemir/data/wordpress
DATA_PATH_MDB		= /home/yidemir/data/mariadb

all: up

up:
	@echo "Docker container is building and doing up..."
	mkdir -p $(DATA_PATH_MDB)
	mkdir -p $(DATA_PATH_WP)
	docker compose -f $(COMPOSE_FILE) up -d --build

bonus:
	@echo "Docker container is building and doing up with bonus containers..."
	mkdir -p $(DATA_PATH_MDB)
	mkdir -p $(DATA_PATH_WP)
	docker compose -f $(COMPOSE_FILE_BONUS) up -d --build

down:
	@echo "Docker container is going down..."
	docker compose -f $(COMPOSE_FILE) -f $(COMPOSE_FILE_BONUS) down

clean:
	@echo "Docker system cache is cleaning..."
	docker system prune -f

fclean:
	@echo "Docker container is deleting with related all data and images..."
	docker compose -f $(COMPOSE_FILE) -f $(COMPOSE_FILE_BONUS) down --volumes --rmi all
	sudo rm -rf $(DATA_PATH_MDB) 
	sudo rm -rf $(DATA_PATH_WP) 
	$(MAKE) clean

re: fclean all

.PHONY: all up bonus down clean fclean re
