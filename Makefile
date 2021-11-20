#  **************************************************************************  #
#                                                                              #
#         ,--,  .---.  .-. .-. _______  .--.  ,-..-. .-.,---.  ,---.           #
#       .' .') / .-. ) |  \| ||__   __|/ /\ \ |(||  \| || .-'  | .-.\          #
#       |  |(_)| | |(_)|   | |  )| |  / /__\ \(_)|   | || `-.  | `-'/          #
#       \  \   | | | | | |\  | (_) |  |  __  || || |\  || .-'  |   (           #
#        \  `-.\ `-' / | | |)|   | |  | |  |)|| || | |)||  `--.| |\ \          #
#         \____\)---'  /(  (_)   `-'  |_|  (_)`-'/(  (_)/( __.'|_| \)\         #
#              (_)    (__)                      (__)   (__)        (__)        #
#               _______ ,---.     .---.  _______ ,---.  ,---.                  #
#              |__   __|| .-'    ( .-._)|__   __|| .-'  | .-.\                 #
#                )| |   | `-.   (_) \     )| |   | `-.  | `-'/                 #
#               (_) |   | .-'   _  \ \   (_) |   | .-'  |   (                  #
#                 | |   |  `--.( `-'  )    | |   |  `--.| |\ \                 #
#                 `-'   /( __.' `----'     `-'   /( __.'|_| \)\                #
#                      (__)                     (__)        (__)               #
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
				utility/benchmark.cpp \
				vector_tests/vector_unit.cpp \
				vector_tests/vector_benchmark.cpp \
				deque_tests/deque_unit.cpp \
				deque_tests/deque_benchmark.cpp \
				map_tests/map_unit.cpp \
				map_tests/map_benchmark.cpp

HEADER_LOC	=	-I ./Fadey/includes/				\
				-I ../Containers/deque/				\
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

LIBRARIES	=	Fadey/libfadey.a

RM 			=	rm -f

all: $(NAME)

$(NAME): make_fadey $(SRC)
	$(CC) $(FLAGS) $(SRC) $(LIBRARIES) $(HEADER_LOC) $(TEST_HEADER) -o $(NAME)

make_fadey:
	make -C Fadey/

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: re
	./$(NAME)

test: run

debug: fclean
	$(CC) $(FLAGS) $(HEADER_LOC) $(TEST_HEADER) $(DEBUG_FLAGS) $(SRC) $(LIBRARIES) -D DEBUG -o $(NAME)
