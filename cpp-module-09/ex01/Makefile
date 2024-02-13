################################################################################
##                                   CPP-00                                   ##
################################################################################

NAME  := RPN

RESET := \033[0m
CYAN  := \033[1;36m
CHECK := \342\234\224
LOG   := printf "[$(CYAN)$(CHECK)$(RESET)] %s\n"

################################################################################
##                                 DIRECTORIES                                ##
################################################################################

OBJ_DIR   := obj

SOURCES := main.cpp RPN.cpp

OBJS := $(addprefix $(OBJ_DIR)/, $(SOURCES:.cpp=.o))

################################################################################
##                                 COMPILATION                                ##
################################################################################

CC = c++
CFLAGS  := -Wall -Werror -Wextra -std=c++98 -g -pedantic -Wshadow

all: $(NAME)

$(NAME): $(OBJS)
	@$(LOG) "Building $@"
	@$(CC) $^ -o $@

$(OBJ_DIR)/%.o: %.cpp $(OBJ_DIR)
	@$(LOG) "Compiling $(notdir $<)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@$(LOG) "Creating objects directory"
	@mkdir $@

val: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

clean:
	@$(RM) -r $(OBJS)
	@$(RM) -r $(FILE_EXTENSION)
	@$(LOG) "Removing objects"
	@$(RM) -r $(OBJ_DIR)
	@$(LOG) "Removing objects directory"

fclean: clean
	@$(RM) -r $(NAME)
	@$(LOG) "Removing $(NAME)"

re: clean all

.PHONY: all clean fclean re
