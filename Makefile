#  **************************************************************************  #
#                                                                              #
#               ,---------.     .-''-.      .-'''-.  ,---------.               #
#               \          \  .'_ _   \    / _     \ \          \              #
#                `--.  ,---' / ( ` )   '  (`' )/`--'  `--.  ,---'              #
#                   |   \   . (_ o _)  | (_ o _).        |   \                 #
#                   :_ _:   |  (_,_)___|  (_,_). '.      :_ _:                 #
#                   (_I_)   '  \   .---. .---.  \  :     (_I_)                 #
#                  (_(=)_)   \  `-'    / \    `-'  |    (_(=)_)                #
#                   (_I_)     \       /   \       /      (_I_)                 #
#                   '---'      `'-..-'     `-...-'       '---'                 #
#                                                                              #
#                    Kingmar  |  https://github.com/K1ngmar                    #
#                                                                              #
#  **************************************************************************  #

NAME		=	container_test

CC			=	clang++

FLAGS		=	-std=c++98 -pedantic -Wall -Werror -Wextra

DEBUG_FLAGS	=	-g -fsanitize=address

SRC			=	main.cpp \
				utility/test_utility.cpp \
				vector_tests/vector_unit.cpp \
				vector_tests/vector_benchmark.cpp \
				deque_tests/deque_unit.cpp

HEADER_LOC	=	-I ../Containers/deque/				\
				-I ../Containers/utility/			\
				-I ../Containers/iterator/			\
				-I ../Containers/list/				\
				-I ../Containers/map/				\
				-I ../Containers/pair/				\
				-I ../Containers/multimap/			\
				-I ../Containers/priority_queue/	\
				-I ../Containers/queue/				\
				-I ../Containers/set/				\
				-I ../Containers/sfinae/			\
				-I ../Containers/stack/				\
				-I ../Containers/unordered_map/		\
				-I ../Containers/vector/

TEST_HEADER =	-I includes/

RM 			=	rm -f

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) $(HEADER_LOC) $(TEST_HEADER) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: re
	./$(NAME)

test: run

debug: fclean
	$(CC) $(FLAGS) $(HEADER_LOC) $(TEST_HEADER) $(DEBUG_FLAGS) $(SRC) -D DEBUG -o $(NAME)
