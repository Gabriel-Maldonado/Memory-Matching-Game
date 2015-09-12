// © copyright 2013  Gabriel Maldonado.  All Rights Reserved.
// Author: Gabriel Maldonado
// Date: 2/08/2013
// Contact:  Gabriel.Maldonado@live.lagcc.cuny.edu
// Description: 	

#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <tchar.h>
using namespace std;

int main ()
{	
	int matrix[4][4] = {{1, 2, 3, 4},{5 ,6, 7, 8},{ 1, 2, 3, 4},{ 5, 6, 7, 8}}; //Set the values for our Matrix array in pairs.
	const int size= 4; //total size of array/16 will give us 4 in height and 4 in width
	int *check[4][4]; //Used for comparing with our matrix array and value1 and value2.
	int row, col; //can be used for pointing and compating numbers in our matrix array.
	int pRow, pCol; //Pointers, for comparing against row and col in our multidimensional array.
	int j, k; 
	int value1, value2; //Used for copying values over and comparing them against one another for redundancy.
	int game; //Used for switching between different segments of our game.
	int intro; //Used for displaying Intro screens
	bool init= false;
	init = true; //initializes our while loop.
	game=0; //Setting game=0 will initialize our game.
	intro=0; //Setting intro=0 Will start our first intro Message.
	srand((unsigned)time(0));  //initialize random seed.

	SetConsoleTitle ( _T("THE MEMORY MATCHING GAME v0.11") ); //Displays the title to our program.

	while (init = true)
	{
		if (game==0) {
			if (intro==0) {
				//Message to display
				cout << "\n\n\n\n";
				cout << "			/////////////////////////////// \n";
				cout << "			///			    /// \n";
				cout << "			/// WINNERS DON'T USE DRUGS /// \n";
				cout << "			///			    /// \n";
				cout << "			/////////////////////////////// \n";
				Sleep(5000); //Parameter in sleep is 5 seconds
				system("CLS");	//Clear the screen
				Sleep(0); //setting sleep to 0
				intro=2; //Set intro=2 and display our Second message.
			} else if (intro==2) {
				//Message to display
				cout << "\n\n\n\n";
				cout << "			//////////////////////////////// \n";
				cout << "			///			     /// \n";
				cout << "			/// The Memory Matching Game /// \n";
				cout << "			///			     /// \n";
				cout << "			//////////////////////////////// \n";
				cout << "			Coded in C++ by Gabriel Maldonado";
				cout << "\n\n\n\n\n\n\n";
				cout << "			      Press a key to start";
				while(game==0) //While game=0, loop will be active.
				{
					if(_kbhit()) //When any key is pressed while our loop is active, we clear the screen and set game=1.
					{
						system("CLS"); //Clear the screen, for next segment to our program.
						game=1; //Setting game=1 will allow our program to different phases in our program.
						intro =0;
					}
				}
			}
		} else if (game==1) {
			j=0;
			pRow=-1;
			pCol=-1;

			//Display Messages, on how to play the game.
			cout << "HOW TO PLAY: \n";
			cout << "Please select two cards by choosing a Row and Column from 0 to 3. \n";
			cout << "If your cards match, you win. Otherwise, please try again. \n\n"; 
			cout << "	x	0	1	2	3 \n";
			cout << "------------------------------------------ \n";
			
			for (int r = 0; r < size; r++)
			{
				for (int c = 0; c < size; c++)
				{
					check[r][c]=&k; //Fill the array with &k, so that we can get zero instead of the address to k.
				}
			}
			
			int temp=NULL;
			for (int r = 0; r < size; r++) //r for rows will increment from 0 to 3
			{
				for (int m = size; m --> 0; m--) //m for rows will decrement from 3 to 0.
				{
					for (int c = 0; c < size; c++) //c for columns will increment from 0 to 3.
					{
						for (int n = size; n --> 0; n--) //n for columns will decrement from 3 to 0.
						{
							//Will randomly seed the positions to numbers in our matrix array.
							r = (rand() % 4); c = (rand() % 4); m = (rand() % 4); n = (rand() % 4);
							//Our swap code
							temp=matrix[r][c]; //For each row and column, we copy over the value from our matrix to temp
							matrix[r][c]= matrix[m][n]; //Copy over the points of matrix m (row) and n (column) to the pointed rows and columns of r and c in our matrix.
							matrix[m][n]=temp; //We copy of temp to our matrix in reverse order of m and n.
						}
					}
				}
			}

			for (row = 0; row < size; row++)
			{
				cout << "	" <<  row << " |";
				for (col=0; col < size; col++)
				{
					if (matrix[row][col] !=NULL) //if the matrix's row and column's array is not NULL (nothing or 0), then display astericks to hide our matching pairs.
					{
						cout << "	*"; //used for hiding all of our pairs
						//cout << "	" << matrix[row][col]  << "  "; //Used for making our secret random numbers visible (for debugging purposes only).
					}
				}
				cout << endl; //break a line after a column is completed.
			}
			game = 2; //setting game=1 will allow the game to continue.

		} else if (game==2) {	
			if (!(pRow < 0 && pCol < 0)) 
			{	
				cout << "HOW TO PLAY: \n";
				cout << "Please select two cards by choosing a Row and Column from 0 to 3. \n";
				cout << "If your cards match, you win. Otherwise, please try again. \n\n"; 
				cout << "	x	0	1	2	3 \n";
				cout << "------------------------------------------ \n";

				for (row = 0; row < size; row++)
				{
					cout << "	" <<  row << " |";
					for (col=0; col <size; col++)
					{	
						if (pRow == row && pCol ==col) { //if the selected input matches, we copy our matrix to the specified row and column in our check array.
							check[pRow][pCol] = &matrix[row][col]; //We copy over the pointed number from our matrix along with its address to our check array.
						}
						//When we compare both multidimensional arrays, we compare the values of these two arrays.
						if (check[row][col] == &matrix[row][col]) { //Since the value is present in our matrix array, we need to compare it with our check array to see if the value exist there as well. If the value does is exist, we show the value. Otherwise, we display an asterick symbol indicating that its not.	
							cout << "	" << *check[row][col] << "  ";	//Here we use a pointer, so that we won't get the address of the specified value and only its value.
						} else { 
							cout << "	*"; //else we show an asterick, hiding the rest of our numbers.
						}

						if (check[pRow][pCol]== &matrix[row][col]) //if the address is equal to the pointed matrix array in our check array, we then conclude that it's a unique value when compared to other numbers that may have the same number but different addresses.
						{
							for (int r = 0; r < size; r++)
							{
								for (int c = 0; c < size; c++)
								{
									//We first check to see if our pointed row and columns are equal to r & c. Further more, we validate its authenticity by comparing the addresses in our matrix with check array to validate its uniqueness. Finally, we set j=1 so that we can insert the first value into our first instance. When we've successfully inserted a value into our first instance, we modify j to j=2 and do the same for our second instance. Thus, preventing any overwrites to our first value and/or second value.
									if (pRow == r && pCol ==c && check[pRow][pCol]== &matrix[r][c] && j==0) {
										value1 = *check[r][c]; 
										j=1; 
										break;
									}
									if (pRow == r && pCol ==c && check[pRow][pCol]== &matrix[r][c] && j==1) {
										value2 = *check[r][c]; 
										j=2; 
										break;
									}
								}
							}			
						} 
					}
					cout << endl;
				}
			}
		//After we have a valid choice for value1 and value2, we proceed with comparing them; to do so, j must be greater than 1. Otherwise, we skip the comparison until we have the second value when j is actually more than 1.
		if (j > 1) { 
			if (value1 && value2==value1 && value1 == value2) { //for sanity purposes, we use a simple test to compare if the values truly are the same, as value1 and value2 must be equal to themselves. 
				cout << endl << "Correct! Select your next pair." << endl; 	
				value1 = NULL;
				value2 = NULL;
				j=0; //set j=0 and perform the test again.
			} else if (value1 && value2!=value1 && value1 != value2) { //Likewise, when they're not equal, we compare them against themselves.
					cout << endl << "Incorrect! Please try again." << endl; 	
					for (int r = 0; r < size; r++)
					{
						for (int c = 0; c < size; c++)
						{
						//if the values when compared are incorrect, we use the addresses of value1 and value2 and compare it against our check array until we have the address to that specified value. Once we have the address, we zero out the value with &k.
							if (*check[r][c] ==value1) {
								check[r][c] = &k;
							}

							if (*check[r][c] ==value2) {
								check[r][c] = &k;
							}
						}
					}
				j=0; //set j=0 and perform the test again.
			}		
		}	
		int numberOfSet = 0;
		for (int r = 0; r < size; r++)
		{
			for (int c = 0; c < size; c++)
			{
				if (!(check[r][c] == &k)) //We compare check with the address of &k, if the address of check is not equal to k, then we and proceed with selecting another pair. Otherwise increase numberOfset to indicate that the specified position in the array has a value.
				{ 
					numberOfSet++;
				} else {
					cout << "Please Select Row number from 0 to 3: ";
					cin >> pRow;	
					cout << "You selected: " << pRow << endl;

					cout << "Please Select Col number from 0 to 3: ";
					cin >> pCol;	
					cout << "You selected: " << pCol << endl;
		
					if (!(pRow < 4 && pCol < 4 && pRow >= 0 && pCol >= 0)) { //
						system("CLS");
						cout << "Row: " << pRow << " and Column: " << pCol << " exceeds the given boundaries. Please try again! \n\n";
					} else {
						system("CLS");
					}
					//so we can break out of the for loop we set both r and c to size.
					r = size;
					c = size;
				}
					
				if (numberOfSet >=16) { //if check array is filled with valid numbers, we display a message and restart the game.
					system("CLS");
					cout << "\n\n\n\n";
					cout << "			/////////////////////////////// \n";
					cout << "			///			    /// \n";
					cout << "			/// Congratulations! You've won! /// \n";
					cout << "			///			    /// \n";
					cout << "			/////////////////////////////// \n";
					Sleep(5000); //Parameter in sleep is 5 seconds
					system("CLS");
					numberOfSet=0;
					game = 1; //When all pairs have been matched, we restart the game by setting game=1 (can also be set to 0, doing so will show the game intro).
				}
			}
		}			
	}
}
return 0;
}