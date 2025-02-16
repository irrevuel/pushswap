#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
#include "libft.h"
#include <stdio.h>
#include <limits.h>

void free_split(char **s);
void check_digit(char *s);
void check_overflow(char *s);
void check(char *full_result);
char *join_and_check(char *argv[], int argc);
void swap(t_list **head, char c);
void push(t_list **head_dest, t_list **head_orig, char c);
void rotate(t_list **head, char c);
void rrotate(t_list **head , char c);
int is_sorted(t_list *head);
void sort_stack(t_list **head_A, t_list **head_B);
void sort_three(t_list **head_A);
void set_nodes(t_list *head_A, t_list *head_B);
void set_price(t_list *head_A, t_list *head_B);
t_list *cheapest(t_list *head_B);
void set_target_node(t_list *head_A, t_list *head_B);
void set_current_position(t_list *head);
void set_stack(char *s, t_list **head);
void move(t_list *to_move, t_list **head_A, t_list **head_B);
void rrr(t_list **head_A, t_list **head_B);
void ss(t_list **head_A, t_list **head_B);
void rr(t_list **head_A, t_list **head_B);

#endif