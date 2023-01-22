#include <iostream>
using namespace std;

// so for this one we need to input 2 intergers first is how many puzzles and the second is how many rounds
// there will be 4 inputs from 4 players.
// player 1 and 2 are together and 3 and 4 are together and the product of the two is what will be 
// be subracted to the total jigsaw puzzle..
int main() {
	
	int piece, rounds;
    cout << "Number of jigsaw puzzle to be destroyed:" ;
    cin >> piece;
    cout << "Enter the number of roudns" ;
    cin >> rounds; 
	if ((piece > 0 && piece <= 1000000) && (rounds > 0 && rounds <= 1000000)) {
			//cout << "Entering the numbers 1-6" << endl;
			int p1, p2, p3, p4;
			int total1 = 0, total2 = 0;
			int  counter= 0;
			
			for (int i = 0; i < rounds; i++) {
				cin >> p1 >> p2 >> p3 >> p4;
					total1 += p1 * p2;
					total2 += p3 * p4;
                    counter++;
                    if (total1 >= piece && total2 >= piece){
                        cout << "It's a tie at round " << counter << "!";
                        break;
                    }
                    else if(total1 >= piece && total2 < piece){
                        cout << "Team 1 wins at round " << counter << "!";
                        break;
                    }
                    else if(total2 >= piece && total1 < piece){
                        cout << "Team 2 wins at round " << counter << "!";
                        break;
                    }
                    else if(counter == rounds && total1 < piece && total2 < piece ){
                        cout << "Oh no!";
                        break;
                    }


			}


	}
	

	return 0;
}