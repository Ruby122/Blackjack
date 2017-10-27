//Yiqing Zhang
#include <stdio.h>
int getCardNumber();
int getCardSum(int);

int main(){
	char tryAgain, extraChar;
	int num, score;
	//loop forever until the user exits the program
	/*for(;;) and while(1) for creating infinite loops.*/
	while(1){
		num = getCardNumber();
		// if num is in the range
		if(num != 0){
			score = getCardSum(num);
			//if all faces of the cards are valid input
			if(score != 0){
				//different formats for different scores
				if(score < 21){
					printf("\nThe value of your hand = %d\n", score);	
				}
				else if(score == 21){
					printf("\nThe value of your hand = %d --> Blackjack\n", score);
				}
				else{
					printf("\nThe value of your hand = %d --> Busted\n", score);	
				}	
			}
		}
		printf("Type Y or y to try again: ");
		scanf(" %c", &tryAgain);
		//read every char after tryAgain until it is a whitespace that can be ignored when reading next input
		scanf("%c", &extraChar);
		// != ' ' not working: always running
		while(extraChar != 10){
			scanf("%c", &extraChar);
		}	
		printf("You typed: %c\n", tryAgain);
		//terminate the infinite while loop if the user types anything EXCEPT 'y' or 'Y'	
		if(tryAgain != 'Y' && tryAgain != 'y'){
			break;
		}
	}
	return 0;
}

//get the number of cards and check whether it is in the range
int getCardNumber(){
	int numberOfCards;
	//declare characters after first non-whitespace character is provided when reading card number 
	char extraChar;
	printf("Enter a number of cards (2-5): ");
	//read the first non-whitespace char as number of the cards
	scanf(" %d", &numberOfCards);
	//read every char after the numOfCards until it is a whitespace that can be ignored when reading next input
	scanf("%c", &extraChar);
	while(extraChar != 10){
		scanf("%c", &extraChar);
	}
	if(numberOfCards > 5 || numberOfCards < 2){
		printf("Error message: the number of cards is out of range.\n");
		return 0;
	}
	else{
		printf("Number of cards entered: %d", numberOfCards);
		return numberOfCards;
	}
}

//get faces of cards and calculate the score of 2,3,4,or 5 cards
int getCardSum(int numOfCards){
	int sum = 0, numOfAce = 0;
	printf("\n Enter the faces of the cards, 2-9, t, j, q, k, a: ");
	
	// Variables cannot be declared in a switch statement
	// a label can only be part of a statement and a declaration is not a statement (error message for declaring char c1 c2 in case 2
	/*Case statements are only labels. In C declarations are not statements.*/
	char c1, c2, c3, c4, c5, extraChar;
	switch(numOfCards){
		case 2: // read the first two non-whitespce chars ignoring all whitespaces
			scanf(" %c %c", &c1, &c2);
			//read every char after c2 until it is a whitespace that can be ignored when reading next input
			scanf("%c", &extraChar);
			while(extraChar != 10){
				scanf("%c", &extraChar);
			}
			printf("Faces of cards entered: %c %c", c1, c2);
			//calculate the value of the 1st card			
			if(c1 == 'a' || c1 == 'A'){
				numOfAce++;
			}
			else if (c1 == '2' || c1 == '3' || c1 == '4' || c1 == '5' || c1 == '6' || c1 == '7' || c1 == '8' ||c1 == '9'){
				sum += c1 - 48;//'2' = 50 and value of 2 in the game is 2		
			}
			else if (c1 == 't' || c1 == 'T' || c1 == 'j' || c1 == 'J' || c1 == 'q' || c1 == 'Q' || c1 == 'k'|| c1 == 'K'){
				sum += 10;// value of 10, 11, 12, and 13 in the game is 10
			}
			else{
				printf("\nInvalid input for faces of the cards.");
				return 0;
			}
			// calculate the value of the 2nd card		
			if(c2 == 'a' || c2 == 'A'){
				numOfAce++;
			}
			else if (c2 == '2' || c2 == '3' || c2 == '4' || c2 == '5' || c2 == '6' || c2 == '7' || c2 == '8' ||c2 == '9'){
				sum += c2 - 48;//'2' = 50 and value of 2 in the game is 2		
			}
			else if (c2 == 't' || c2 == 'T' || c2 == 'j' || c2 == 'J' || c2 == 'q' || c2 == 'Q' || c2 == 'k'|| c2 == 'K'){
				sum += 10;// value of 10, 11, 12, and 13 in the game is 10
			}
			else{
				printf("\nInvalid input for faces of the cards.");
				return 0;
			}
			// calculate proper value for ace cards: the loop below works for 2 cards but not for more than 2
			// Better solution: count all aces as 11 and then subtract 10 until we run out of ace number
			while(numOfAce > 0){
				//if one ace is counted 11 and then we get a busted score, all aces should be counted as 1
				if(sum + 11 > 21){
					sum += numOfAce;
					break;
				}
				// Consider the situation: 10 A A - we got busted score finally since we count 1 ace as 11
				// fix for the while loop we wrote: add an if block - if there is at least one ace and sum > 21 we subtract 10 from the score
				else{
					sum += 11;
				}
				numOfAce--;
			}
			break;
		case 3: scanf(" %c %c %c", &c1, &c2, &c3);
			//read every char after c3 until it is a whitespace that can be ignored when reading next input
			scanf("%c", &extraChar);
			while(extraChar != 10){
				scanf("%c", &extraChar);
			}
			printf("Faces of cards entered: %c %c %c", c1, c2, c3);
			//calculate the value of the 1st card			
			if(c1 == 'a' || c1 == 'A'){
				numOfAce++;
			}
			else if (c1 == '2' || c1 == '3' || c1 == '4' || c1 == '5' || c1 == '6' || c1 == '7' || c1 == '8' ||c1 == '9'){
				sum += c1 - 48;//'2' = 50 and value of 2 in the game is 2		
			}
			else if (c1 == 't' || c1 == 'T' || c1 == 'j' || c1 == 'J' || c1 == 'q' || c1 == 'Q' || c1 == 'k'|| c1 == 'K'){
				sum += 10;// value of 10, 11, 12, and 13 in the game is 10
			}
			else{
				printf("\nInvalid input for faces of the cards.");
				return 0;
			}
			// calculate the value of the 2nd card		
			if(c2 == 'a' || c2 == 'A'){
				numOfAce++;
			}
			else if (c2 == '2' || c2 == '3' || c2 == '4' || c2 == '5' || c2 == '6' || c2 == '7' || c2 == '8' ||c2 == '9'){
				sum += c2 - 48;//'2' = 50 and value of 2 in the game is 2		
			}
			else if (c2 == 't' || c2 == 'T' || c2 == 'j' || c2 == 'J' || c2 == 'q' || c2 == 'Q' || c2 == 'k'|| c2 == 'K'){
				sum += 10;// value of 10, 11, 12, and 13 in the game is 10
			}
			else{
				printf("\nInvalid input for faces of the cards.");
				return 0;
			}
			// calculate the value of the 3rd card		
			if(c3 == 'a' || c3 == 'A'){
				numOfAce++;
			}
			else if (c3 == '2' || c3 == '3' || c3 == '4' || c3 == '5' || c3 == '6' || c3 == '7' || c3 == '8' ||c3 == '9'){
				sum += c3 - 48;//'2' = 50 and value of 2 in the game is 2		
			}
			else if (c3 == 't' || c3 == 'T' || c3 == 'j' || c3 == 'J' || c3 == 'q' || c3 == 'Q' || c3 == 'k'|| c3 == 'K'){
				sum += 10;// value of 10, 11, 12, and 13 in the game is 10
			}
			else{
				printf("\nInvalid input for faces of the cards.");
				return 0;
			}
			// calculate proper value for ace cards
			// Count all aces as 11 and then take 10 out of sum until the score is not busted
			sum += (11 * numOfAce);			
			while (sum > 21 && numOfAce > 0){
				sum -= 10;
				numOfAce--;
			}
			break;
		case 4: scanf(" %c %c %c %c", &c1, &c2, &c3, &c4);
			//read every char after c4 until it is a whitespace that can be ignored when reading next input
			scanf("%c", &extraChar);
			while(extraChar != 10){
				scanf("%c", &extraChar);
			}
			printf("Faces of cards entered: %c %c %c %c", c1, c2, c3, c4);
			//calculate the value of the 1st card			
			if(c1 == 'a' || c1 == 'A'){
				numOfAce++;
			}
			else if (c1 == '2' || c1 == '3' || c1 == '4' || c1 == '5' || c1 == '6' || c1 == '7' || c1 == '8' ||c1 == '9'){
				sum += c1 - 48;//'2' = 50 and value of 2 in the game is 2		
			}
			else if (c1 == 't' || c1 == 'T' || c1 == 'j' || c1 == 'J' || c1 == 'q' || c1 == 'Q' || c1 == 'k'|| c1 == 'K'){
				sum += 10;// value of 10, 11, 12, and 13 in the game is 10
			}
			else{
				printf("\nInvalid input for faces of the cards.");
				return 0;
			}
			// calculate the value of the 2nd card		
			if(c2 == 'a' || c2 == 'A'){
				numOfAce++;
			}
			else if (c2 == '2' || c2 == '3' || c2 == '4' || c2 == '5' || c2 == '6' || c2 == '7' || c2 == '8' ||c2 == '9'){
				sum += c2 - 48;//'2' = 50 and value of 2 in the game is 2		
			}
			else if (c2 == 't' || c2 == 'T' || c2 == 'j' || c2 == 'J' || c2 == 'q' || c2 == 'Q' || c2 == 'k'|| c2 == 'K'){
				sum += 10;// value of 10, 11, 12, and 13 in the game is 10
			}
			else{
				printf("\nInvalid input for faces of the cards.");
				return 0;
			}
			// calculate the value of the 3rd card		
			if(c3 == 'a' || c3 == 'A'){
				numOfAce++;
			}
			else if (c3 == '2' || c3 == '3' || c3 == '4' || c3 == '5' || c3 == '6' || c3 == '7' || c3 == '8' ||c3 == '9'){
				sum += c3 - 48;//'2' = 50 and value of 2 in the game is 2		
			}
			else if (c3 == 't' || c3 == 'T' || c3 == 'j' || c3 == 'J' || c3 == 'q' || c3 == 'Q' || c3 == 'k'|| c3 == 'K'){
				sum += 10;// value of 10, 11, 12, and 13 in the game is 10
			}
			else{
				printf("\nInvalid input for faces of the cards.");
				return 0;
			}
			// calculate the value of the 4th card		
			if(c4 == 'a' || c4 == 'A'){
				numOfAce++;
			}
			else if (c4 == '2' || c4 == '3' || c4 == '4' || c4 == '5' || c4 == '6' || c4 == '7' || c4 == '8' ||c4 == '9'){
				sum += c4 - 48;//'2' = 50 and value of 2 in the game is 2		
			}
			else if (c4 == 't' || c4 == 'T' || c4 == 'j' || c4 == 'J' || c4 == 'q' || c4 == 'Q' || c4 == 'k'|| c4 == 'K'){
				sum += 10;// value of 10, 11, 12, and 13 in the game is 10
			}
			else{
				printf("\nInvalid input for faces of the cards.");
				return 0;
			}
			// calculate proper value for ace cards
			sum += (11 * numOfAce);			
			while (sum > 21 && numOfAce > 0){
				sum -= 10;
				numOfAce--;
			}
			break;
		case 5: scanf(" %c %c %c %c %c", &c1, &c2, &c3, &c4, &c5);
			//read every char after c4 until it is a whitespace that can be ignored when reading next input
			scanf("%c", &extraChar);
			while(extraChar != 10){
				scanf("%c", &extraChar);
			}
			printf("Faces of cards entered: %c %c %c %c %c", c1, c2, c3, c4, c5);
			//calculate the value of the 1st card			
			if(c1 == 'a' || c1 == 'A'){
				numOfAce++;
			}
			else if (c1 == '2' || c1 == '3' || c1 == '4' || c1 == '5' || c1 == '6' || c1 == '7' || c1 == '8' ||c1 == '9'){
				sum += c1 - 48;//'2' = 50 and value of 2 in the game is 2		
			}
			else if (c1 == 't' || c1 == 'T' || c1 == 'j' || c1 == 'J' || c1 == 'q' || c1 == 'Q' || c1 == 'k'|| c1 == 'K'){
				sum += 10;// value of 10, 11, 12, and 13 in the game is 10
			}
			else{
				printf("\nInvalid input for faces of the cards.");
				return 0;
			}
			// calculate the value of the 2nd card		
			if(c2 == 'a' || c2 == 'A'){
				numOfAce++;
			}
			else if (c2 == '2' || c2 == '3' || c2 == '4' || c2 == '5' || c2 == '6' || c2 == '7' || c2 == '8' ||c2 == '9'){
				sum += c2 - 48;//'2' = 50 and value of 2 in the game is 2		
			}
			else if (c2 == 't' || c2 == 'T' || c2 == 'j' || c2 == 'J' || c2 == 'q' || c2 == 'Q' || c2 == 'k'|| c2 == 'K'){
				sum += 10;// value of 10, 11, 12, and 13 in the game is 10
			}
			else{
				printf("\nInvalid input for faces of the cards.");
				return 0;
			}
			// calculate the value of the 3rd card		
			if(c3 == 'a' || c3 == 'A'){
				numOfAce++;
			}
			else if (c3 == '2' || c3 == '3' || c3 == '4' || c3 == '5' || c3 == '6' || c3 == '7' || c3 == '8' ||c3 == '9'){
				sum += c3 - 48;//'2' = 50 and value of 2 in the game is 2		
			}
			else if (c3 == 't' || c3 == 'T' || c3 == 'j' || c3 == 'J' || c3 == 'q' || c3 == 'Q' || c3 == 'k'|| c3 == 'K'){
				sum += 10;// value of 10, 11, 12, and 13 in the game is 10
			}
			else{
				printf("\nInvalid input for faces of the cards.");
				return 0;
			}
			// calculate the value of the 4th card		
			if(c4 == 'a' || c4 == 'A'){
				numOfAce++;
			}
			else if (c4 == '2' || c4 == '3' || c4 == '4' || c4 == '5' || c4 == '6' || c4 == '7' || c4 == '8' ||c4 == '9'){
				sum += c4 - 48;//'2' = 50 and value of 2 in the game is 2		
			}
			else if (c4 == 't' || c4 == 'T' || c4 == 'j' || c4 == 'J' || c4 == 'q' || c4 == 'Q' || c4 == 'k'|| c4 == 'K'){
				sum += 10;// value of 10, 11, 12, and 13 in the game is 10
			}
			else{
				printf("\nInvalid input for faces of the cards.");
				return 0;
			}
			// calculate the value of the 5th card		
			if(c5 == 'a' || c5 == 'A'){
				numOfAce++;
			}
			else if (c5 == '2' || c5 == '3' || c5 == '4' || c5 == '5' || c5 == '6' || c5 == '7' || c5 == '8' ||c5 == '9'){
				sum += c5 - 48;//'2' = 50 and value of 2 in the game is 2		
			}
			else if (c5 == 't' || c5 == 'T' || c5 == 'j' || c5 == 'J' || c5 == 'q' || c5 == 'Q' || c5 == 'k'|| c5 == 'K'){
				sum += 10;// value of 10, 11, 12, and 13 in the game is 10
			}
			else{
				printf("\nInvalid input for faces of the cards.");
				return 0;
			}
			// calculate proper value for ace cards
			sum += (11 * numOfAce);			
			while (sum > 21 && numOfAce > 0){
				sum -= 10;
				numOfAce--;
			}
			break;
	}
	return sum;
}




	
