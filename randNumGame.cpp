using namespace std;

#include<iostream>
#include<ctime>
#include<cstdlib>

class Player{
    private:
    string name;
    int score;

    public:
    Player(string n , int s) : name(n) , score(s) {};

    void setName(string n)
    {
        name = n;
    }

    void setScore(int s)
    {
        score = s;
    }

    string getName()
    {
        return name;
    }

    int getScore()
    {
        return score;
    }

};

string findRandomBot(const string arr[] , int size)
{
    srand(time(nullptr));
    int randomIndex = rand() % size;
    return arr[randomIndex];
}

int getRandomNum(int from , int to)
{
    srand(time(nullptr));
    int randNum = rand() % to + from;
    return randNum;
}

int main()
{
    string Bots[5] = {"Jack" , "Bob" , "Roy" , "Neckels" , "Raj"};

    string realPlayerName;
    string botPlayerName;

    cout<<"Enter your name : ";
    cin>>realPlayerName;

    botPlayerName = findRandomBot(Bots, 5);

    Player player1(realPlayerName , 0); //Real Player
    Player player2(botPlayerName , 0);  //Bot Player

    cout<<"=====================================\nHello "<<player1.getName()<<" You are connected to "<<player2.getName()<<endl;

    do{
        cout<<"================================================"<<endl;

        int realPlayerChoice;
        int botPlayerChoice;

        int finalGeneratedNum;
        
        cout<<"Choose any number between 1-10 : ";
        cin>>realPlayerChoice;

        botPlayerChoice = getRandomNum(1 , 10);

        cout<<player1.getName()<<" you Chose : "<<realPlayerChoice<<" and "<<player2.getName()<<" Chose : "<<botPlayerChoice<<endl;
        cout<<"Press Enter Key."<<endl;

        finalGeneratedNum = getRandomNum(1 , 10);

        if(!(realPlayerChoice == botPlayerChoice)){
            if(finalGeneratedNum == realPlayerChoice)
            {
                cout<<"Generated Number is : "<<finalGeneratedNum<<endl;
                player1.setScore(player1.getScore() + 1);
                cout<<"===================================\n"<<player1.getName()<<" Won.!!!\nYour Score : "<<player1.getScore()<<endl;
            }else if(finalGeneratedNum == botPlayerChoice)
            {
                cout<<"Generated Number is : "<<finalGeneratedNum<<endl;
                player2.setScore(player2.getScore() + 1);
                cout<<"==================================\n"<<player2.getName()<<" Won.!!!\n"<<player2.getName()<<"'s Score : "<<player2.getScore()<<endl;
            }else {
                cout<<"Not matched , Try Again.!!!"<<endl;
            }
        }else {
            cout<<"======================\nOops.! It's tie , TryAgain.\n======================================"<<endl;
        }

    }while (player1.getScore() >= 50 || player2.getScore() >= 50);
    

    return 0;
}