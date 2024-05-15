CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

M_SRCS		=	get_next_line.c get_next_line_utils.c
BONUS_SRCS	=	get_next_line_bonus.c get_next_line_utils_bonus.c

M_OBJS		=	$(M_SRCS:.c=.o)
BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

all:	mrun brun

mrun:	$(M_OBJS) main_mandatory.c
		$(CC) $(CFLAGS) -o m.run $(M_OBJS) main_mandatory.c
		./m.run

brun:	$(BONUS_OBJS) main_bonus.c
		$(CC) $(CFLAGS) -o b.run $(BONUS_OBJS) main_bonus.c
		./b.run

clean:	
		rm -f $(M_OBJS) $(BONUS_OBJS) m.run b.run

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@