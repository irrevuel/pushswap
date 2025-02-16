#include "pushswap.h"

void set_current_position(t_list *head)
{
    int i;

    i = 0;
    while (head)
    {
        head->current_position = i;
        head = head->next;
        i++;
    }
}

void set_target_node(t_list *head_A, t_list *head_B)
{
    t_list *current_a;
    t_list *target_node;

    while (head_B)
    {
        target_node = NULL; // Inicializar `target_node` a NULL al inicio de cada iteración
        current_a = head_A;
        while (current_a)
        {
            if (current_a->content > head_B->content && 
                (!target_node || current_a->content < target_node->content))
                target_node = current_a;
            current_a = current_a->next;
        }
        if (!target_node)
        {
            current_a = head_A;
            target_node = head_A;
            while (current_a)
            {
                if (current_a->content < target_node->content)
                    target_node = current_a;
                current_a = current_a->next;
            }
        }
        head_B->target_node = target_node;
        head_B = head_B->next;
    }
}

void set_price(t_list *head_A, t_list *head_B)
{
    int len_a = ft_lstsize(head_A);
    int len_b = ft_lstsize(head_B);

    while (head_B)
    {
        if (head_B->current_position > len_b / 2)
            head_B->push_price = len_b - head_B->current_position;  //esto lo puedo meter en una funcionque se llama desde el while
        else
            head_B->push_price = head_B->current_position;

        if (head_B->target_node->current_position > len_a / 2)
            head_B->push_price += len_a - head_B->target_node->current_position;
        else
            head_B->push_price += head_B->target_node->current_position;
        head_B = head_B->next;
    }
}

t_list *cheapest(t_list *head_B)
{
    t_list *cheap = NULL;

    while (head_B)
    {
        if (!cheap || head_B->push_price < cheap->push_price)
            cheap = head_B;
        head_B = head_B->next;
    }
    return cheap;
}

void set_nodes(t_list *head_A, t_list *head_B)
{
    set_current_position(head_A);
    set_current_position(head_B);
    set_target_node(head_A, head_B);
    set_price(head_A, head_B);
}
