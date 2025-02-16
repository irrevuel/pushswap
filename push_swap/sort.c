#include "pushswap.h"

int is_sorted(t_list *head)
{
    if (head == NULL || head->next == NULL)
        return 1;
    while (head && head->next)
    {
        if (head->content > head->next->content)
            return 0;
        head = head->next;
    }
    return 1;
}

void sort_three(t_list **head_A)
{
    t_list *highest;
    t_list *current;

    highest = *head_A;
    current = (*head_A)->next;
    while (current)
    {
        if (current->content > highest->content)
            highest = current;
        current = current->next;
    }
    if (*head_A == highest)
        rotate(head_A, 'a');
    else if ((*head_A)->next == highest)
        rrotate(head_A, 'a');
    
    if ((*head_A)->content > (*head_A)->next->content)
        swap(head_A, 'a');
}

void move(t_list *to_move, t_list **head_A, t_list **head_B)
{
    int targetA;
    int targetB;
    int middle_A = ft_lstsize(*head_A) / 2;
    int middle_B = ft_lstsize(*head_B) / 2;

    if (!to_move->target_node)
        return;
    targetA = to_move->target_node->current_position;
    targetB = to_move->current_position;
    while ((*head_A)->current_position != targetA && (*head_B)->current_position != targetB)
    {
        if ((*head_A)->current_position > middle_A && (*head_B)->current_position > middle_B)
            rrr(head_A, head_B);
        else if ((*head_A)->current_position < middle_A && (*head_B)->current_position < middle_B)
            rr(head_A, head_B);
        else
            break;
    }

    /*while ((*head_B)->current_position != targetB)
    {
                       write (1, "ADI\n", 4);

        if ((*head_B)->current_position > middle_B)
            rrotate(head_B, 'b');
        else
            rotate(head_B, 'b');
    }*/

    if ((*head_B)->current_position != targetB)
    {
        //printf("current position: %i\n", (*head_B)->current_position);
        if ((*head_B)->current_position > middle_B)
       {
            while ((*head_B)->current_position != targetB)
            {
               // printf("current position: %i\n", (*head_B)->current_position);
                rrotate(head_B, 'b');
            }
                //rrotate(head_A, 'a');
       } 
        else
        {
            while ((*head_B)->current_position != targetB)
            {
               // printf("current position: %i\n", (*head_B)->current_position);
                rotate(head_B, 'b');
            }
                //rotate(head_A, 'a');
        } 
    }

    if ((*head_A)->current_position != targetA)
    {
        if ((*head_A)->current_position > middle_A)
       {
            while ((*head_A)->current_position != targetA)
                rrotate(head_A, 'a');
       } 
        else
        {
            while ((*head_A)->current_position != targetA)
                rotate(head_A, 'a');
        } 
    }
    push(head_A, head_B, 'a');
}

 void print_nodes(t_list *head_A, t_list *head_B)
 {
    printf("Stack B\n");
    while (head_B)
    {
        printf("content: %i ", head_B->content);
        printf("current pos: %i ", head_B->current_position);
        printf("push price: %i ", head_B->push_price);
        printf("nodo objetivo: %i \n", head_B->target_node->content);
        head_B = head_B->next;
    }
    printf("Stack A\n");
    while (head_A)
    {
        printf("content: %i ", head_A->content);
        printf("current pos: %i \n", head_A->current_position);
        head_A = head_A->next;
    }
    
 }

void lowest_to_top(t_list **head_A)
{
    t_list *lowest;
    t_list *current;
    int middle = ft_lstsize(*head_A) / 2;

    lowest = *head_A;
    current = (*head_A)->next;
    while (current)
    {
        if (current->content < lowest->content)
            lowest = current;
        current = current->next;
    }
    if (*head_A == lowest)
        return;
    else
    {

        if ((*head_A)->content != lowest->content)
        {
            if ((*head_A)->current_position > middle)
            {
                while ((*head_A)->content != lowest->content)
                    rrotate(head_A, 'a');
            } 
            else
            {
                while ((*head_A)->content != lowest->content)
                    rotate(head_A, 'a');
            } 
        }
    }
}

//Necesito ordenar 2 elementos?
void sort_stack(t_list **head_A, t_list **head_B)
{
    t_list  *to_move;
    int i;
    //int j = 0;

    *head_B = NULL;
    i = ft_lstsize(*head_A);
    if (is_sorted(*head_A))
        return;
    if (i == 3)
    {
        sort_three(head_A);
        return;
    }
    //ordeno el stack A
    while (ft_lstsize(*head_A) > 3)
            push(head_B, head_A, 'b');
    sort_three(head_A);
    while (*head_B)
    {
        set_nodes(*head_A, *head_B); 
        to_move = cheapest(*head_B);
        /*printf("content: %i ", to_move->content);
        printf("current pos: %i ", to_move->current_position);
        printf("push price: %i ", to_move->push_price);
        printf("nodo objetivo: %i", to_move->target_node->content);
        printf("movimineto numero %i\n", j);*/
        move(to_move, head_A, head_B);
       // j++;
        //write(1, "move\n", 5);
    }
    lowest_to_top(head_A);
    //print_nodes(*head_A, *head_B);
}