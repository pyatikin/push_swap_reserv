#include "push_swap.h"

int if_sorted(int argc, char **argv)
{

}
int parse_argv(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
    while(i < argc)
	{
		j = 0;
		while(argv[i][j])
		{
			if(!(ft_isdigit(argv[i][j]) || (argv[i][0] == '-' && (ft_isdigit(argv[i][1])))))
				return (1);
			j++;
		
		}
		i++;
	}
	return (0);
}

t_stack *translate(int argc, char **argv)
{
	t_stack *a;
	int	i;

	i = 1;
	a = createt_stack();
	while(i<argc)
	{
		//printf("%d\t", ft_atoi(argv[i]));
		if(argv[i][0] == '0' && argv[i][1] == '\0')
			pushBack(a, 0);
		else if(ft_atoi(argv[i]) == 0)
		{
			printf("WRONG NUM\n");
			exit(4);
		}
		else
			pushBack(a, ft_atoi(argv[i]));
		i++;
	}
	//printt_stack(a);
	return (a);
}
void duplicates(t_stack *st)
{
	int i;
	int j;

	i = 0;
	while(i < st->size-1){
		j=i+1;
		while (j<st->size)
		{
			if(getNvalue(st, i) == getNvalue(st, j))
			{
				printf("DUPLICATES\n");
				exit(2);
			}
			j++;
		}
		i++;
	}
}
int main(int argc, char**argv)
{
	t_stack *st;
	t_stack *b;
    if(argc <= 2)
        return (0);
    else
    {
        if(parse_argv(argc, argv))
		{
			printf("NOT NUM\n");
			exit (1);
		}
		st = translate(argc, argv);
		duplicates(st);
//------------------------------------
		b = createt_stack();


		parse_stack(st, b);
		triple_sort(st);
		find_your_place(st, b);
		evaluation(st, b);
		printf("a\n");
		printt_stack(st);
		printf("b\n");
		printt_stack(b);
		Node *tmp = b->head;
		while(tmp != NULL)
		{
			printf("value = %d | place b = %d | place a = %d | price = %d\n", tmp->value, tmp->b_place, tmp->a_place, tmp->price);
			tmp = tmp->next;
		}
		printf("%d", (int)(0.9));

		//triple_sort(st);
        //if_sorted(argc,argv);
    }
}