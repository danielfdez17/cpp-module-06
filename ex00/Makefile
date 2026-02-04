# * Colors
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
RESET = \033[0m
OK = $(GREEN)[OK]$(RESET)

# * Program name
NAME = convert

# * Compilation
MYCPP = c++
MYCPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address

# * Removal
RM = rm -rf

# * Includes
INCLUDES = -I ./inc/

# * Objects dir
OBJ_DIR = ./obj/

# * Sources files
BUREAUCRAT_DIR = ./src/
BUREAUCRAT_SRCS = 	ScalarConverter.cpp \
					main.cpp

SRCS = $(BUREAUCRAT_SRCS)

# * Object files
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

# ! RULES
$(OBJ_DIR)%.o: $(BUREAUCRAT_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(MYCPP) $(MYCPPFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@$(MYCPP) $(MYCPPFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
	@echo "$(OK) $(GREEN)$(NAME)$(RESET)"

all: obj $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJS)
	@echo "$(OK) $(RED)Removed object files$(RESET)"

fclean: clean
	@echo "$(OK) $(RED)Removed $(NAME)$(RESET)"
	@$(RM) $(NAME)

re: fclean all
	@echo "$(OK) $(YELLOW)Rebuilt $(NAME)$(RESET)"

run:
	clear
	@$(MAKE) re --no-print-directory
	./$(NAME) 0
	./$(NAME) 125.50
	./$(NAME) nan
	./$(NAME) 42.024f
	./$(NAME) c
	./$(NAME) nan
	./$(NAME) +inf
	./$(NAME) -inf
	./$(NAME) nanf
	./$(NAME) +inff
	./$(NAME) -inff
	./$(NAME) 45678
	./$(NAME) 987654.23adsf
	./$(NAME) 234789.984
	./$(NAME) adsfadsfadf
	./$(NAME) 123afadsF

.PHONY: all obj clean fclean re run

.DEFAULT_GOAL: all
