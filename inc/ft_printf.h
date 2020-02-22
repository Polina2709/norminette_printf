/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:17:26 by tmyrcell          #+#    #+#             */
/*   Updated: 2020/02/22 17:29:04 by jczech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FT_PRINTF_H
# define FT_PRINTF_FT_PRINTF_H

# define SPECIFIERS "sSpd%DioOuUxXcCfFeE\\"
# define MODSCHAR "lhL"
# define SUPPORTED "1234567890sSpd%.DioOuUxXcCfFeElhL#0 -+*\\"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include "libft/libft.h"

typedef	struct s_flag	t_flag;
struct		s_flag
{
	unsigned int		flag_minus;
	unsigned int		flag_plus;
	unsigned int		flag_zero;
	unsigned int		flag_space;
	unsigned int		flag_hash;
	unsigned int		width;
	unsigned int		precision;
	unsigned int		prec;
	char				*format;
	char				*format_mod;
};

int				ft_printf(const char *format, ...);
char			*ft_str_concat_unsafe(char *left, const char *right, size_t offset, size_t count);
int				ft_get_mods(const char *format, char **stringformat);
t_flag			*ft_analyze_format(char *stringformat, t_flag *flag, va_list ap);
int				ft_find_format(const char **format, char **output, va_list ap, int *mod_size);
void			analyze_flags(char stringformat, t_flag *flag, va_list ap);
void			analyze_precision(char **stringformat, t_flag *flag, va_list ap);
void			init_width_star(t_flag *flag, va_list ap, int sign_pres);
int				analyze_specifiers(char *stringformat, t_flag *flag);
char			*format_processing(t_flag *flag, va_list ap);
char			*find_coincidence(t_flag *flag, va_list ap);
char			*format_d(t_flag *flag, va_list ap);
char			*format_c(t_flag *flag, va_list ap);
char			*format_s(va_list ap);
char			*format_f(t_flag *flag, va_list ap);
char			*format_u(t_flag *flag, va_list ap);
char			*format_p(va_list ap);
char			*format_o(t_flag *flag, va_list ap);
char			*format_x(t_flag *flag, va_list ap);
char			*format_xx(t_flag *flag, va_list ap);
char			*overlay_flags(t_flag *flag, char *tmp);
char			*work_flags_with_s(t_flag *flag, char *ptr);
char			*work_flags_with_f(t_flag *flag, char *tmp);
char			*work_flags_with_u(t_flag *flag, char *tmp);
char			*work_flags_with_p(t_flag *flag, char *tmp);
char			*work_flags_with_x(t_flag *flag, char *tmp);
char			*work_flags_with_d(t_flag *flag, char *tmp);
char			*work_flags_with_per(t_flag *flag, char *tmp);
char			*work_flags_with_o(t_flag *flag, char *tmp);
char			*set_sign_for_d(t_flag *flag, char *tmp);
char			*second_step_for_d(t_flag *flag, char *tmp);
char			*second_step_for_d2(t_flag *flag, char *tmp);
char			*check_zero_for_d(t_flag *flag, char *str);
char			*ft_dtoa(double d);
char			*ft_ldtoa(long double f);
char			*non_dec_char(long double f);
int				ct_ndec_digit(long double f);
int				is_dec(long double f);
int				is_s_dec(char *tmp);
long double		get_dec_neg(long double f);
long double		get_dec(long double f);
char			*dec_char(long double f);
void			correct_back_ad01(char *s);
long int		prec_ftoi(long double d);
char			*first_step_for_f(t_flag *flag, char *tmp);
char			*second_step_for_f(char *tmp);
int				count_af_dot(char *tmp);
char			*ft_strjoin_free(char *s1, char *s2);
char			*ft_strjoin_free2(char *s1, char *s2);
char			*step_precis_for_f(t_flag *flag, char *tmp);
int				strln(const char *s);
unsigned int	len_without_x(const char *s);
unsigned int	len_without_spec(const char *s);
unsigned int	len_without_sign(const char *s);
void			increm_s(char *tmp, int precis);
int				locate_char_index(char *s, char c);
char			*ft_strsub_free(char *s, int start, int len);
char			*third_step_for_f(t_flag *flag, char *ptr);
char			*third_step_part2(t_flag *flag, char *tmp);
char			*fill_0_after_space(char *input, int count);
char			*ad_fld_end(char *s, int nb_space);
char			*add_fld_strt(char *s, int nb_space);
char			*ad_0_aftersign(char *s, int n);
char			*ad_0_after0x(char *s, int n);
char			chk_lng(t_flag *flag);
int				malloc_count(unsigned long adr);
char			*ft_strrev(char *str);
char			*ft_itoa_base(unsigned long long int n, int base);
char			convert_letter(int a);
char			*first_step_for_x(t_flag *flag, char *tmp);
char			*second_step_for_x(t_flag *flag, char *tmp);
char			*second_step_for_x2(t_flag *flag, char *tmp);
char			*ft_itoa_base_xx(unsigned long int value, unsigned long base);
char			convert_xx(unsigned long int nb);
char			*first_step_for_o(t_flag *flag, char *tmp);
char			*second_step_for_o(t_flag *flag, char *tmp);
char			*second_step_for_o2(t_flag *flag, char *tmp);
char			*ft_itoa_unsigned_long(unsigned long int n);
int				ft_nbrlen_unsigned_long(unsigned long int n);
char			*ft_itoa_long(long n);
char			*ft_zero(char *s);
int				ft_len_of_itoa(unsigned long num);
int				ft_neg(long n, unsigned long *num);
unsigned long	strlen_bytes(char *input, t_flag *flag);
char			*ft_fill_by_symbol(char *s, int symbol_count, char symbol);

#endif
