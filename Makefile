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

CC			=	clang++

FLAGS		=	-std=c++98 -pedantic -Wall -Werror -Wextra

DEBUG_FLAGS	=	-g -fsanitize=address

SRC			=	main.cpp

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

LIBRARIES	=	Fadey/libfadey.a

FADEY		=	./Fadey

FADEY_LOC	=	-I $(FADEY)/includes/

RM 			=	rm -f

COMMON_LOC	=  $(LIBRARIES) $(UTILITY) $(FADEY_LOC) $(OTHER_LOC) $(UTILITY_LOC) $(PAIR_LOC) $(ITERATOR_LOC) $(TEST_HEADER)

all: $(NAME) deque map set vector

$(NAME):

deque: make_fadey
	@ $(CC) $(FLAGS) $(DEQUE_SRC) $(DEQUE_LOC) $(COMMON_LOC) -o $(DEQUE_NAME)
	@ ./$(DEQUE_NAME)

map: make_fadey 
	@ $(CC) $(FLAGS) $(MAP_SRC) $(MAP_LOC) $(COMMON_LOC) -o $(MAP_NAME)
	@ ./$(MAP_NAME)
	
set: make_fadey 
	@ $(CC) $(FLAGS) $(SET_SRC) $(SET_LOC) $(COMMON_LOC) -o $(SET_NAME)
	@ ./$(SET_NAME)

stack: make_fadey 
	@ $(CC) $(FLAGS) $(STACK_SRC) $(STACK_LOC) $(COMMON_LOC) -o $(STACK_NAME)
	@ ./$(STACK_NAME)

vector: make_fadey
	@ $(CC) $(FLAGS) $(VECTOR_SRC) $(VECTOR_LOC) $(COMMON_LOC) -o $(VECTOR_NAME)
	@ ./$(VECTOR_NAME)

make_fadey:
	make -C Fadey/

clean:
	$(RM) $(OBJ)
	make clean -C Fadey/ 

fclean: clean
	make fclean -C Fadey/
	$(RM) $(DEQUE_NAME)
	$(RM) $(MAP_NAME)
	$(RM) $(SET_NAME)
	$(RM) $(STACK_NAME)
	$(RM) $(VECTOR_NAME)

re: fclean all
