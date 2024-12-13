//Introdueixo les llibreries que utilitzarem al joc.
#include <iostream>
#include <string>
#include <stdlib.h>
#include <Windows.h>
#include <cstdlib>
//Utilitzem aquest estandart
using namespace std;
//Declaro les funcions que vull utilitzar amb les variables que utilitzaré
void yes(string, string);
void no(string, string);
void questions();
void again();
int main()
{
    //Creo les variables necessaries per poder crear un menu
    char first;
    bool correct = true;
    cout << "Welcome to a world of strawberries!\nYou want to start the game? (y/n): ";
    //Comproba si l'usuari escriu y o n per començar la historia, si no tanca el programa.
    while (correct) {
        cin >> first;
        if (first == 'Y' || first == 'y')
        {
            //Crida la funció que dona inici al joc
            correct = false;
            system("CLS");
            questions();
        }
        else if (first == 'N' || first == 'n')
        {
            system("CLS");
            cout << "Then see you next time!";
            return 0;
        }   
        else
        {
            cout << "Please enter y or n: \n";
            correct = true;
        }
    }
}
//Començament de la funció
void questions()
{
    //El joc només té dues decisions i son couts de text per fer la historia.
    bool menu = true;
    string name, classmate = "Hitori";
    char decission;
    cout << "You enter to your new highschool, soon you notice something feels weird...\n"; Sleep(4000); //Sleep fa que el programa esperi 4 segons
    cout << "Someone catches your attention...\n\n"; Sleep(4000);
    cout << "However, you get closer to your classmate, it looks like he has something to tell you."; Sleep(4000); system("CLS");
    cout << classmate << ": WELCOME!\n"; Sleep(2000);
    cout << classmate << ": I heard you're new here, right?\n"; Sleep(4000);
    cout << classmate << ": It's a pleasure to meet you.\n"; Sleep(4000);
    cout << classmate << ": What's your name? "; cin >> name; system("CLS");//system cls fa que nateji per pantalla el text
    cout << name << ": I'm " << name << ".\n"; Sleep(4000);
    //Comproba si el nom del jugador és el mateix que el del company
    if (name == classmate)
    {
        cout << classmate << ": You have the same name as me :D\n"; Sleep(4000);
    }
    cout << classmate << ": Nice to meet you, " << name << ".\n\n" << endl; Sleep(4000);
    cout << classmate << ": I'm sure you're kinda lost...\n"; Sleep(4000);
    cout << classmate << ": But don't worry, we've all been there.\n"; Sleep(4000);
    cout << classmate << ": It's a relief to know not everyone it's the same here...\n"; Sleep(4000);
    cout << classmate << ": I thought I would be the only one who's not a strawberry.\n"; Sleep(4000);
    cout << classmate << ": Do you want me to guide you to our school so you can get to know it better?\n";
    cout << "(y/n): "; cin >> decission;
    //Depenent de la decisió, fara una funció o altre.
    while (menu)
    {
        if (decission == 'y' || decission == 'Y')
        {
            system("CLS");
            cout << "*He smiles at you briefly*\n"; Sleep(4000);
            cout << "*" << classmate << " takes your hand and shows you the playground*\n\n"; Sleep(4000);
            menu = false;
            //Passa les variables tipus string dvariable local
            yes(classmate, name);
        }
        else if (decission == 'n' || decission == 'N')
        {
            system("CLS");
            cout << "\*He looks at you surprised (Thought you would say yes...)*\n\n"; Sleep(4000);
            menu = false;
            //Passa les variables tipus string dvariable local
            no(classmate, name);
        }
        else{
            cout << "You have to select between y or n)";
            menu = true;
        }  
    }
}
//La funció necessita les variables string amb el nom de la variable per poder ser utilitzades.
void yes(string classmate, string name){
    cout << classmate << ": Here's our lovely playground...\n"; Sleep(4000);
    cout << classmate << ": Lovely whenever Misaki's group isn't here...\n"; Sleep(4000);
    cout << classmate << ": If you ever meet a group of strawberries, never approach them... DON'T EVEN LOOK AT THEM!!!\n"; Sleep(4000);
    cout << classmate << ": They're horrible...\n"; Sleep(4000);
    cout << classmate << ": Anyways, let's continue with our tour.\n\n"; Sleep(4000);
    cout << "*Takes your hand again and shows you where the canteen is*\n\n"; Sleep(4000);
    cout << classmate << ": Well, this is our canteen.\n"; Sleep(4000);
    cout << classmate << ": Honestly it's kinda small, and the food tastes like garbage.\n"; Sleep(4000);
    cout << classmate << ": At least you can make good friends here!\n"; Sleep(4000);
    cout << classmate << ": Or maybe not...\n\n"; Sleep(4000);
    cout << "*For one last time, forcefully holds your hand again*\n\n"; Sleep(4000);
    cout << classmate << ": Finally, here's where you'll be for the rest of the course."; Sleep(4000); system("CLS");
    cout << "*The bell starts ringing*\n\n"; Sleep(4000);
    cout << classmate << ": Welp, I have to go to my class... Good luck with your first day, " << name << "!\n\n"; Sleep(4000);
    cout << "*Your first class ends, this place dosen't look that bad to you after all*\n\n"; Sleep(4000); system("CLS");
    cout << "Good ending.\n\n"; Sleep(5000);
    again();
}
void no(string classmate, string name){  
    string abuser = "Misaki";
    int laugh = 0;
    double randomizer;
    cout << classmate << ": ...\n"; Sleep(4000);
    cout << classmate << ": *Sigh*\n"; Sleep(4000);
    cout << classmate << ": I see, we have to go to class anyways, good luck!\n\n";Sleep(4000);
    cout << "*He goes out of the class, looking sad at the ground*\n\n"; Sleep(4000); system("CLS");
    cout << name << ": It's strange.\n"; Sleep(4000);
    cout << name << ": Everything it's so pink, unlike him.\n"; Sleep(4000);
    cout << name << ": There's something wrong.\n\n"; Sleep(4000);
    cout << "*Suddenly, you see that someone approches you*\n\n"; Sleep(4000); system("CLS");
    cout << abuser << ": Hey, you have to be the new kid.\n"; Sleep(4000);
    cout << abuser << ": I was looking at you while you were talking to that weirdo...\n"; Sleep(4000);
    cout << abuser << ": But now that I can see you closer, it looks like you two are the same, fucking weirdos...\n"; Sleep(4000);
    cout << abuser << ": You should rot with the weirdos too.\n"; Sleep(4000);
    cout << abuser << ": Go with your kind.\n"; Sleep(4000);
    cout << abuser << ": There's no space in the school for non strawberry people, you know?\n"; Sleep(4000); system("CLS");
    //Repeteix 73 vegades aleatoriament una de les condicions segons un numero aleatori generat d'un entre quatre.
    while (laugh !=72)
    {
        randomizer = rand() % 4 + 1;
        if (randomizer == 1)
        {
            cout << " HAHAHAHAHAHAHAAHAHAHAHAHAHAHAHAHAHAHAAHAHAH "; Sleep(100);
        }
        else if (randomizer == 2 )
        {
            cout << " HAHAHHAHAHAHAHAHHAHAHAHAHAHAHAHHAH "; Sleep(100);
        }
        else if (randomizer == 3) {
            cout << " HAHAHAHAHAHHAHAAHA "; Sleep(100);
        }
        else
        {
            cout << " AHAHAAHHAHHAHAAHHAHAHA "; Sleep(100);
        }
        laugh++;
    }
    Sleep(2000); system("CLS");
    cout << "\n\n*She pushes you and you fall off*\n\n"; Sleep(4000); system("CLS");
    cout << "(Talking to yourself)\n\n";
    cout << name << ": I see, things work like this here, right?\n"; Sleep(4000);
    cout << name << ": Today has been a bad day, and probabbly it won't be the only one. It only depends on your luck, right?\n"; Sleep(4000);
    cout << name << ": Well, I will have to get to know about the rules of this place...\n"; Sleep(4000);
    cout << name << ": I don't know you, and you don't know me... But I don't think it's necessary just to know where our roles are...\n\n"; Sleep(4000); system("CLS");
    cout << "Bad ending...\n\n"; Sleep(5000);
    again();
}
//La funció pregunta si el jugador vol tornar a jugar, és exactament igual que el primer menú.
void again() {
    char first;
    bool correct = true;
    cout << "Would you like to play again? (y/n): ";
    while (correct) {
        cin >> first;
        if (first == 'Y' || first == 'y')
        {
            system("CLS");
            correct = false;
            questions();
        }
        else if (first == 'N' || first == 'n')
        {
            system("CLS");
            cout << "Then see you next time!";
            correct = false;
        }
        else
        {
            cout << "Please enter y or n\n";
            correct = true;
        }
    }
}
