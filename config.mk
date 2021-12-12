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

_CONTAINERS_LOC	=	../containers

DEQUE_LOC		=	$(CONTAINERS_LOC)/deque/

UTILITY_LOC		=	$(CONTAINERS_LOC)/utility/

ITERATOR_LOC	=	$(CONTAINERS_LOC)/iterator/

MAP_LOC			=	$(CONTAINERS_LOC)/map/

PAIR_LOC		=	$(CONTAINERS_LOC)/pair/

SET_LOC			=	$(CONTAINERS_LOC)/set/

STACK_LOC		=	$(CONTAINERS_LOC)/stack/

VECTOR_LOC		=	$(CONTAINERS_LOC)/vector/

OTHER_LOC		=	$(CONTAINERS_LOC)/sfinae/					\
					$(CONTAINERS_LOC)/unorederd_map/			\
					$(CONTAINERS_LOC)/lexicographical_compare/	\
					$(CONTAINERS_LOC)/type_traits

CONTAINERS_LOC	= $(addprefix -I, $(_CONTAINERS_LOC))
