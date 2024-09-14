#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include<stdio.h>
#include<conio.h>
#include <fstream>
#include<ctime>
#include <stack>
#include <queue>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

// Forward declarations
class User;
class Game;
class Study;

struct Question {
    string statement;
    string option_1, option_2, option_3, option_4;
    string option_correct;
};

struct node {
    Question data;
    node* pre;
    node* next;
};

struct Node
{
    string data;
    Node* pre;
    Node* next;
};

Node* tail = NULL;
Node* head = NULL;
Node* newnode = NULL;

class Game {
public:
    int level = 1;
    int premium = 0;
    stack<int> stack_score;
    queue<Question> queue_questions;

    int driver_code();
    void load_question_level_1();
    void load_question_level_2();
    void load_question_level_3();
    void add_question(Question q);
    string display_question(Question q);
    int score(Question q, string answer);
    int display_score(int size);
};

class User {
private:
    string Username_up, Password_up;
    string Username_in, Password_in;

public:
    int sign_up();
    int sign_in();
    int Logged_in();
    int play_music();
    int classify_music();
    int make_playlist();
    int play_musicgame();
    int study_music();
};

class Study {
public:
    stack<int> stack_courses;
    int course_enrollment();
    int course_access();
    int driver_code_1();
};

// Implementations for User class
int User::sign_up() {
    fstream object;
    object.open("Registration.txt", ios::app);

    cout << "\n\tUsername: ";
    cin >> Username_up;
    cout << "\n\tPassword: ";
    cin >> Password_up;

    object << Username_up << " " << Password_up << endl;
    object.close();
    return 0;
}

int User::sign_in() {
    User U;
    fstream object_1;
    object_1.open("Registration.txt", ios::in);

    if (!object_1) {
        cout << "Error Opening File!!!";
        return -1;
    } else {
        cout << "\n\tUsername: ";
        cin >> Username_in;
        cout << "\n\tPassword: ";
        cin >> Password_in;

        while (object_1) {
            if (object_1 >> Username_up && object_1 >> Password_up && Username_up == Username_in && Password_up == Password_in) {
                return U.Logged_in();
            }
        }
    }
    return -1;
}

int User::Logged_in() {
    User U;
    int choice, choice_repeat;
    system("CLS");

    do {
        cout << "\n-----------------------------------";
        cout << "\n\t1. Play Music";
        cout << "\n\t2. Classify Music";
        cout << "\n\t3. Make Playlist";
        cout << "\n\t4. Play Music Game";
        cout << "\n\t5. Study Music";
        cout << "\n\t6. Exit";
        cout << "\n-----------------------------------\n";
        cin >> choice;

        switch (choice) {
            case 1:
                U.play_music();
                break;
            case 2:
                U.classify_music();
                break;
            case 3:
                U.make_playlist();
                break;
            case 4:
                U.play_musicgame();
                break;
            case 5:
                U.study_music();
                break;
            default:
                // exit(0);
                break;
        }

        cout << "\n-----------------------------------";
        cout << "\n\t0. Repeat";
        cin >> choice_repeat;

    } while (choice_repeat == 0);

    return 0;
}

int User::play_music() {
    // Implementation for play_music
	system("CLS");
	int choice_repeat;
	int choice_song;
	do{
		//will change song names afterwards
	cout<<"\nSelect the song you want to play:\n";
	cout<<"\n1. Song A";
	cout<<"\n2. Song B";
	cout<<"\n3. Song C";
	cout<<"\n4. Song D";
	cout<<"\n4. Song E";
	cin>>choice_song;
	switch(choice_song)
	{
		case 1:
			int play;
				//furthur process start when whole song is finished
				//PlaySound(("Song_1.wav"),NULL,SND_SYNC); 
				//play in background (we will use this)
				PlaySound(TEXT("Song_1.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play;
				if(play==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
			break;
		case 2:
			int play1;
			//we will change the song afterwards
			PlaySound(TEXT("Song_1.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play1;
				if(play1==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
			break;
		case 3:
			int play2;
			PlaySound(TEXT("Song_1.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play2;
				if(play2==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}			
			break;
		case 4:
			int play3;
			PlaySound(TEXT("Song_1.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play3;
				if(play3==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
			break;
		case 5:
			int play4;
			PlaySound(TEXT("Song_1.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play4;
				if(play4==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
			break;
		default:
			cout<<"Wrong Choice!!!";
			break;
	}
	cout<<"\n0. Show List Again\n";
	cin>>choice_repeat;
	}while(choice_repeat==0);
    return 0;
}

int User::classify_music() {
    	int choice_category, choice_genre, choice_language, choice_singer,choice_song;
	cout<<"\n-----------------------------------";
	cout<<"\n\tChoose Category:";
	cout<<"\n1. Genre";
	cout<<"\n2. Language";
	cout<<"\n3. Singer";
	cout<<"\n-----------------------------------";
	cin>>choice_category;
	switch(choice_category)
	{
		case 1:
		cout<<"\n-----------------------------------";
			cout<<"\n\tChoose Genre:";
			cout<<"\n1. Jazz";
			cout<<"\n2. Sufi";
			cout<<"\n3. Pop\n";
		cout<<"\n-----------------------------------";
			cin>>choice_genre;
			switch(choice_genre)
			{
				case 1:
	cout<<"\nSelect the song you want to play:\n";
	cout<<"\n1. Juro ge to janu ge ";
	cout<<"\n2. Song B";
	cout<<"\n3. Song C";
	cout<<"\n4. Song D";
	cin>>choice_song;
					switch(choice_song)
	            {
	            	case 1:
	           	int play;
				PlaySound(TEXT("Song_2.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play;
				if(play==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
					break;
					case 2:
						int play1;
				PlaySound(TEXT("Song_1.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play1;
				if(play1==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
						break;
					case 3:
						int play2;
				PlaySound(TEXT("Song_1.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play2;
				if(play2==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
						break;
					case 4:
						int play3;
				PlaySound(TEXT("Song_1.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play3;
				if(play3==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
					break;	
				}
			break;
				case 2:
						cout<<"\nSelect the song you want to play:\n";
	cout<<"\n1. Mustafa jaan e rehmat ";
	cout<<"\n2. Song B";
	cout<<"\n3. Song C";
	cout<<"\n4. Song D";
	cin>>choice_song;
					switch(choice_song)
	            {
	            	case 1:
	           	int play;
				PlaySound(TEXT("Song_3.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play;
				if(play==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
					break;
					case 2:
						int play1;
				PlaySound(TEXT("Song_1.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play1;
				if(play1==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
						break;
					case 3:
						int play2;
				PlaySound(TEXT("Song_1.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play2;
				if(play2==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
						break;
					case 4:
						int play3;
				PlaySound(TEXT("Song_1.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play3;
				if(play3==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
					break;	
				}
			break;
				case 3:
					cout<<"\nSelect the song you want to play:\n";
	cout<<"\n1. Tera hone laga hu";
	cout<<"\n2. Song B";
	cout<<"\n3. Song C";
	cout<<"\n4. Song D";
	cin>>choice_song;
					switch(choice_song)
	            {
	            	case 1:
	           	int play;
				PlaySound(TEXT("Song_4.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play;
				if(play==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
					break;
					case 2:
						int play1;
				PlaySound(TEXT("Song_1.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play1;
				if(play1==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
						break;
					case 3:
						int play2;
				PlaySound(TEXT("Song_1.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play2;
				if(play2==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
						break;
					case 4:
						int play3;
				PlaySound(TEXT("Song_1.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play3;
				if(play3==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
					break;	
				}
			break;	
				
			}
			break;
		case 2:
			cout<<"\n\tChoose Language:";
			cout<<"\n1. Urdu/Hindi";
			cout<<"\n2. English";
			cin>>choice_language;
			switch(choice_language)
			{
				case 1:
						cout<<"\nSelect the song you want to play:\n";
	cout<<"\n1. Juro ge to janu ge";
	cout<<"\n2. Sufiana kalam";
	cout<<"\n3. Tera hone laga hu";
	cout<<"\n4. Song D";
	cin>>choice_song;
					switch(choice_song)
	            {
	            	case 1:
	           	int play;
				PlaySound(TEXT("Song_2.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play;
				if(play==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
					break;
					case 2:
						int play1;
				PlaySound(TEXT("Song_3.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play1;
				if(play1==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
						break;
					case 3:
						int play2;
				PlaySound(TEXT("Song_4.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play2;
				if(play2==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
						break;
					case 4:
						int play3;
				PlaySound(TEXT("Song_1.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play3;
				if(play3==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
					break;	
				}
			break;
				case 2:
					cout<<"\nSelect the song you want to play:\n";
	cout<<"\n1. Song A";
	cout<<"\n2. Song B";
	cout<<"\n3. Song C";
	cout<<"\n4. Song D";
	cin>>choice_song;
					switch(choice_song)
	            {
	            	case 1:
	           	int play;
				PlaySound(TEXT("Song_1.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play;
				if(play==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
					break;
					case 2:
						int play1;
				PlaySound(TEXT("Song_1.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play1;
				if(play1==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
						break;
					case 3:
						int play2;
				PlaySound(TEXT("Song_1.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play2;
				if(play2==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
						break;
					case 4:
						int play3;
				PlaySound(TEXT("Song_1.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play3;
				if(play3==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
					break;	
				}
			break;
			
			}
			break;
		case 3:
			cout<<"\n\tChoose Singer:";
			cout<<"\n1. Atif Aslam";
			cout<<"\n2. Nusrat";
			cout<<"\n3. Arijit Singh\n";
			cin>>choice_singer;
			switch(choice_singer)
			{
				case 1:
	cout<<"\nSelect the song you want to play:\n";
	cout<<"\n1. Juro ge to janu ge";
	cout<<"\n2. Mustafa jaan e rehmat";
	cout<<"\n3. Tera hone laga hu";
	cout<<"\n4. Song D";
	cin>>choice_song;
					switch(choice_song)
	            {
	            	case 1:
	           	int play;
				PlaySound(TEXT("Song_2.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play;
				if(play==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
					break;
					case 2:
						int play1;
				PlaySound(TEXT("Song_3.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play1;
				if(play1==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
						break;
					case 3:
						int play2;
				PlaySound(TEXT("Song_4.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play2;
				if(play2==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
						break;
					case 4:
						int play3;
				PlaySound(TEXT("Song_1.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play3;
				if(play3==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
					break;	
				}
			break;
					break;
				case 2:
						cout<<"\nSelect the song you want to play:\n";
	cout<<"\n1. Song A";
	cout<<"\n2. Song B";
	cout<<"\n3. Song C";
	cout<<"\n4. Song D";
	cin>>choice_song;
					switch(choice_song)
	            {
	            	case 1:
	           	int play;
				PlaySound(TEXT("Song_1.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play;
				if(play==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
					break;
					case 2:
						int play1;
				PlaySound(TEXT("Song_1.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play1;
				if(play1==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
						break;
					case 3:
						int play2;
				PlaySound(TEXT("Song_1.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play2;
				if(play2==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
						break;
					case 4:
						int play3;
				PlaySound(TEXT("Song_1.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play3;
				if(play3==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
					break;	
				}
			break;
					break;
				case 3:
						cout<<"\nSelect the song you want to play:\n";
	cout<<"\n1. Song A";
	cout<<"\n2. Song B";
	cout<<"\n3. Song C";
	cout<<"\n4. Song D";
	cin>>choice_song;
					switch(choice_song)
	            {
	            	case 1:
	           	int play;
				PlaySound(TEXT("Song_1.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play;
				if(play==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
					break;
					case 2:
						int play1;
				PlaySound(TEXT("Song_1.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play1;
				if(play1==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
						break;
					case 3:
						int play2;
				PlaySound(TEXT("Song_1.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play2;
				if(play2==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
						break;
					case 4:
						int play3;
				PlaySound(TEXT("Song_1.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
				cout<<"\n\tTo stop enter 1: ";
				cin>>play3;
				if(play3==1)
				{
					PlaySound(0,0,0);//function to pause/stop
				}
					break;	
				}
			break;
					break;
			}
			break;
		default:
			cout<<"Wrong Choice!!!";
			break;
	}
}
void addsong(string song)
{
    newnode = new Node;
    newnode->data = song;
    newnode->pre = NULL;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        cout << "Head created";
    }
    else
    {
        tail->next = newnode;
        newnode->pre = tail;
        tail = newnode;
        cout << "\nSong Inserted ";
    }
}

void display_playlist()
{
    Node* ptr;
    ptr = head;

    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int reverse_playlist()
{
    cout << "\nReversed playlist\n";
    Node* ptr;
    ptr = tail;

    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->pre;
    }

    return 0;
}

void shuffle_playlist()
{
    // Implementation for shuffling playlist
}

int User::make_playlist() {
	int choice_song, choose_option, choice1;

    do
    {
        cout << "\n-----------------------------------";
        cout << "\n\t1. Add song";
        cout << "\n\t2. Display playlist";
        cout << "\n\t3. Reverse playlist";
        cout << "\n\t4. Shuffle playlist";
        cout << "\n-----------------------------------";
        cin >> choose_option;

        switch (choose_option)
        {
        case 1:
            do
            {
                cout << "\n-----------------------------------";
                cout << "\nSelect the song you want to add in your playlist:\n";
                cout << "\n1. Kaun Tujhe";
                cout << "\n2. Juro ge to janu ge";
                cout << "\n3. Sufiana kalam";
                cout << "\n4. Tera hone laga hu";
                cout << "\n5. Song E";
                cout << "\n-----------------------------------";
                cin >> choice_song;

                switch (choice_song)
                {
                case 1:
                    addsong("kaun_Tujhe");
                    break;
                case 2:
                    addsong("Juro_ge_to_janu_ge");
                    break;
                case 3:
                    addsong("song c");
                    break;
                case 4:
                    addsong("song d");
                    break;
                case 5:
                    addsong("song e");
                    break;
                default:
                    cout << "\nWRONG CHOICE\n";
                    break;
                }

                cout << "\nTo repeat press 0\n";
                cin >> choice1;
            } while (choice1 == 0);
            break;

        case 2:
            display_playlist();
            break;

        case 3:
            reverse_playlist();
            break;

        case 4:
            shuffle_playlist();
            break;
        }

        cout << "\nTo repeat press 0\n";
        cin >> choice1;

    } while (choice1 == 0);

    return 0;
}

//Implementations for Game class
void Game::load_question_level_1() {
    // Load questions for level 1
			Question q1{
				"What is my name?",
				"A.Eman","B.Maryam","C.Asma","D.Hina",
				"A"
			};
			Question q2{
				"What is my real name?",
				"A.Eman","B.Maryam","C.Asma","D.Hina",
				"A"
			};
			Question q3{
				"What is my basic name?",
				"A.Eman","B.Maryam","C.Asma","D.Hina",
				"A"
			};
		
			add_question(q1);
			add_question(q2);
			add_question(q3);
		
		    // Add questions to the queue (order of questions)
   			queue_questions.push(q1);
    		queue_questions.push(q2);
    		queue_questions.push(q3);

}

void Game::load_question_level_2() {
    // Load questions for level 2
			Question q1{
				"What is my name?.....",
				"A.Eman","B.Maryam","C.Asma","D.Hina",
				"A"
			};
			Question q2{
				"What is my real name?....",
				"A.Eman","B.Maryam","C.Asma","D.Hina",
				"A"
			};
			Question q3{
				"What is my basic name?....",
				"A.Eman","B.Maryam","C.Asma","D.Hina",
				"A"
			};
		
			add_question(q1);
			add_question(q2);
			add_question(q3);
		
		    // Add questions to the queue (order of questions)
   			queue_questions.push(q1);
    		queue_questions.push(q2);
    		queue_questions.push(q3);
}

void Game::load_question_level_3() {
    // Load questions for level 3
			Question q1{
				"What is my name?/////",
				"A.Eman","B.Maryam","C.Asma","D.Hina",
				"A"
			};
			Question q2{
				"What is my real name?/////",
				"A.Eman","B.Maryam","C.Asma","D.Hina",
				"A"
			};
			Question q3{
				"What is my basic name?///",
				"A.Eman","B.Maryam","C.Asma","D.Hina",
				"A"
			};
		
			add_question(q1);
			add_question(q2);
			add_question(q3);
		
		    // Add questions to the queue (order of questions)
   			queue_questions.push(q1);
    		queue_questions.push(q2);
    		queue_questions.push(q3);
    
}

void Game::add_question(Question q) {
    node* newnode = new node{q, NULL, NULL};
    node* head = NULL;
    node* tail = NULL;

    if (head == NULL) {
        newnode = head;
        newnode = tail;
    } else {
        tail->next = newnode;
        newnode->pre = tail;
        newnode = tail;
    }
}

string Game::display_question(Question q) {
    cout << q.statement << endl;

    cout << q.option_1 << endl;
    cout << q.option_2 << endl;
    cout << q.option_3 << endl;
    cout << q.option_4 << endl;

    string abc;
    cin >> abc;
    return abc;
}

int Game::score(Question q, string answer) {
    if (answer == q.option_correct) {
        cout << "\n\n\tCorrect!!!\n";
        stack_score.push(1);
    } else {
        cout << "\n\n\tIncorrect!!!\n";
        stack_score.push(0);
    }

    return 0;
}

int Game::display_score(int size) {
    int score_final = 0;
    while (!stack_score.empty()) {
        score_final = score_final + stack_score.top();
        stack_score.pop();
    }

    cout << "You scored " << score_final << " out of " << size << " !!!";
    if (score_final == size) {
        level++;
    }
    return 0;
}
int Game::driver_code() {
    int choice;
	int continuee;
	
	do{
	cout<<"\n\t1.Start All Over";
	cout<<"\n\t2. Resume Progress";
	cin>>choice;
	if(choice==1)
	{
		level=1;
	}	
	
		if(level==1)
		{
			load_question_level_1();
		}
		else if(level==2)
		{
			load_question_level_2();
		}
		else if(level==3)
		{
			load_question_level_3();
		}

	int size=queue_questions.size();
	while(!queue_questions.empty())
	{
		Question current_question = queue_questions.front();
		queue_questions.pop();
		//display_question(current_queston);
		
		string answer=display_question(current_question);
		
		score(current_question, answer);
	
	}
	
	display_score(size);
	
	cout<<"\n1. Continue";
	cin>>continuee;
	}while(continuee==1);
    return 0;
}

int User::play_musicgame() {
    Game g;
    g.driver_code();
    return 0;
}

load_music_history()
{
	fstream file;
	file.open("History.txt",ios::in);
	if(!file)
	{
		cout<<"\nError opening file!";
		
	}
	else
	{
		char x;
		while(file)
		{
			file>>x;
			if(file.eof())
			break;
			cout<<x;
		}
		file.close();
	}
}
load_music_genres()
{
	fstream file1;
	file1.open("Genre.txt",ios::in);
	if(!file1)
	{
		cout<<"\nError opening file!";
		
	}
	else
	{
		char x;
		while(file1)
		{
			file1>>x;
			if(file1.eof())
			break;
			cout<<x;
		}
		file1.close();
	}
}
load_music_technology()
{
	fstream file2;
	file2.open("Technology.txt",ios::in);
	if(!file2)
	{
		cout<<"\nError opening file!";
		
	}
	else
	{
		char x;
		while(file2)
		{
			file2>>x;
			if(file2.eof())
			break;
			cout<<x;
		}
		file2.close();
	}
}
load_music_media()
{
	fstream file3;
	file3.open("History.txt",ios::in);
	if(!file3)
	{
		cout<<"\nError opening file!";
		
	}
	else
	{
		char x;
		while(file3)
		{
			file3>>x;
			if(file3.eof())
			break;
			cout<<x;
		}
		file3.close();
	}
}
int Study::driver_code_1() {
    char any;
    int another;
    int choice_course;
    
    cout << "\n.........................................................";
    cout << "\n\tWELCOME TO THE STUDY FEST OF MUSICITY!!!!";
    cout << "\n.........................................................";
    cout << "\n\nPress any char key to continue..";
    cin >> any;
    system("CLS");
	
	int repeat;
			cout<<"\nFollowing is the list of courses you can enroll into...";
			cout<<"\nSelect any of your interest";
			do{
			cout<<"\n\n1.Music History";
			cout<<"\n2.Music Genres";
			cout<<"\n3.Music Tecnology";
			cout<<"\n4.Music And Media";
			cin>>choice_course;
			switch(choice_course)
			{
				case 1:
					load_music_history();
					break;
				case 2:
					load_music_genres();
					break;
				case 3:
					load_music_technology();
					break;
				case 4:
					load_music_media();
					break;
				default:
					cout<<"Course doesn't exist";
			}
			cout<<"\n\t1.View another course";
			cin>>another;
			}while(another==1);
			
}

int User::study_music() {
    Study s;
    s.driver_code_1();
    return 0;
}

int main() {
    User U;
    int choice_sign, choice_repeat;
    cout << "\n-----------------------------------";
    cout << "\n\t1. SIGN UP";
    cout << "\n\t2. SIGN IN\n";
    cout << "\n-----------------------------------";
    cin >> choice_sign;

    system("CLS");
    switch (choice_sign) {
        case 1:
            U.sign_up();
            break;
        case 2:
            U.sign_in();
            break;
        default:
            cout << "\n\tWrong choice!!!";
            break;
    }
    cout << "\n-----------------------------------";

    return 0;
}
