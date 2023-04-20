/*

Jonathan Morales                                                             

                                            

LAB#2

Improve the game's c++

1.Provide many comments;
2.Provide an introduction to the game;
3.Provide a means to play again;
4.Do not use a an array, but research and use the vector STL to hold strings;
5.Some idea on how well the player preformed;
6.you played 5 times and your best time was 10 seconds, worst was 23 seconds, you gave-up 2 times.
7.Use/create functions so that you have a small main() function that main() is easy to read/understand.


*/

#include <iostream>
#include <string>//string library so can hold words and can help to pass into the vectors
#include <ctime>//time function to have the time of the motherboard 
#include <cstdlib>  //so we can use the s ran function.
#include <vector>//vector function
#include <stdlib.h>//clear library so the hello() flush and just appear is just in the begging

using namespace std;
/************beginnign************/
//FUNCTION PROTOTYPE
void hello();// function prototype of greeting and tittle of the game "the name of the game."
//BANK OF WORDS
void intro();
vector<string> words{ "moon","Venus" ,"Earth","Mars", "Jupiter", "Neptune","Saturn","sun","Uranus","Pluto","Ceres","433Eros","Haumea","Eris", "MilkyWay","asteroid","comets","galaxy","stars" };//the vector that contains the word banks 
void print_vector(vector<string >words);// Help to print the bank words directly.
string Random(const vector<string>& const w);//random word. 
string Scram(std::string);//Scramble function using and string has a parameter is a copy of the random word 
void GameScram(string z);
void  Game();
void winms(string z);
void playagain();
void keepplaying();
void scorew(unsigned int T1, unsigned int T2);//time function with message
void scorel(unsigned int T1, unsigned int T2);
void spaces();//just for spaces 
void end();

/******************************************************************/

int main()
{

	hello();//Greetings message with the game name

	intro();//a brief explanation about the game 

	Game();//game function

    end();//credits


}

/*******************************************************************/
void hello() // tittle message and menu to play the game 
{
	char start{};
	system("CLS");
	cout << ".:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:.\n";
	cout << R"(
        __/\\\\\\\\\\\__________/\\\\\\\\\__/\\\\\\\\\\\\\\\\\\\____/\\\\\\\\\______/\\\\\\\\   /\\\\\
       __/\\\/////////\\\_____/\\\////////__\/////\\\///////////___/\\\\\\\\\\\\\___\/\\\\\\\\  /\\\\\\
        _\//\\\______\///____/\\\/_______________\/\\\_____////___/\\\/////////\\\___\/\\\\\\\\ /\\\\\\\
         _\////\\\__________/\\\_________________\/\\\____////____\/\\\_______\/\\\___\/\\\\\\\\/\\\\\\\\
            __\////\\\______\/\\\_________________\/\\\\\\\\\______\/\\\\\\\\\\\\\\\___\/\\\\___\/___\\\\\
          ______\////\\\___\//\\\________________\/\\\__\\\\\_______\/\\\/////////\\\___\/\\\\________\\\\\
        _/\\\______\//\\\___\///\\\______________\/\\\_____\\\\______\/\\\_______\/\\\___\/\\\\________\\\\\
         \///\\\\\\\\\\\/______\////\\\\\\\\\__/\\\\\\\______\\\\_____\/\\\_______\/\\\___\/\\\\________\\\\\
       ___\///////////___________\/////////__\///////// ______\\\\\____\///________\///____\/\\\\________\\\\\
)" << '\n';
	cout << ".:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:.\n";

	cout << "                             press any key to start and enter to the play the game   \n";
	cin >> start;
	cout << " " << flush; //flush forces the printing to the screen before it clears
	system("CLS");
}
void print_vector(vector<string>words)//passing vectors through the function in this case is a string (words) so I do not  have to use an arrays 
{
	for (int i = 0; i < words.size(); i++)
	{
		cout << words[i] << " \t";
	}

}//pass the number of elements word.size and storage in temporary array to display all the words 
void   Game()
{

	char choice;
	const char Q = 'N';

	do {

		system("CLS");
		//print_vector(words);
		string z = Random(words);//z is the variable that will storage the random word 

		cout << "\n **********************************************************************************\n";
		cout << " \n    .--.       .-'.      .--.      .--.      .--.      .--.      .`-.      .--. \n";
		cout << "\n     :::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\ \n ";
		cout << "\n     '      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      ` \n";
		cout << "\n ***********************************************************************************\n";
		
		GameScram(z);


		cout << "\n **********************************************************************************\n";
		cout << " \n    .--.       .-'.      .--.      .--.      .--.      .--.      .`-.      .--. \n";
		cout << "\n     :::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\ \n ";
		cout << "\n     '      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      ` \n";
		cout << "\n ***********************************************************************************\n";

		keepplaying();
		cout << "You want to continue playing:  [Y/N] \n";
		cin >> choice;
		choice = toupper(choice);   // fix all choices to upper case

	} while (choice != Q);

	system("CLS");
}//
string Random(const vector<string>& const w)
{
	srand(time(NULL));
	int r = rand() % w.size();//creates a random word from divide from Word that is the number of the elements.taking the modules of the division.

	return w[r]; //storage the word in the temporary 


}//creates a temporary value w[r] located in the function 
string Scram(string z) {


	string l = z;// is the random word that will be storage in l 
	const int w = z.size();//store the number of letter is in the random word, that will be change in scramble word 
	for (int letter = 0; letter < w; letter++)
	{
		int k = rand() % w;//takes a random letter from the word 

		char temporary = l[k];// temporary storage the letter 
		l[k] = l[letter]; //replace the position of the random letter into the word
		l[letter] = temporary;//the scramble word 
	}
	return l;

}
void  GameScram(string z)
{
	playagain();
	int attemps = 0;//the user attemps 
	int Maxattemps = 5;//the max attemps 
	unsigned int T1 = time(0); //<---time count is when start to take time 
	string k = Scram(z);//k is the scramble letter
	string word;//the guess from the user.

	bool outofguess = false; 

	cout << " the word is: " << k << endl;

	while (word != z && !outofguess)
	{
		if (attemps < Maxattemps)
		{

			cout << "guess the word: \n";
			cin >> word;
			attemps++;
			cout << " the attemps are:  " << attemps << endl;
            
			if (word == z) {

				cout << "_.--.__.-'""`-.__.--.__.-'""`-.__.--.__.-'""`-.__.--.__.-'`-._\n";
                
				cout << " =^..^=   =^..^=   =^..^=  winner =^..^=    =^..^=    =^..^=\n";
                
				cout << "_.--.__.-'""`-.__.--.__.-'""`-.__.--.__.-'""`-.__.--.__.-'`-._\n";
                spaces();
				winms(z);
				
				unsigned int T2 = time(0);

				scorew(T1, T2);
				system("pause");
				system("CLS");
                 break;
			}
		}
		else//I could keep do it more function so I can keep clean the code and dont have too many couts but is going to be the same in the functions 
		{
			outofguess = true;
            unsigned int T2 = time(0);
            spaces();
			cout << "_/~\_/~\_/~\_/~\_/~\_/~\_/~\__\n";
			cout << " \n";
			cout << "Awww out of  guesses" << endl;
            cout << " \n";
			cout << "=_/~\_/~\_/~\_/~\_/~\_/~\_/~\__\n";
			cout << " \n";
			cout << " the word was:   " << z <<  endl;
			cout << " \n";
			cout << "=_/~\_/~\_/~\_/~\_/~\_/~\_/~\__\n";
            spaces();
			scorel(T1,T2);
            spaces();
		    cout << "__/~\_/~\_/~\_/~\_/~\_/~\_/~\__\n";
			system("pause");//so the cin.get don't pass without let the user press enter
			system("CLS");
			break;
		}
	}
	

}
	//graphics and messages 
void intro()
{
	//system("CLS");
	
	cout << ".:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.\n";
	cout << R"(
                                       _..-,--.._                   
                                 ,`. ,',','      `.                 
                                 `. `,/`/          \           
                                   :'.`:            :        /(o.o)\ ^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v/(o.o)\
        ____ _          _ __       | |`|            |        /(o.o)\               HI                    /(o.o)\ 
      _(    `.)        ( (  )`.    : `-'            ;     _  /(o.o)\ our station Usuda Deep Space Center /(o.o)\ 
     ( (    ) ))      ( (    ))    ,\_            _/.  (`',' /(o.o)\  receives an encrypted              /(o.o)\
    ( (   )  _)        `-(__.'    '.  ```------'''  .`       /(o.o)\  message but the only form to        /(o.o)\
     '.__)--'       .-..           |``-...____...-''|        /(o.o)\ decrypt it knows where it comes from /(o.o)\
                   (_)_))          |                |        /(o.o)\ ^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v/(o.o)\
              ,'`.        ___...---|                |--..._
  ,'`. ,'`. ,'   _`.---'''         |                | "
-'..._`.   `.   /`-._  "      "    |    _           |
       ```-..`./:::::)             `-...||______...-'    "
              /:::_.'     "        "                "
           _.:.'''   "                       "       
)" << '\n';
	cout << ".:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.\n";

	cout << "                                        Press enter to continue                  \n";
	cin.get();
	//cout << " " << flush; //flush forces the printing to the screen before it clears
	system("pause");//so the cin.get don't pass without let the user press enter
   system("CLS");
   cout << ".:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.\n";
   cout << R"(
      
                                               .oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.
                              ***              .oOo.                                           .oOo.
                             / : \             .oOo.  You have 5  attempts to decrypt where     oOo.
                            / o0o \            .oOo.   the message came from or will despair   .oOo.
                      _____"~~~~~~~"_____      .oOo.                                           .oOo.
                      \+###|U * * U|###+/      .oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.
                       \...!(.>..<)!.../  
                        ^^^^o|   |o^^^^       
                     +=====}:^^^^^:{=====+#   .oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.   
                     .____  .|!!!|.  ____.         message: 
                     |#####:/" " "\:#####|   01101000 01101001 00100000 01100110 01110010 01101111 01101101
                     |#####=|  O  |=#####|   00100000 01110100 01101000 01100101 00100000 01110011 01110000       
                     |#####>\_____/<#####|   01100001 01100011 01100101 00101110
                      ^^^^^   | |   ^^^^^      .oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo
                              o o

    
)" << '\n';
   cout << ".:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.\n";

   cout << "                                        Press enter to continue                  \n";
   cin.get();//allows to continue to the next screen
   //cout << " " << flush; //flush forces the printing to the screen before it clears
   system("pause");//so the cin.get don't pass without let the user press enter
   system("CLS");

}
void winms(string z)
{

	cout << ".:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.\n";
	cout << R"(
  
                /___.`--.____ .--. ____.--(             RADIO TRANSMITION        
                       .'_.- (    ) -._'.
                     .'.'    |'..'|    '.'.             Usuda Deep Space Center:
              .-.  .' /'--.__|____|__.--'\ '.  .-.      ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^
             (O).)-| |  \    |    |    /  | |-(.(O)     ~^~^ALPHA2~^~^~^~^ALPHA2~^~^~^~^~^~^~^~^~^~^~^
              `-'  '-'-._'-./      \.-'_.-'-'  `-'      ~^~^~THE COORDINATES WHERE~^~^~^~ THE ^~^~^~^~
                 _ | |   '-.________.-'   | | _         ~^~^~MESSAGE CAME FROM IS CONFIRM^~^~^~^~^~^~^
              .' _ | |     |   __   |     | | _ '.      ~^~^~^~^PROCEED TO SEND OUR MESSAGE~^~^OVER~^~
             / .' ''.|     | /    \ |     |.'' '. \     ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^
             | |( )| '.    ||      ||    .' |( )| |     ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^
             \ '._.'   '.  | \    / |  .'   '._.' /
              '.__ ______'.|__'--'__|.'______ __.'
             .'_.-|         |------|         |-._'.                                             :APHA2
            //\\  |         |--::--|         |  //\\     ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^
           //  \\ |         |--::--|         | //  \\    ~^~^~^~^~^~^~^~^~^~^~^COPY OVER~^~^~^~^~^~^~^~
          //    \\|        /|--::--|\        |//    \\   ~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^
         / '._.-'/|_______/ |--::--| \_______|\`-._.' \  ~^~^~^~CONFIRM THE COORDINATES ^~^~^~^~^~^~^~^
        / __..--'        /__|--::--|__\        `--..__ \ ~^~^~^~^~^~^~^~^~^~^~^~^~^~^OVER~^~^~^~^~^~^~^
       / /               '-.|--::--|.-'               \ \~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^
      / /                   |--::--|                   \ \
     / /                    |--::--|                    \ \
 _.-'  `-._                 _..||.._                  _.-` '-._
'--..__..--'               '-.____.-'                '--..__..-     
)" << '\n';
	cout << ".:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.\n";
	cout << " " << endl;
	cout << " " << endl;
	cout << " Usuda Deep Space Center: ~^WHERE THE~^~^MESSAGE~^~^CAME FROM^~^~^~^   " << z << "  ^~^~^~^~OVER^~^~^~^~^~^~" << endl;
	cout << " " << endl;
	cout << " " << endl;
	cin.get();
	//cout << " " << flush; //flush forces the printing to the screen before it clears
	system("pause");//so the cin.get don't pass without let the user press enter
	system("CLS");


}   //win message 
void playagain()
{

	cout << ".:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.\n";
	cout << R"(
                                       .              +  
                   .                    .       .     *  .      .    .     . .   . . .        ! /
  .       *                        . . . .  .   .  + .*            *
            "You Are Here"     ..    .  . .   .  +  . . .       .       . +  .+. 
.                 |             .  .   .    .    . ..        ..
                  |           .     .     . +.    +  ..  .   . .   . .   .   .   . .  +   .    .            
                 \|/            .       .   . .
        . .       V          .    * . . .  .  +   . .         .     . + .  . .     .      .
           +      .           .  . .  .    +..
                          .  .   .    . +  .+. .         .       . +  .+. ..
  .                      . . . .  . + .  . .     .      .
           .      .    .     . .   . . .        ! /..
      *             .    . .  +    .  .       - O -   .     .    .  +   . .  *  .   
          .     .    .  +   . .  *  . .      . / |
               . + .  .  .  .. +  .    
)" << '\n';
	cout << ".:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.\n";

	

} //you are here
void scorew(unsigned int T1,unsigned int T2)
{

	unsigned int T3 = 10;
	unsigned int T4 = 23;
	unsigned int score = (T2 - T1);

	if (score <= T3)//is going to have a message in to times the first is 10 seconds is the perfect time or good
	{
		cout << "<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<: " << endl;
		cout << " " << endl;
		cout << "good time to decrypt the location!!!!!\n ";
		cout << " " << endl;
		cout << "the time " << score << " second" << endl;
		cout << " " << endl;
		cout << "<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<: " << endl;
	}else if (score <= T4) {//the second mark is on 23 or more to decrypt the message

		cout << "<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<: " << endl;
		cout << " " << endl;
		cout << " time enough to decrypt the message \n ";
		cout << " " << endl;
		cout << "the time " << score << " second" << endl;
		cout << " " << endl;
		cout << "<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<: " << endl;
	}
	else {

		cout << "<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<: " << endl;
		cout << " " << endl;
		cout << " the message almost despair \n ";
		cout << " " << endl;
		cout << "the time " << score << " second" << endl;
		cout << " " << endl;
		cout << "<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<:>:<: " << endl;

	}


}
void scorel(unsigned int T1, unsigned int T2)
{
   spaces();
	cout << "*****We lost the message******** \n";
    cout << "keep trying we have more messages in coming\n";

}
void keepplaying()
{
	cout << ".:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.\n";
	cout << R"(


      ,-.
     / \  `.  __..-,O
    :   \ --''_..-'.'
    |    . .-' `. '.                  There are more messages to decrypt......
    :     .     .`.'
     \     `.  /  ..          The universe is a symphony of strings, and the mind of
      \      `.   ' .         God that Einstein eloquently wrote about for thirty years
       `,       `.   \        would be cosmic music resonating through eleven-dimensional hyper space.
      ,|,`.        `-.\     
     '.||  ``-...__..-`         Michio Kaku.
      |  |
      |__|
      /||\
     //||\\
    // || \\
 __//__||__\\__
'--------------'
               
)" << '\n';
	cout << ".:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.\n";
	
}
void end()
{
	cout << "_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_\n";
	cout << "\n";
	cout << "           THANKS FOR PLAY THE GAME         \n";
	cout << "\n";
	cout << "                                     I HOPE YOU ENJOYED PLAYING THE GAME  \n";
	cout << "\n";
	cout << "_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_\n";
	cout << R"(
      


                       |b
                       ||
                       ||,
                       |'\
                        |`|
                        | `|
                        '| |.
                         | `L
                         |  |,
                         `|  |.                              _,/7
                          |  `|                       __,---'' /
                          |   `|              __,---'"   ..- ./
                          ||   |      _.--=/'',--=-,,  -    ,/
                          `|   \,/'''`\,     /'   >  \     /'
                           | ,/'  `. .  `\ ,/'   / \  \   /'
                   ___,----Y-'      Y     7'   .'.' `\ \ /'
               _-/''        `\.     .   ,/'    /.'    `\\ 
           _,-''          ---  \    `  /'    ./.'   __-' "
        _/''     .--            `\    /'     /,'_--'
     ,/''  ..                     `"\_     ./ /
 .,/'                             .--"\    / / 
<------------------,_____      ,/~'  \ | ./ .'
                        `"""""""      `|_/\ /
                                        '  '
                                  
                              

    
)" << '\n';
	

	cout << "                                        Press enter to continue                  \n";
	cin.get();//allows to continue to the next screen
	//cout << " " << flush; //flush forces the printing to the screen before it clears
	system("pause");//so the cin.get don't pass without let the user press enter
	system("CLS");

	cout << R"(
      

                                   .--'...`-._
                                .-'..::::::::..\
                               /.:::::::::::::::\
                              |.::::::::::::::::.|
                             .-..::::::::::::::::|
                             | |\.\\|-\|//- \::::|
                             | | `-\ 'D| 'D|||)::|   uh..... you still here?...... did you like the game?
                             | |  ||   <    ||::.|               probably if you want you can keep playing.....
                             | |  |'        |/:__'              anyway thanks for playing.... 
                             | |   \\_ `  _  /=__=-             
                             | |      `--'   |::.`-.
                             | |      _|    _/\::::\
                             |_|     /#|  _/##'  \:|
                             |-|    |/|__/\#'     \'
                             | |  _/       //      \
                             | |_/________//        |
                             | |  ketchup   \|/     |
                             | |  <^|        `      |
                             | |  (__)       |      |
                            _|_|\_`'-'      ,'      |
                           ( __ 7 \--       |      .'
                           ( __V--.|        <      |
                           ( __)   |__.     |      |
                            `--'-._<     __-       |
                            _|_|\ \|_.--'  |      .'
                           (     /###/            |
                           /    |###/           _/\
                           (    |##/\__________/ |_\
                            `---`-\#-'          ||'=|
                             | |  /             |`--|
                             |_| |              |888|
                             |-| |              |8e--|
                             | |.'              |8|_=|
                             | ||                ||''|
                             | ||                |`-=|
                             | ||                1995|
                             | ||                10.--|
                             | ||                15|_=|
                             | ||                |.|''|
                             | ||                |8`-=|
                             |_||                |8e--|
                           _- v||                |8|_=|
                          |||. :|                |8|''|
                          \\.  .|________________'8`-=|
                           |:___|ee-----.ee.-----.8e--|
                            |==||8|__|__|88|__|__|8|_=|
                           /' |`\8|''|''|88|''|''|8|'''
                          |.  ||:|-------------------'
                         |..  ||.|  |   : :.  :.
                         |..  || |. |    | |   |
                        |.|.  | ..| |    | |   |
                        |...     .| |    | |    |
                        |..    .:.| |    |  |   |
                        |..     |.| |   .'  |   |
                        |:..|  .||  |   |   |   |
                         |..|   |'  |   |   |   |
                         |. |  :|   |   |   |___|
                          |.| :|'   |---|   |   |
                 _  _      ||  |    |   |   |== |
              __/_|/_/\_ _ | ||'   _/=  |   |.--|
           __-% /%\GST_/\%\ |||_.-| \   |  |.--.|
        ___\%\/%\-/75min/\\-. /___|-|___|  (____)
       /%/  /_///%\/\%\/%/\_/ `---------'  `----'
                '-'-'
             "Sweeping"
                              

    
)" << '\n';


	cout << "                                        Press enter to continue                  \n";
	cin.get();//allows to continue to the next screen
	//cout << " " << flush; //flush forces the printing to the screen before it clears
	system("pause");//so the cin.get don't pass without let the user press enter
	system("CLS");

}
void spaces()
{
	cout << " \n";
	cout << " \n";


}
