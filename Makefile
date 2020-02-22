NAME = libftprintf.a
C = clang
FLAGS = -Wall -Wextra -Werror
LIBFT = inc/libft
DIR_S = src
DIR_O = objs
HEADER = inc


SOURCES = 	ad_0_after0x.c \
 		ad_0_aftersign.c \
 		ad_0_aftersps.c \
 		ad_fld_end.c \
 		ad_fld_strt.c \
		analyze_format.c \
		count_af_dot.c \
	 	find_format.c \
	 	format_c.c \
	  	format_d.c \
	   	format_f.c \
		format_o.c \
		format_p.c \
		format_s.c \
		format_u.c \
		format_x.c \
	 	format_xx.c \
	 	format_processing.c \
		ft_big_itoa_base.c \
	 	ft_dtoa.c \
	 	ft_itoa_base.c \
	  	ft_ldtoa.c \
		ft_printf.c \
	 	ft_strjoin_free.c \
	  	ft_strjoin_free2.c \
	  	ft_strrev.c  \
	  	ft_strsub_free.c \
		get_mods.c \
		help_analyze_format.c \
	 	help_func_for_f.c \
	  	inscrem_s.c \
	   	locate_chr_index.c \
	   	overlay_flags.c \
		prec_ftoi.c  \
		step_precis_for_f.c \
	 	strlen.c  \
	 	work_flags_with_d.c \
		work_flags_with_f.c \
	 	work_flags_with_o.c \
	  	work_flags_with_p.c \
	  	work_flags_with_s.c \
		work_flags_with_u.c \
		work_flags_with_x.c \
	 	work_flags_with_per.c \
		work_with_f.c \
		ft_itoa_long.c \
		ft_unsig_itoa_long.c \

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))
OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))
all: $(NAME)
$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp inc/libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p objs
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<
clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)
fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
re: fclean all
	
