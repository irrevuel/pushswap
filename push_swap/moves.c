#include "pushswap.h"

void write_move(char *move, char stack)
{
    write(1, move, ft_strlen(move));
    if (stack)
        write(1, &stack, 1);
    write(1, "\n", 1);
}
// COMPROBAR QUE NO LE METO COSAS MALAS EN GENERAL
void swap(t_list **head, char c)
{
    int aux;

    if(!head || !head[0] || !(*head)->next) //ver que hay dos elementos
        return;
    aux = (*head)->content;
    (*head)->content = (*head)->next->content;
    (*head)->next->content = aux;
    if(c)
        write_move("s", c);
    //escribir el moviento, traer por parámetro la letra correspondiente
}

void push(t_list **head_dest, t_list **head_orig, char c)
{
    t_list *aux;

    if (!(*head_orig))
        return;
    aux = (*head_orig)->next;
    ft_lstadd_front(head_dest, (*head_orig));
    *head_orig = aux;
    write_move("p", c);
}

void rotate(t_list **head, char c)
{
    t_list *aux;

    if (!(*head) || !(*head)->next)
        return;
    aux = (*head)->next;
    ft_lstadd_back(head, (*head));
    (*head)->next = NULL;
    *head = aux;
    if (c)
        write_move("r", c);
}

void rrotate(t_list **head, char c)
{
    t_list *last;
    t_list *second_last;

    if (!(*head) || !(*head)->next)
        return;
    last = *head;
    second_last = NULL;
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = *head;
    *head = last;
    if(c)
        write_move("rr", c);
}

void rrr(t_list **head_A, t_list **head_B)
{
    rrotate(head_A, 'r');
    rrotate(head_B, 'r');
    write_move("rr", 0);
}

void ss(t_list **head_A, t_list **head_B)
{
    swap(head_A, 's');
    swap(head_B, 's');
}

void rr(t_list **head_A, t_list **head_B)
{
    rotate(head_A, 0);
    rotate(head_B, 0);
    write_move("rrr", 0);
}