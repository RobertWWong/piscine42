#include <stdio.h>

void	ft_make_array (int arr[8][8], int or_print)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (i < 8)
	{
		while (j < 8)
		{
			if (!or_print)
				arr[i][j] = 0;
			else
				printf("%d, ", arr[i][j]);
			j++;
		}
		if (or_print)
			printf("%c\n", ' ');
		i++;
		j = 0;
	}

}

int		ft_issafe(int board[8][8], int row, int col)
{
	int i;
	int j;

	i = 0;
	j = col;

	// ft_make_array(board, 1);
	// printf("%s\n", "  ");
	while (i < col)
		if (board[row][i++])
			{printf("%s\n","in the first" );return (0);}
	i = row;
	while (i >= 0 && j >= 0)
		if (board[--i][--j])
			{printf("%s\n", "in the seconds");return (0);}
	i = row;
	j = col;
	while (i < 8 && j >= 0)
		if (board[++i][--j])
			{printf("%s\n", "int the thirds");return (0);}

	return (1);
}
/*Stupid ass norminette comment styles */
int		ft_solvequeens(int board[8][8], int col)
{
	int i;
	int valsum;

	i = 0;
	valsum = 0;
	while(i < 8)
	{
		if (col == 8)
		{
			ft_make_array(board, 1);
			return (0);
		}
		if (ft_issafe(board, i, col))
		{
			board[i][col] = 1;
			valsum += ft_solvequeens(board, col + 1);
			board[i][col] = 0;
		}
		else
			return (0);
		i++;
	}
	return valsum;
}

int main(int argc, char const *argv[])		//consider this one to actually be the 8 queen functions
{
	// printf("%d\n", ft_find_next_prime(978123456));

	int chess[8][8];
	int i;
	i = 0;

 	// chess = {{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};


	ft_make_array(chess,0);

	// printf("%d\n",13*12*11*10*9*8*7*6*5*4*3*2*1 );
	ft_make_array(chess,1);
	printf("%c\n", '\n');

	// chess[2][3] = 1;
	ft_make_array(chess,1);

	printf("is safe from others = %d\n\n\n", ft_issafe(chess, 2,3));
	i = ft_solvequeens(chess,0);
	if (i > 0)
		printf("Possible winning places = %d\n", i);
	else
		printf("\n%s  %d\n", "Nah, no winning places",i);


	return 0;
}