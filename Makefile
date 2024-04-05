CFLAGS=-Wall -Wextra -Werror -g
LFLAGS=-Llibft

BUILD_DIR=build
SOURCES_DIR=source
HEADERS_DIR=header
IFLAGS=-I$(HEADERS_DIR) -I.
PUSH_SWAP_HEADER=$(HEADERS_DIR)/push_swap.h
CHECKER_HEADER=$(HEADERS_DIR)/checker.h
COMMON_HEADER=$(HEADERS_DIR)/common.h
PUSH_SWAP_DIR=push_swap
CHECKER_DIR=checker
PUSH_SWAP_PATH=$(SOURCES_DIR)/$(PUSH_SWAP_DIR)
CHECKER_PATH=$(SOURCES_DIR)/$(CHECKER_DIR)
PUSH_SWAP_BUILD_PATH=$(BUILD_DIR)/$(PUSH_SWAP_DIR)
CHECKER_BUILD_PATH=$(BUILD_DIR)/$(CHECKER_DIR)
PUSH_SWAP_MODULES=main
CHECKER_MODULES=main
COMMON_MODULES=numbers_reader ft_atoi_safe push swap rotate_up rotate_down dllist dllist_is_sorted

PUSH_SWAP_OBJ=$(addprefix $(PUSH_SWAP_BUILD_PATH)/, $(addsuffix .o, $(PUSH_SWAP_MODULES)))
CHECKER_OBJ=$(addprefix $(CHECKER_BUILD_PATH)/, $(addsuffix .o, $(CHECKER_MODULES)))
COMMON_OBJ=$(addprefix $(BUILD_DIR)/, $(addsuffix .o, $(COMMON_MODULES)))

.PHONY: bonus all clean fclean re

all: push_swap

bonus: checker

libft/libft.a:
	make -C libft all

push_swap: $(PUSH_SWAP_BUILD_PATH) libft/libft.a $(PUSH_SWAP_OBJ) $(COMMON_OBJ) $(PUSH_SWAP_HEADER) Makefile
	cc $(CFLAGS) $(LFLAGS) -DPRINT_STACK_ACTIONS=1 -o $@ $(PUSH_SWAP_OBJ) $(COMMON_OBJ) -lft

checker: $(CHECKER_BUILD_PATH) libft $(CHECKER_OBJ) $(COMMON_OBJ) $(CHECKER_HEADER) Makefile
	cc $(CFLAGS) $(LFLAGS) -o $@ $(CHECKER_OBJ) $(COMMON_OBJ) -lft

$(BUILD_DIR):
	mkdir $@

$(PUSH_SWAP_BUILD_PATH): | $(BUILD_DIR)
	mkdir $@

$(CHECKER_BUILD_PATH): | $(BUILD_DIR)
	mkdir $@

$(PUSH_SWAP_BUILD_PATH)/%.o: $(PUSH_SWAP_PATH)/%.c $(PUSH_SWAP_HEADER) Makefile
	cc $(CFLAGS) $(IFLAGS) -o $@ -c $<

$(CHECKER_BUILD_PATH)/%.o: $(CHECKER_PATH)/%.c $(CHECKER_HEADER) Makefile
	cc $(CFLAGS) $(IFLAGS) -o $@ -c $<

$(BUILD_DIR)/%.o: $(SOURCES_DIR)/%.c $(COMMON_HEADER) Makefile
	cc $(CFLAGS) $(IFLAGS) -o $@ -c $<

clean:
	make -C libft fclean
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f push_swap

re: fclean all
