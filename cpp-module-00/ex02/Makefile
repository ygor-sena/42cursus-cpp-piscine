################################################################################
##                                   CPP-00                                   ##
################################################################################

NAME  := account

RESET := \033[0m
CYAN  := \033[1;36m
CHECK := \342\234\224
LOG   := printf "[$(CYAN)$(CHECK)$(RESET)] %s\n"

################################################################################
##                                 DIRECTORIES                                ##
################################################################################

OBJ_DIR   := obj
INC_DIRS  := include

HEADERS := Account.hpp

SOURCES := tests.cpp Account.cpp

OBJS := $(addprefix $(OBJ_DIR)/, $(SOURCES:.cpp=.o))
TEST_LOG := test.log

################################################################################
##                                 COMPILATION                                ##
################################################################################

CC = c++
CFLAGS  := -Wall -Werror -Wextra -std=c++98 $(addprefix -I, $(INC_DIRS))

all: $(NAME)

$(NAME): $(OBJS) | $(LIBFT) $(MLX)
	@$(LOG) "Building $@"
	@$(CC) $^ -o $@

$(OBJ_DIR)/%.o: %.cpp $(HEADERS) | $(OBJ_DIR)
	@$(LOG) "Compiling $(notdir $<)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@$(LOG) "Creating objects directory"
	@mkdir $@

val: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

clean:
	@$(RM) -r $(OBJS) $(TEST_LOG)
	@$(LOG) "Removing objects"
	@$(RM) -r $(OBJ_DIR)
	@$(LOG) "Removing objects directory"

fclean: clean
	@$(RM) -r $(NAME)
	@$(LOG) "Removing $(NAME)"

re: clean all

.PHONY: all clean fclean re
