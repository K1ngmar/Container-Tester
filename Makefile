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

include config.mk 

DEQUE_NAME	=	deque_tester
MAP_NAME	=	map_tester
SET_NAME	=	set_tester
STACK_NAME	=	stack_tester
VECTOR_NAME	=	vector_tester
BANNER_NAME	=	print_banner

CC			=	clang++

FLAGS		=	-std=c++98 -pedantic -Wall -Werror -Wextra

DEBUG_FLAGS	=	-g -fsanitize=address

BANNER_SRC	=	banner/main.cpp

UTILITY		=	utility/test_utility.cpp			\
				utility/benchmark.cpp

DEQUE_SRC	=	deque_tests/deque_unit.cpp			\
				deque_tests/deque_benchmark.cpp		\
				deque_tests/main.cpp

MAP_SRC		=	map_tests/map_unit.cpp				\
				map_tests/map_benchmark.cpp			\
				map_tests/main.cpp

SET_SRC		=	set_tests/set_unit.cpp				\
				set_tests/set_benchmark.cpp			\
				set_tests/main.cpp

VECTOR_SRC	=	vector_tests/vector_unit.cpp		\
				vector_tests/vector_benchmark.cpp	\
				vector_tests/main.cpp
				
TEST_HEADER =	-I includes/

LIBFADEY	=	Fadey/libfadey.a

FADEY		=	./Fadey

FADEY_LOC	=	-I $(FADEY)/includes/

RM 			=	rm -f

COMMON_LOC	=  $(LIBFADEY) $(UTILITY) $(FADEY_LOC) $(OTHER_LOC) $(UTILITY_LOC) $(PAIR_LOC) $(ITERATOR_LOC) $(TEST_HEADER)

all:
	@ $(MAKE) banner
	@ $(MAKE) deque
	@ $(MAKE) map
	@ $(MAKE) set
	@ $(MAKE) vector

banner: make_fadey $(BANNER_NAME)
	@ ./$(BANNER_NAME)

$(BANNER_NAME):
	@ $(CC) $(FLAGS) $(BANNER_SRC) $(COMMON_LOC) -o $(BANNER_NAME)

deque: make_fadey $(DEQUE_NAME)
	@ ./$(DEQUE_NAME)

$(DEQUE_NAME):
	@ $(CC) $(FLAGS) $(DEQUE_SRC) $(DEQUE_LOC) $(COMMON_LOC) -o $(DEQUE_NAME)

map: make_fadey $(MAP_NAME)
	@ ./$(MAP_NAME)

$(MAP_NAME):
	@ $(CC) $(FLAGS) $(MAP_SRC) $(MAP_LOC) $(COMMON_LOC) -o $(MAP_NAME)
	
set: make_fadey $(SET_NAME)
	@ ./$(SET_NAME)

$(SET_NAME):
	@ $(CC) $(FLAGS) $(SET_SRC) $(SET_LOC) $(COMMON_LOC) -o $(SET_NAME)

stack: make_fadey $(STACK_NAME)
	@ ./$(STACK_NAME)

$(STACK_NAME):
	@ $(CC) $(FLAGS) $(STACK_SRC) $(STACK_LOC) $(COMMON_LOC) -o $(STACK_NAME)

vector: make_fadey $(VECTOR_NAME)
	@ ./$(VECTOR_NAME)

$(VECTOR_NAME):
	@ $(CC) $(FLAGS) $(VECTOR_SRC) $(VECTOR_LOC) $(COMMON_LOC) -o $(VECTOR_NAME)

make_fadey: $(LIBFADEY)

$(LIBFADEY):	
	@ $(MAKE) -C Fadey/

clean:
	@ $(RM) $(OBJ)
	@ $(MAKE) clean -C Fadey/ 

fclean: clean
	$(MAKE) fclean -C Fadey/
	$(RM) $(DEQUE_NAME)
	$(RM) $(MAP_NAME)
	$(RM) $(SET_NAME)
	$(RM) $(STACK_NAME)
	$(RM) $(VECTOR_NAME)
	$(RM) $(BANNER_NAME)

re: fclean all

.PHONY: $(BANNER_NAME)
