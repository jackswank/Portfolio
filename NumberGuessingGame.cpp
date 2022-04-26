/*
JACK SWANK
Program Description: Number guessing game with a random number generator introduction to class member functions, private and public member variables mutator and accessor functions.
 *************************************************************/
#include <iostream> //standard library for i/o
#include <string> // string class
#include <ctime> //random number generator
using namespace std;
/*********************************************************
 //Following is the declaration of numberGuess
 **********************************************************/
class numberGuess
{
public:
     //constructor
     numberGuess();
     
     //these functions are public so they can be accessed by non-member functions
     void SetUpperRange(int); //sets the upper range for the round (mutator)
     int  GetUpperRange()const; //returns the value of the private member variable (accessor)
     void SetNumGuesses(int);//sets the number of guesses for the round (mutator)
     int  GetNumGuesses()const;//returns the value of the private member variable (accessor)
     int  GetSolution()const; //returns the value of the private member variable (accessor)
      
     void GuessInput(); //gets the next guess from the user
     bool ProcessGuess(); //determines if the guess is right or wrong
     void GenerateSolution(); //generates the solution
      
     int small;//lowest value for feedback
     int large;//highest value for feedback
     bool above;//current guess above the solution
     bool below;//current guess below the solution
  
private:
     int upperValue;//15, 50, or 150
     int numGuesses;//4, 6, or 8
     int currentGuess;//current guess input by the user
     int solution;//pseudo random generated number
};
//MEMBER FUNCTION DEFINTIONS GO HERE
//the default constructor is called when and object of
//numberGuess is delared
numberGuess::numberGuess()
{
    //cout << "The default constructor has been called\n";
    upperValue = 0;
    //initialize all member variables here
    small = 0;//lowest value for feedback
    large = 0;//highest value for feedback
    above = false;//current guess above the solution
    below = false;//current guess below the solution
    numGuesses = 0;//4, 6, or 8
    currentGuess = 0;//current guess input by the user
    solution = 0;//pseudo random generated number
}
void numberGuess::SetUpperRange(int upper)
//mutator function
//Description:  sets the upper value of the current round
{
    upperValue = upper;
}
int  numberGuess::GetUpperRange()const
//accessor function
//Description:  returns the upper value(private member variable)
{
    return upperValue;
}
void numberGuess::SetNumGuesses(int num)
//Description:  Sets the number of guesses for the current round.
{
    numGuesses = num;
}
//ADD THE REST OF THE MEMBER FUNCTIONS HERE
int numberGuess::GetNumGuesses()const
//returns the value of the private member variable (accessor)
{
    return numGuesses;
}
int numberGuess::GetSolution()const
//returns the value of the private member variable (accessor)
{
    return solution;
}
void numberGuess::GuessInput()
//gets the next guess from the user
{
    if (below)
    {
        if (small < currentGuess)
        {
            small = currentGuess;
        }
    }
    if (above)
    {
        if (large > currentGuess)
        {
            large = currentGuess;
        }
    }
    cout << "\nEnter a guess between " << small << " and " << large << " : ";
    //get the guess
    cin >> currentGuess;
}
bool numberGuess::ProcessGuess()
//determines if the guess is right or wrong
{
    if (currentGuess > solution)
    {
        cout << "\nYour guess was too high.";
        cout << "\n-----------------------";
        above = true;
        return false;
    }
    else if (currentGuess < solution)
    {
        cout << "\nYour guess was too low.";
        cout << "\n-----------------------";
        below = true;
        return false;
    }
    else
    {
        cout << "\nYour guess matches the solution.";
        cout << "\n-----------------------";
        return true;
    }
}
void numberGuess::GenerateSolution()
//generates the solution
{
    srand((unsigned)time(0));
    solution = 1 + rand() % upperValue;
    //cout << "\nSolution is " << currentGame.solution << endl;
}
//FUNCTION PROTOTYPES
//function prototype for PlayOneRound NOT a member function
void PlayOneRound(const string&, numberGuess&);
//Precondition: User name is entered and the user selected that they want to play the game
//Postcondition: Game is played by user
//Description:  Play one round of the number guess game
//function prototype for SetUpLevel NOT a member function
void SetUpLevel(numberGuess&);
//Precondition: The game is started to be played by the user
//Postcondition: A level for the user to play is selected
//Description:  User is given a choice of different levels to play

//main function
int main()
{
    string name;
    string yesOrNo;
    
    //declare variables and the currentGame
    numberGuess currentGame;
    cout << "Enter your first name: ";
    cin >> name;
    cout << "Hi " << name << ", do you want to play the guessing game? (y(Y) or n(N)): ";
    cin >> yesOrNo;
    //while begin loop
    while (yesOrNo != "n" && yesOrNo !=  "N")
    {
        PlayOneRound(name, currentGame);
        
        cout << "Do you want to play another round? (y(Y) or n(N)): ";
        cin >> yesOrNo;
    }
    return  0;
    
}

//HERE IS THE PlayOneRound function
//The following 2 functions are not member functions
//to help understand private member variables
//use accessor and mutator functions
void PlayOneRound(const string& name, numberGuess& currentGame)
//Description:  Play one round of the number guess game
{
    //initalize bool values (public member variables)
    currentGame.above = 0;
    currentGame.below = 0;
    //set the upper range based on the level (LevelRange function)
    SetUpLevel(currentGame);
    cout << "\nYou will have " << currentGame.GetNumGuesses() << " guesses, Good Luck!" << endl;
    //initialize high and low values
    currentGame.small = 1;
    currentGame.large = currentGame.GetUpperRange(); //accessor function
    //generate the random number
    currentGame.GenerateSolution();
    //loop(number of guesses)
    for(int i = 0; i < currentGame.GetNumGuesses(); i++)
    {
        cout << "\nThis is guess number (" << i + 1 << " of " << currentGame.GetNumGuesses() << ")";
        currentGame.GuessInput();
        //reset above and below bool values to false
        currentGame.below = 0;
        currentGame.above = 0;
        if (currentGame.ProcessGuess())
        {
            cout << "\nYou won that round, " << name << "!\n";
            i = currentGame.GetNumGuesses();
        }
    }
    cout << "\nThe solution was " << currentGame.GetSolution() << endl;
}
void SetUpLevel(numberGuess& currentGame)
//Asks and gets the level and sets up one round of the game
{
    int level;
    do{
        //display and get the levels
        cout << "What level (Enter 1, 2, or 3)? \n(1) Level 1 - 4 guesses, numbers 1 through 15 \n(2) Level 2 - 6 guesses, numbers 1 through 50 \n(3) Level 3 - 8 guesses, numbers 1 through 150: ";
        cin >> level;
    } while (level > 3 || level < 1);
    if (level == 1)
    {
        //mutator functions
        currentGame.SetNumGuesses(4);
        currentGame.SetUpperRange(15);
    }
    //add conditions for levels 2 and 3
    else if (level == 2)
    {
        //mutator functions
        currentGame.SetNumGuesses(6);
        currentGame.SetUpperRange(50);
    }
    else if (level == 3)
    {
        //mutator functions
        currentGame.SetNumGuesses(8);
        currentGame.SetUpperRange(150);
    }
    else
    {
        cout << "\nThat is not a valid level";
    }
}

