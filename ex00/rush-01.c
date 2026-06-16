#include <unistd.h>
#include <stdlib.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void print_error(void)
{
    write(1, "Error\n", 6);
}
void print_grid(int grid[4][4])
{
    int row;
    int col;

    row = 0;
    while (row < 4)
    {
        col = 0;
        while (col < 4)
        {
            ft_putchar(grid[row][col] + '0');
            if (col < 3)
                ft_putchar(' ');
            col++;
        }
        ft_putchar('\n');
        row++;
    }
}
int valid_input(char *str)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= '1' && str[i] <= '4')
        {
            count++;
            if (str[i + 1] != ' ' && str[i + 1] != '\0')
                return (0);
        }
        else if (str[i] != ' ')
            return (0);
        i++;
    }
    return (count == 16);
}
void get_clues(char *input, int top[4], int bottom[4], int left[4], int right[4])
{
    int values[16];
    int i;
    char *str;

    i = 0;
    str = input;
    while (i < 16)
    {
        values[i] = atoi(str);
        while (*str != ' ' && *str != '\0')
            str++;
        if (*str == ' ')
            str++;
        i++;
    }
    i = 0;
    while (i < 4)
    {
        top[i] = values[i];
        bottom[i] = values[i + 4];
        left[i] = values[i + 8];
        right[i] = values[i + 12];
        i++;
    }
}
int is_valid_placement(int grid[4][4], int row, int col, int num)
{
    int i;

    i = 0;
    while (i < 4)
    {
        if (grid[row][i] == num)
            return (0);
        if (grid[i][col] == num)
            return (0);
        i++;
    }
    return (1);
}
int count_visible(int line[4])
{
    int count;
    int max;
    int i;

    count = 0;
    max = 0;
    i = 0;
    while (i < 4)
    {
        if (line[i] > max)
        {
            count++;
            max = line[i];
        }
        i++;
    }
    return (count);
}
int check_all_clues(int grid[4][4], int top[4], int bottom[4], int left[4], int right[4])
{
    int i;
    int j;
    int line[4];
    int reversed[4];

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            line[j] = grid[i][j];
            reversed[3 - j] = grid[i][j];
            j++;
        }
        if (count_visible(line) != left[i])
            return (0);
        if (count_visible(reversed) != right[i])
            return (0);
        i++;
    }
    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            line[j] = grid[j][i];
            reversed[3 - j] = grid[j][i];
            j++;
        }
        if (count_visible(line) != top[i])
            return (0);
        if (count_visible(reversed) != bottom[i])
            return (0);
        i++;
    }
    return (1);
}
int solve(int grid[4][4], int pos, int top[4], int bottom[4], int left[4], int right[4])
{
    int row;
    int col;
    int num;

    if (pos == 16)
        return (check_all_clues(grid, top, bottom, left, right));

    row = pos / 4;
    col = pos % 4;

    num = 1;
    while (num <= 4)
    {
        if (is_valid_placement(grid, row, col, num))
        {
            grid[row][col] = num;
            if (solve(grid, pos + 1, top, bottom, left, right))
                return (1);
            grid[row][col] = 0; // backtrack
        }
        num++;
    }
    return (0);
}
int main(int argc, char **argv)
{
    int grid[4][4];
    int top[4];
    int bottom[4];
    int left[4];
    int right[4];
    int i;
    int j;

    if (argc != 2 || !valid_input(argv[1]))
    {
        print_error();
        return (0);
    }

    get_clues(argv[1], top, bottom, left, right);

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            grid[i][j] = 0;
            j++;
        }
        i++;
    }

    if (solve(grid, 0, top, bottom, left, right))
        print_grid(grid);
    else
        print_error();

    return (0);
}
