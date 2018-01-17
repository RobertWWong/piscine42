/*This one is going to run our actual program*/
void	sastantua(int size)
{

}

/*This will make our door, which has a $ handle in the middle row, one space from the right side, height */
void	make_door(int length, int handle)
{
	int row;
	int col;

	row = 0;
	col = 0;
	while (row < length)
	{
		col = 0;
		while (col < length)
		{
			if (handle && (row == length / 2) && (col == length - 2))
				printf("%c", '$');
			else
				printf("%c", '|');
			col++;
		}
		printf("%c\n", '\n');
		row++;
	}
}

/*This will make the steps for either the left/right side from the door or a whole step.*/
void	make_steps(int length, int left_right_none)
{

}


/*Find the height of the pyramid*/
int	find_height(int stage)
{
	if (stage == 1)
		return (3);
	return (3 + stage - 1);
}

/*Arithmetic series to find total height of pyramid*/
int find_total_height(int stages)
{	
	return ((stages * (3 + (3 + stages - 1)) / 2));
}

/*
**	Now this one needs some work. I need to figure out how to even get it started 
**	The beginning row space depends on the previous row, and its current stage.
**	it is a multiple of a stage ratio and its height.
*/
int		find_beginning_rowspace(int stage)
{
	int hardmaths;
	int height;
	int totalheight;

	height = find_height(stage);
	totalheight = find_total_height(stage);
	hardmaths = 0;
	if (stage == 1)
		return (3);

	return 1;
}

/*
** Does exactly what it is named.
** Formula for finding bottom row of current stage is =  current + (stage_height - 1) * 2
** Because a star is added to each end for every row.
*/
int		find_bottom_rowspace(int currentrowlen, int stage)
{
	int height;

	height = (find_height(stage) - 1) * 2;	
	return (currentrowlen + height);
}


/*This will create the pyramid pattern of each stage
Stage one begins with 3 rows, and increases by one for every stage after the forst pme*/
void	make_stages(int stage)
{
	int rowspace;
	int height;
	int idx;

	idx = 0;
	rowspace = 0;
	height = find_height(stage);
	if (stage == 1)
	{
		while (idx < height)
			idx++;	
	}
	height++;
}


int main(int argc, char const *argv[])
{

	// sastantua(3);
	int height = 5;
	int rowspace = 57;
	printf("Current stage height = %d\n", find_height(height));
	printf("Total height of stages %d  		%d\n", find_total_height(height), 3+4+5+6+7);
	printf("bottom row = %d\n", find_bottom_rowspace(rowspace , height));
	
	return 0;
}