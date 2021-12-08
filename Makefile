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
				map_tests/map_benchmark.cpp \
				set_tests/set_unit.cpp \
				set_tests/set_benchmark.cpp

ifndef CONTAINERS_LOC
CONTAINERS_LOC = ../containers
endif

HEADER_LOC	=	-I ./Fadey/includes/							\
				-I $(CONTAINERS_LOC)/deque/						\
				-I $(CONTAINERS_LOC)/utility/					\
				-I $(CONTAINERS_LOC)/iterator/					\
				-I $(CONTAINERS_LOC)/lexicographical_compare/	\
				-I $(CONTAINERS_LOC)/list/						\
				-I $(CONTAINERS_LOC)/map/						\
				-I $(CONTAINERS_LOC)/pair/						\
				-I $(CONTAINERS_LOC)/multimap/					\
				-I $(CONTAINERS_LOC)/priority_queue/			\
				-I $(CONTAINERS_LOC)/queue/						\
				-I $(CONTAINERS_LOC)/set/						\
				-I $(CONTAINERS_LOC)/sfinae/					\
				-I $(CONTAINERS_LOC)/stack/						\
				-I $(CONTAINERS_LOC)/unordered_map/				\
				-I $(CONTAINERS_LOC)/vector/					\
				-I $(CONTAINERS_LOC)/srcs						\
				-I $(CONTAINERS_LOC)/src

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
