# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 10:21:00 by rgohrig           #+#    #+#              #
#    Updated: 2026/03/19 15:38:07 by rgohrig          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                             C++ MAKEFILE
# **************************************************************************** #

# ----------------------------- GENERAL ----------------------------------------

NAME :=			bureaucrat

COMPILER :=		c++
DEBUG_FLAGS :=	-Wshadow -g -fsanitize=address,undefined
CFLAGS :=		-Wall -Werror -Wextra -std=c++17

HEADERS :=		-I include 

SRC :=			main.cpp Bureaucrat.cpp AForm.cpp \
				ShrubberyCreationForm.cpp \
				PresidentialPardonForm.cpp \
				RobotomyRequestForm.cpp \
				Intern.cpp

DIR_OBJ :=		obj
OBJ :=			$(SRC:%.cpp=$(DIR_OBJ)/%.o)


# ----------------------------- NORMAL -----------------------------------------

all: $(NAME)

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

$(DIR_OBJ)/%.o: %.cpp | $(DIR_OBJ)
	@mkdir -p $(dir $@)
	@$(COMPILER) $(CFLAGS) $(HEADERS) -o $@ -c $<
	@echo 🔥 $@

# executable
$(NAME): $(OBJ)
	@$(COMPILER) $(CFLAGS) -o $@ $^
	@echo "\n   C🚀🚀   $@   ($(CFLAGS))\n"

# ----------------------------- Clean ------------------------------------------

clean:
	@rm -rf $(DIR_OBJ)
	@echo 🧹 cleaned all objects

fclean: clean
	@rm -f $(NAME)
	@echo 🧹🧹🧹 cleaned $(NAME)

re: fclean all

# ----------------------------- Debug ------------------------------------------

debug: fclean
debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(NAME)

.PHONY: all clean fclean re debug
