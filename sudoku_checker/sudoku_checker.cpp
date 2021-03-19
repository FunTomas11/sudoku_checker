#include <iostream>

using namespace std;

const size_t LENGTH = 9;

class Sudoku
{
private:
	int arr[LENGTH][LENGTH];
	int chk_arr[LENGTH] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	bool isRowSolved(int arr[LENGTH])
	{

		size_t chk = 0;

		for (size_t i = 0; i < LENGTH; i++)
		{
			for (size_t j = 0; j < LENGTH; j++)
			{
				if (chk_arr[i] == arr[j])
					chk++;
			}
		}

		return chk == LENGTH;
	}

	bool isExistsAtRow(int arr[LENGTH], int num)
	{
		for (int i = 0; i < LENGTH; i++)
		{
			if (arr[i] == num)
				return false;
		}

		return true;
	}

	void solveRow(int arr[LENGTH])
	{

		for (int i = 0; i < LENGTH; i++)
		{
			size_t j = 0;
			while (isExistsAtRow(arr, arr[i]))
			{
				arr[i] = chk_arr[j];
				j++;
			}
		}
	}

public:
	Sudoku(int(&arr)[LENGTH][LENGTH])
	{
		for (size_t i = 0; i < LENGTH; i++)
		{
			for (size_t j = 0; j < LENGTH; j++)
			{
				this->arr[i][j] = arr[i][j];
			}
		}
	}

	void show()
	{
		for (size_t i = 0; i < LENGTH; i++)
		{
			for (size_t j = 0; j < LENGTH; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}

	bool isSolved()
	{
		int tempArr[LENGTH];
		size_t chk = 0;

		for (size_t i = 0; i < LENGTH; i++)
		{
			for (size_t j = 0; j < LENGTH; j++)
			{
				tempArr[j] = arr[i][j];
			}
			if (isRowSolved(tempArr))
				chk++;
		}

		for (size_t i = 0; i < LENGTH; i++)
		{
			for (size_t j = 0; j < LENGTH; j++)
			{
				tempArr[j] = arr[j][i];
			}
			if (isRowSolved(tempArr))
				chk++;
		}

		return chk == LENGTH * 2;
	}
};

int main()
{

	int arr1[LENGTH][LENGTH] = {
			{3, 0, 6, 5, 0, 8, 4, 0, 0},
			{5, 2, 0, 0, 0, 0, 0, 0, 0},
			{0, 8, 7, 0, 0, 0, 0, 3, 1},
			{0, 0, 3, 0, 1, 0, 0, 8, 0},
			{9, 0, 0, 8, 6, 3, 0, 0, 5},
			{0, 5, 0, 0, 9, 0, 6, 0, 0},
			{1, 3, 0, 0, 0, 0, 2, 5, 0},
			{0, 0, 0, 0, 0, 0, 0, 7, 4},
			{0, 0, 5, 2, 0, 6, 3, 0, 0} };

	int arr2[LENGTH][LENGTH] =
	{ {8, 3, 5, 4, 1, 6, 9, 2, 7},
	 {2, 9, 6, 8, 5, 7, 4, 3, 1},
	 {4, 1, 7, 2, 9, 3, 6, 5, 8},
	 {5, 6, 9, 1, 3, 4, 7, 8, 2},
	 {1, 2, 3, 6, 7, 8, 5, 4, 9},
	 {7, 4, 8, 5, 2, 9, 1, 6, 3},
	 {6, 5, 2, 7, 8, 1, 3, 9, 4},
	 {9, 8, 1, 3, 4, 5, 2, 7, 6},
	 {3, 7, 4, 9, 6, 2, 8, 1, 5} };

	Sudoku s1(arr1);
	Sudoku s2(arr2);
	s1.show();
	cout << endl;
	s2.show();
	cout << endl;

	s1.isSolved() ? cout << "Sudoku 1 Solved" : cout << "Sudoku 1 Not solved";
	cout << endl;
	s2.isSolved() ? cout << "Sudoku 2 Solved" : cout << "Sudoku 2 Not solved";

	return 0;
}
