# Library-Systems-Information
This is a group Project to create a library systems information utilizng several different classes with advance class feature compisiton, and STL containers
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
INSTRUCTIONS: 
- When you are loaded into the program you will be brought to the main menu 
- At the main menu you will be presented with 3 options which are (T/t) to complete a
  transaction of returning or withdrawing a book, (S/s) to search the inventory, or (V/v) to view borrower information. 

- If you click (T/t):
	- You will be then promted to enter either (R/r) to return a book or (W/w) to withdraw a book
	- You will then have to enter the 5 digit borrower id
	- You will then have to enter t he date in (m d y) format
	- You will then have to enter the title of the book
    - If those steps are completed correctly then your desired action will be completed, and a message will be displayed to inform you of that

- If you click (S/s):
	- You will be prompted to enter (A/a) to display all books or (B/b) to search for a specific book
		- If (A/a) is clicked then all the books in the inventory will be printed to the screen
		
		- If (B/b) is clicked:
			- You will be prompted to enter the title of the book, and if the book is in the inventory all of its information will be displayed
- If you click (V/v):
	- You will be prompted to enter (A/a) to add a user, (I/i) to search for a speciifc user, or (E/e) to output entire borrower list
		- If (A/a) is clicked, you will be prompted to enter the borrowers name, address, and their choice of 5 digit ID, and then they will be added to the list
		- If (I/i) is clicked, you will be prompted to enter the borrowers ID, and if it is a valid ID, that users Info will be outputted
		- If (E/e) is clicked the entire list of borrowers will be outputted (could be used to inform someone of their ID)

- No matter which one you click, after that action is finished you will be prompted to enter 1 to go back to the main menu, anything else will terminate the program
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
SOME PROBLEMS WE RAN INTO:
Completing this program was quite fun, but also quite extensive, and slightly diffuclt. One of the main problems we had was insuring each of the classes worked smoothly
with one another while using composition. For example, there was an an instance when we trying to search for a specific objetc in the vectors, but we were not recieving data
from it, and then after some debugging the change that was needed was to return a pointer to the address of the object, and then we were able to pull data from the object. 
Another problem that occured while coding was insuring we were running the proper tests in order to be certain that the program would run well, such as checking if a book
exists, checking if a borrower exists, and making sure dates are valid.   