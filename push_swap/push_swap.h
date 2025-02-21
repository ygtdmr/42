/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:33:24 by yidemir           #+#    #+#             */
/*   Updated: 2025/02/21 18:37:09 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

typedef struct s_stack
{
	int				*nbr;
	struct s_stack	*next;
}	t_stack;

size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s1);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

t_stack	*stack_new(int *nbr);
t_stack	*stack_last(t_stack *s);
void	stack_clear(t_stack **s, void (*del)(void*));
void	stack_add_front(t_stack **s, t_stack *n);
void	stack_add_back(t_stack **s, t_stack *n);
void	stack_delone(t_stack *s, void (*del)(void*));
int		stack_size(t_stack *s);
int		stack_sorted(t_stack *s);

int		args_to_stack(int argc, char **argv, t_stack **s);
int		stack_action(char *a, t_stack **sa, t_stack **sb);
void	do_action(char *a, t_stack **sa, t_stack **sb);
int		*nbr_next(t_stack *s, int *nbr);
int		*nbr_max(t_stack *s);
int		*nbr_prev(t_stack *s, int *nbr);
void	nbr_mv_b(t_stack **sa, t_stack **sb);
void	nbr_mv_a(t_stack **sa, t_stack **sb);
int		nbr_mv_side(t_stack *stack, int nbr);
void	nbr_set(t_stack *sa, t_stack *sb, int *na, int *nb);
