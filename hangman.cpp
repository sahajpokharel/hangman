#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <conio.h>
#include <windows.h>

using namespace std;

int main();

class words{
	
	string word;
	
	public:
		
		words()
		{
			srand(time(0));
			int word_index = 1 + (rand() % 500);
			
			ifstream wordfile;
			wordfile.open("words.txt");
			
			if(!wordfile.is_open())
			{
				cout<<"Sorry, unable to generate a word."<<endl;
				exit(1);
			}
		    
			int current_line = 0;
		    
			while (getline(wordfile, word)) 
			{
		    	current_line++;
		        
				if (current_line == word_index)
		        	break;
		    }
		    
			wordfile.close();
		}
		
		
		void play_game()
		{
		    char letter, letters_and_blanks[word.length()], wrong_guesses[8] = {};
		    int wrong_attempts = 0, blanks = word.length(), i = 0;
		    bool complete;
		
		    for (i = 0; i < word.length(); i++)
		        letters_and_blanks[i] = '_';
		
		    while (1)
		    {
		        bool valid_input = false;
		        
				while (!valid_input)
		        {
		            display_hangman(wrong_attempts, letters_and_blanks, wrong_guesses);
		            cout << endl << endl << "Enter letter: ";
		            cin >> letter;
		            
					if (toupper(letter) >= 65 && toupper(letter) <= 90)
		                valid_input = true;
		            
					else
		                system("cls");
		        }
		
		        int new_blanks = blanks;
		
		        for (i = 0; i < word.length(); i++)
		        {
		            if (word[i] == toupper(letter))
		            {
		                letters_and_blanks[i] = toupper(letter);
		                blanks--;
		            }
		        }
		
		        if (new_blanks == blanks)
		        {
		            bool already_guessed = false;
		            
					for (i = 0; wrong_guesses[i] != '\0'; i++)
		            {
		                if (wrong_guesses[i] == letter)
		                {
		                    already_guessed = true;
		                    break;
		                }
		            }
		
		            if (!already_guessed)
		            {
		                wrong_guesses[wrong_attempts] = letter;
		                wrong_attempts++;
		            }
		
		            continue;
		        }
		
		        complete = true;
		        
				for (i = 0; i < word.length(); i++)
		        {
		            if (letters_and_blanks[i] == '_')
		            {
		                complete = false;
		                break;
		            }
		        }
		
		        if (complete)
		            break;
		    }
		
		    if (complete)
		    {
		        display_hangman(wrong_attempts, letters_and_blanks, wrong_guesses);
		        cout << endl << endl << "CORRECT!\n\nYou Win";
		        end_game();
		    }
		}


		void display_hangman(int wrong_attempts, string letters_and_blanks, char wrong_guesses[])
		{
			if (wrong_attempts == 0)
			{
				system("cls");
				
				cout<<"\n\n\n\n\n\n\n\n\n\n";
				cout<<letters_and_blanks;
				cout<<endl<<endl<<"Invalid letters: ";
			}
			
			else if (wrong_attempts == 1)
			{
				system("cls");
				
				cout<<"=========="<<endl;
		    	cout<<"\n\n\n\n\n\n\n\n\n";
				cout<<letters_and_blanks;
				cout<<endl<<endl<<"Invalid letters: "<<wrong_guesses[0];
			}
			
			else if (wrong_attempts == 2)
			{
				system("cls");
				
				cout<<"=========="<<endl;
				cout<<"    |"<<endl;
		    	cout<<"    |"<<endl;
		    	cout<<"\n\n\n\n\n\n\n";
				cout<<letters_and_blanks;
				cout<<endl<<endl<<"Invalid letters: "<<wrong_guesses[0]<<" "<<wrong_guesses[1];
			}
			
			else if (wrong_attempts == 3)
			{
				system("cls");
				
				cout<<"=========="<<endl;
				cout<<"    |"<<endl;
		    	cout<<"    |"<<endl;
				cout<<"    O"<<endl;
		    	cout<<"\n\n\n\n\n\n";
				cout<<letters_and_blanks;
				cout<<endl<<endl<<"Invalid letters: "<<wrong_guesses[0]<<" "<<wrong_guesses[1]<<" "<<wrong_guesses[2];
			}
		    
			else if (wrong_attempts == 4)
		    {
		    	system("cls");
				
				cout<<"=========="<<endl;
				cout<<"    |"<<endl;
		    	cout<<"    |"<<endl;
				cout<<"    O"<<endl;
				cout<<"    |"<<endl;
				cout<<"    |";
		    	cout<<"\n\n\n\n";
				cout<<letters_and_blanks;
				cout<<endl<<endl<<"Invalid letters: "<<wrong_guesses[0]<<" "<<wrong_guesses[1]<<" "<<wrong_guesses[2]<<" "<<wrong_guesses[3];
			}
			
			else if (wrong_attempts == 5)
			{
				system("cls");
				
				cout<<"=========="<<endl;
				cout<<"    |"<<endl;
		    	cout<<"    |"<<endl;
				cout<<"    O"<<endl;
				cout<<"   /|"<<endl;
				cout<<"    |";
		    	cout<<"\n\n\n\n";
				cout<<letters_and_blanks;
				cout<<endl<<endl<<"Invalid letters: "<<wrong_guesses[0]<<" "<<wrong_guesses[1]<<" "<<wrong_guesses[2]<<" "<<wrong_guesses[3]<<" "<<wrong_guesses[4];
			}
			
			else if (wrong_attempts == 6)
			{
				system("cls");
				
				cout<<"=========="<<endl;
				cout<<"    |"<<endl;
		    	cout<<"    |"<<endl;
				cout<<"    O"<<endl;
				cout<<"   /|\\"<<endl;
				cout<<"    |";
		    	cout<<"\n\n\n\n";
				cout<<letters_and_blanks;
				cout<<endl<<endl<<"Invalid letters: "<<wrong_guesses[0]<<" "<<wrong_guesses[1]<<" "<<wrong_guesses[2]<<" "<<wrong_guesses[3]<<" "<<wrong_guesses[4]<<" "<<wrong_guesses[5];
			}
			
			else if (wrong_attempts == 7)
			{
				system("cls");
				
				cout<<"=========="<<endl;
				cout<<"    |"<<endl;
		    	cout<<"    |"<<endl;
				cout<<"    O"<<endl;
				cout<<"   /|\\"<<endl;
				cout<<"    |"<<endl;
				cout<<"   /"<<endl;
		    	cout<<"\n\n\n";
				cout<<letters_and_blanks;
				cout<<endl<<endl<<"Invalid letters: "<<wrong_guesses[0]<<" "<<wrong_guesses[1]<<" "<<wrong_guesses[2]<<" "<<wrong_guesses[3]<<" "<<wrong_guesses[4]<<" "<<wrong_guesses[5]<<" "<<wrong_guesses[6];
			}
			
			else if (wrong_attempts == 8)
			{
				system("cls");
				
				cout<<"=========="<<endl;
				cout<<"    |"<<endl;
		    	cout<<"    |"<<endl;
				cout<<"    O"<<endl;
				cout<<"   /|\\"<<endl;
				cout<<"    |"<<endl;
				cout<<"   / \\"<<endl;
		    	cout<<"\n\n\n";
				cout<<letters_and_blanks;
				cout<<endl<<endl<<"Invalid letters: "<<wrong_guesses[0]<<" "<<wrong_guesses[1]<<" "<<wrong_guesses[2]<<" "<<wrong_guesses[3]<<" "<<wrong_guesses[4]<<" "<<wrong_guesses[5]<<" "<<wrong_guesses[6]<<" "<<wrong_guesses[7];
				cout<<endl<<endl<<"The word was: "<<word<<"!\n\nYou Lose";
				
				end_game();
			}
		}
		
		
		void end_game()
		{
			char choice;
			
			cout<<endl<<endl<<"[1] Play a new game\n[2] Exit the game";
			
			do
			{
				choice = getch();
				
				if(choice == '1')
				{
					system("cls");
					main();
				}
				
				else if(choice == '2')
				{
					system("cls");
					
					cout<<endl<<endl<<"\t\t\tThanks for playing hangman\n\t\tVisit github.com/sahajpokharel for more games!";
					
					Sleep(2000);
					exit(1);
				}
			
			}while(choice!='1'||choice!='2');
		}
};


int main()
{
	words w;
	
	w.play_game();
	
	return 0;
}
