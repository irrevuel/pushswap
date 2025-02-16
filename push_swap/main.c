#include "pushswap.h"

void set_stack(char *s, t_list **head)
{
    int i;
    char **split_array;

    i = 1;
    split_array = ft_split(s, ' ');
    if (split_array)
        *head = ft_lstnew(ft_atoi(split_array[0]));
    while (split_array[i] && split_array)
    {
        ft_lstadd_back(head, ft_lstnew(ft_atoi(split_array[i]))); //deberia de comproba si se ha hecho bien
        i++;
    }
    free_split(split_array);
}

int main(int argc, char *argv[])
{
    char *full_string;
    t_list *head_A;
    t_list *head_B;

    (void)argv;
    if (argc == 1 )
    {
        ft_putendl_fd("Error", 1);
        return (0);
    }
    full_string = join_and_check(argv, argc);
    set_stack(full_string, &head_A);
    if (!full_string)
    {
        ft_putendl_fd("Error", 1);
        return (0);
    }
    sort_stack(&head_A, &head_B);
    /*while (head_A)
    {
        printf("%i\n", head_A->content);
        head_A = head_A->next;
    }*/
    //ft_lstclear(&head_A, free);
    //no tengo que vaciar la lista?
    return 0;
}


