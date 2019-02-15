NAME = fdf
SRCS_DIR = srcs
INCL_DIR = incl
LIBS_DIR = libs
FLAG_W =
FLAG_G = -lmlx -framework OpenGL -framework Appkit
LIBS = -L$(LIBS_DIR) -l$(L_FILE)
C_FILES = apply_correction.c apply_move.c apply_rotation.c apply_scale.c apply_type.c \
    ev_hook.c ft_error.c ft_prints.c ft_set_defaults.c ft_tools.c \
    gr_color.c gr_draw_image.c gr_draw_line_easy.c rd_read_obj.c
O_FILES = $(C_FILES:%.c=%.o) main.o
L_FILE = ft

all: $(NAME)

$(NAME): $(O_FILES)
	make -C $(LIBS_DIR)
	$(CC) -o $(NAME) $(FLAG_G) $(O_FILES) $(LIBS)

$(O_FILES): $(addprefix $(SRCS_DIR)/, $(C_FILES)) main.c
	$(CC) -c $(FLAG_W) -I$(INCL_DIR) $(addprefix $(SRCS_DIR)/, $(C_FILES)) main.c

clean:
	rm -rf $(O_FILES)
	make -C $(LIBS_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBS_DIR) fclean

re:	fclean all
