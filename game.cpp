#include <iostream>
#include <fstream>
#include "GUILib.h"
using namespace std;

void displayalien(float initial_x, float initial_y, float final_x, float final_y, float bull_x, float bull_y, bool alien_present[]) {
    float xin = initial_x;
    int k = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            if (!alien_present[k]) {        //if alien is collided
                myRect(initial_x, initial_y, final_x, final_y, 0, 0, 0);
                myRect(initial_x + 4, initial_y + 5, final_x - 12, final_y - 10, 0, 0, 0);
                myRect(initial_x + 12, initial_y + 5, final_x - 4, final_y - 10, 0, 0, 0);
                myLine(initial_x + 6, initial_y - 7, final_x - 10, final_y - 20, 0, 0, 0);
                myLine(initial_x + 14, initial_y - 7, final_x - 10, final_y - 20, 0, 0, 0);
            }
            else {
                myRect(initial_x, initial_y, final_x, final_y, 183, 104, 162);
                myRect(initial_x + 4, initial_y + 5, final_x - 12, final_y - 10, 250, 230, 250);
                myRect(initial_x + 12, initial_y + 5, final_x - 4, final_y - 10, 250, 230, 250);
                myLine(initial_x + 6, initial_y - 7, final_x - 10, final_y - 20, 250, 230, 250);
                myLine(initial_x + 14, initial_y - 7, final_x - 10, final_y - 20, 250, 230, 250);
            }

            initial_x += 50;
            final_x += 50;
            k++;
        }
        initial_y += 50;
        final_y += 50;
        initial_x = xin;
        final_x = initial_x + 20;
    }
}
void checkCollisionAndErase(float& bull_x, float& bull_y, bool& strike, int& score, float alien_arr[][4], bool alien_present[]) {
    for (int i = 0; i < 50; i++) {
        if (alien_present[i]) {
            if (bull_x >= alien_arr[i][0] && bull_x <= alien_arr[i][1] &&
                bull_y >= alien_arr[i][2] && bull_y <= alien_arr[i][3]) {
                // Collision detected
                alien_present[i] = false;
                myRect(alien_arr[i][0], alien_arr[i][2], alien_arr[i][1], alien_arr[i][3], 0, 0, 0); // Erase alien
                myRect(bull_x, bull_y, bull_x + 10, bull_y + 10, 0, 0, 0);

                bull_x = -1;
                bull_y = -1;
                strike = true;
                score += 10; // Increment score
                break;
            }
        }
    }
}
void erasealien(float initial_x, float initial_y, float final_x, float final_y) {
    float xin = initial_x;
    float xf = final_x;
    float yin = initial_y;
    float yf = final_y;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            myRect(initial_x, initial_y, final_x, final_y, 0, 0, 0);
            myRect(initial_x + 4, initial_y + 5, final_x - 12, final_y - 10, 0, 0, 0);
            myRect(initial_x + 12, initial_y + 5, final_x - 4, final_y - 10, 0, 0, 0);
            myLine(initial_x + 6, initial_y - 7, final_x - 10, final_y - 20, 0, 0, 0);
            myLine(initial_x + 14, initial_y - 7, final_x - 10, final_y - 20, 0, 0, 0);
            initial_x += 50;
            final_x += 50;
        }
        initial_y += 50;
        final_y += 50;
        initial_x = xin;
        final_x = initial_x + 20;
    }
}
void displayship(int x1, int x2, int y1, int y2, int peaky) {
    //main triangle
    myLine(x1, y1, x2, peaky, 193, 38, 184);           //upper
    myLine(x1, y2, x2, peaky, 193, 38, 184);           //lower
    myLine(x1, y1, x1, y2, 193, 38, 184);             //straight
    myLine(x1, y1 - 20, x1, y1, 156, 81, 182);        //upper straight
    myLine(x1, y2, x1, y2 + 20, 156, 81, 182);        //lower straight
    // side triangles
    myLine(x1, y1 - 20, (x1 + x2) / 2, (peaky + y1) / 2, 156, 81, 182);            //upper
    myLine(x1, y2 + 20, (x1 + x2) / 2, (peaky + y2) / 2, 156, 81, 182);    //lower
    myRect(x1 - 15, y1, x1, y2, 166, 58, 121);                             //back rectangle
    //sparkle
    myLine(x1 - 30, (y1 + y2) / 2 + 25, x1 - 15, (y1 + y2) / 2 + 2, 160, 32, 240);            //4
    myLine(x1 - 40, (y1 + y2) / 2 + 9, x1 - 15, (y1 + y2) / 2 + 1, 160, 32, 240);          //3
    myLine(x1 - 38, (y1 + y2) / 2 - 7, x1 - 15, (y1 + y2) / 2 - 1, 160, 32, 240);        //2
    myLine(x1 - 47, (y1 + y2) / 2 - 23, x1 - 15, (y1 + y2) / 2 - 2, 160, 32, 240);       //1
}
void eraseship(int x1, int x2, int y1, int y2, int peaky) {
    //main triangle
    myLine(x1, y1, x2, peaky, 0, 0, 0);           //upper
    myLine(x1, y2, x2, peaky, 0, 0, 0);           //lower
    myLine(x1, y1 - 20, x1, y2 + 20, 0, 0, 0);        //straight
    // side triangles
    myLine(x1, y1 - 20, (x1 + x2) / 2, (peaky + y1) / 2, 0, 0, 0);            //upper
    myLine(x1, y2 + 20, (x1 + x2) / 2, (peaky + y2) / 2, 0, 0, 0);    //lower
    myRect(x1 - 15, y1, x1, y2, 0, 0, 0);                             //back rectangle
    //sparkle
    myLine(x1 - 30, (y1 + y2) / 2 + 25, x1 - 15, (y1 + y2) / 2 + 2, 0, 0, 0);            //4
    myLine(x1 - 40, (y1 + y2) / 2 + 9, x1 - 15, (y1 + y2) / 2 + 1, 0, 0, 0);          //3
    myLine(x1 - 38, (y1 + y2) / 2 - 7, x1 - 15, (y1 + y2) / 2 - 1, 0, 0, 0);        //2
    myLine(x1 - 47, (y1 + y2) / 2 - 23, x1 - 15, (y1 + y2) / 2 - 2, 0, 0, 0);       //1
}
void movealien(float& almovin_x, float& almovin_y, float& almovf_x, float& almovf_y, float bull_x, float bull_y, bool& almovcount, bool alien_present[]) {

    if (almovin_x < 10) {               //here the condition to stop the aliens will come
        almovf_y = 330;
        almovin_y = -3;
    }
    else if (almovf_y == 250 || almovin_y == 25)     //condition for movement inside the boundary
    {
        if (almovf_y == 250) {
            erasealien(almovin_x, almovin_y - 20, almovf_x, almovf_y - 19.1);
            almovin_x -= 25;
            almovf_x -= 25;
            displayalien(almovin_x, almovin_y, almovf_x, almovf_y, bull_x, bull_y, alien_present);
            erasealien(almovin_x + 25, almovin_y, almovf_x + 25, almovf_y);

            almovin_y -= 1;
            almovf_y -= 1;
            almovcount = 1;
        }
        else {
            erasealien(almovin_x, almovin_y - 20, almovf_x, almovf_y - 19.1);
            almovin_x -= 25;
            almovf_x -= 25;
            displayalien(almovin_x, almovin_y, almovf_x, almovf_y, bull_x, bull_y, alien_present);
            erasealien(almovin_x + 25, almovin_y, almovf_x + 25, almovf_y);

            almovin_y += 1;
            almovf_y += 1;
            almovcount = 0;
        }
    }
    else if (almovin_y > 25 && almovf_y < 250) {     //boundary limit
        if (almovcount == 0) {
            if (almovf_y < 250) {
                erasealien(almovin_x, almovin_y - 20, almovf_x, almovf_y - 19.1);
                almovin_y += 1;
                almovf_y += 1;
                displayalien(almovin_x, almovin_y, almovf_x, almovf_y, bull_x, bull_y, alien_present);
                erasealien(almovin_x, almovin_y - 20, almovf_x, almovf_y - 19.1);
            }
        }
        else if (almovcount == 1) {
            if (almovin_y > 25)
            {
                erasealien(almovin_x, almovin_y + 20, almovf_x, almovf_y + 19.1);
                almovin_y -= 1;
                almovf_y -= 1;
                displayalien(almovin_x, almovin_y, almovf_x, almovf_y, bull_x, bull_y, alien_present);
                erasealien(almovin_x, almovin_y + 20, almovf_x, almovf_y + 19.1);
            }
        }
    }
}
void displaylives() {

    int i_x = 830;
    int i_y = 450;
    for (int i = 0; i < 3; i++) {
        myLine(i_x, i_y, i_x + 25, i_y, 228, 0, 120);
        myLine(i_x, i_y, i_x + 12.5, i_y - 25, 228, 0, 120);
        myLine(i_x + 12.5, i_y - 25, i_x + 25, i_y, 228, 0, 120);
        i_x += 45;
    }

}
void eraselives(int count) {

    int i_x = 830;
    int i_y = 450;
    for (int i = 0; i < count; i++) {
        myLine(i_x, i_y, i_x + 25, i_y, 0, 0, 0);
        myLine(i_x, i_y, i_x + 12.5, i_y - 25, 0, 0, 0);
        myLine(i_x + 12.5, i_y - 25, i_x + 25, i_y, 0, 0, 0);
        i_x += 45;
    }

}

void sleep(int milliseconds) {
    clock_t startTime = clock();
    while (clock() < startTime + milliseconds * CLOCKS_PER_SEC / 1000);
}
int main() {
    // win check
    bool win = true;
    //pause variable
    bool paused = false;
    //ship variables
    int x1, x2, y1, y2, peaky;
    //bullet variables
    float bull_x;
    float bull_y;
    int whichKey;
    //moving aliens variables
    float almovin_x;
    float almovf_x;
    float almovin_y;
    float almovf_y;
    bool almovcount;
    bool strike;
    int lives = 0;
    //score variable
    int score;
    // Alien grid initialize
    float alien_arr[50][4];
    bool alien_present[50];
    int k = 0;

    //read data
    ifstream inFile("data.txt");
    inFile >> x1;
    inFile >> x2;
    inFile >> y1;
    inFile >> y2;
    inFile >> peaky;
    inFile >> bull_x;
    inFile >> bull_y;
    inFile >> almovin_x;
    inFile >> almovf_x;
    inFile >> almovin_y;
    inFile >> almovf_y;
    inFile >> almovcount;
    inFile >> strike;
    inFile >> lives;
    inFile >> score;
    inFile >> win;
    for (int i = 0; i < 50; i++) {
        inFile >> alien_present[i];
    }
    inFile.close();

    //resume choice
    if (lives > 0 && lives <= 3 && win == false) {
        bool option;
        cout << "Do you want to resume the game from last dropped (1 or 0)" << endl;
        cin >> option;
        if (option == 0) {
            x1 = 70, x2 = 130, y1 = 80, y2 = 120, peaky = 100;
            bull_x = -1;
            bull_y = -1;
            almovin_x = 350;
            almovf_x = almovin_x + 20;
            almovin_y = 25;
            almovf_y = almovin_y + 20;
            almovcount = 0;
            strike = false;
            lives = 3;
            //score initialize
            score = 0;
            for (int i = 0; i < 50; i++) {
                alien_present[i] = true;
            }
            k = 0;
        }
        else if (option == 1) {
            //read data
            ifstream inFile("data.txt");
            inFile >> x1;///1
            inFile >> x2;//2
            inFile >> y1;//3
            inFile >> y2;//4
            inFile >> peaky;//5
            inFile >> bull_x;//6
            inFile >> bull_y;//7
            inFile >> almovin_x;//8
            inFile >> almovf_x;//9
            inFile >> almovin_y;//10
            inFile >> almovf_y;//11
            inFile >> almovcount;//12
            inFile >> strike;//13
            inFile >> lives;//14
            inFile >> score;//15
            inFile >> win;//16
            for (int i = 0; i < 50; i++) {
                inFile >> alien_present[i];
            }//66
            inFile.close();
        }
        myRect(0, 0, 450, 50, 0, 0, 0);
    }
    else if (lives == 0 || win == true) {
        x1 = 70, x2 = 130, y1 = 80, y2 = 120, peaky = 100;
        bull_x = -1;
        bull_y = -1;
        almovin_x = 350;
        almovf_x = almovin_x + 20;
        almovin_y = 25;
        almovf_y = almovin_y + 20;
        almovcount = 0;
        strike = false;
        lives = 3;
        //score initialize
        score = 0;
        // Alien grid initialize
        for (int i = 0; i < 50; i++) {
            alien_present[i] = true;
        }
        k = 0;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            alien_arr[k][0] = almovin_x + j * 50;        //start x
            alien_arr[k][1] = alien_arr[k][0] + 20;     //end x
            alien_arr[k][2] = almovin_y + i * 50;       //start y
            alien_arr[k][3] = alien_arr[k][2] + 20;     //end y
            k++;
        }
    }

    while (true) {
        displayship(x1, x2, y1, y2, peaky);

        bool keyPressed = isKeyPressed(whichKey);
        if (keyPressed == true) {
            if (whichKey == 1) {		//left key
                eraseship(x1, x2, y1, y2, peaky);
                x1 -= 5;
                x2 -= 5;
                displayship(x1, x2, y1, y2, peaky);
            }
            if (whichKey == 2) {		//up key
                eraseship(x1, x2, y1, y2, peaky);
                y1 -= 5;
                y2 -= 5;
                peaky -= 5;
                displayship(x1, x2, y1, y2, peaky);
            }
            if (whichKey == 3) {		//right key
                eraseship(x1, x2, y1, y2, peaky);
                x1 += 5;
                x2 += 5;
                displayship(x1, x2, y1, y2, peaky);
            }
            if (whichKey == 4) {		//down key
                eraseship(x1, x2, y1, y2, peaky);
                y1 += 5;
                y2 += 5;
                peaky += 5;
                displayship(x1, x2, y1, y2, peaky);
            }
            if (whichKey == 8 && bull_x == -1 && bull_y == -1) {  //shoot by using space
                bull_x += (x2 + 2);
                bull_y = peaky;
                myRect(bull_x, bull_y, bull_x + 8, bull_y + 3, 250, 230, 250);
            }
            if (whichKey == 7) {		//pause by using esc
                paused = !paused;
                if (paused) {
                    myRect(180, 135, 700, 250, 112, 41, 99);
                    drawText(45, 200, 150, 112, 41, 99, "Game Paused");
                }
                else {
                    myRect(180, 135, 700, 250, 0, 0, 0);
                }
            }
        }
        //pause code
        if (paused) {
            continue;
        }

        //collisions checking
        checkCollisionAndErase(bull_x, bull_y, strike, score, alien_arr, alien_present);
        int k = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 10; j++) {
                alien_arr[k][0] = almovin_x + j * 50;        //start x
                alien_arr[k][1] = alien_arr[k][0] + 20;     //end x
                alien_arr[k][2] = almovin_y + i * 50;       //start y
                alien_arr[k][3] = alien_arr[k][2] + 20;     //end y
                k++;
            }
        }
        //move bullet
        if (bull_x < 940 && bull_x != -1) {
            myRect(bull_x, bull_y, bull_x + 8, bull_y + 3, 0, 0, 0);
            bull_x += 15;
            myRect(bull_x, bull_y, bull_x + 8, bull_y + 3, 250, 230, 250);
        }
        else if (bull_x >= 940) {
            myRect(bull_x, bull_y, bull_x + 8, bull_y + 3, 0, 0, 0); // Stop bullet
            bull_x = -1;
            bull_y = -1;
            strike = false;
        }

        //move alien
        movealien(almovin_x, almovin_y, almovf_x, almovf_y, bull_x, bull_y, almovcount, alien_present);
        myRect(15, 0, 200, 40, 228, 0, 120);
        drawText(15, 20, 5, 228, 0, 120, "Score = ", true, score);
        displaylives();

        drawText(15, 830, 380, 0, 0, 0, "Lives ", true, lives);


        // Checking if ship moves ahead of aliens
        if (x2 > almovin_x) {
            lives--;
            eraselives(3 - lives);

            //score reduction on one life reduction
            score -= 20;
            // Reset ship position
            eraseship(x1, x2, y1, y2, peaky);
            x1 = 70;
            x2 = 130;
            y1 = 80;
            y2 = 120;
            peaky = 100;
            // Reset alien position
            erasealien(almovin_x, almovin_y - 5, almovf_x, almovf_y + 5);
            almovin_x = 350;
            almovf_x = almovin_x + 20;
            almovin_y = 25;
            almovf_y = almovin_y + 20;
            almovcount = 0;
        }
        eraselives(3 - lives);
        //show lives
        drawText(15, 830, 380, 147, 112, 219, "Lives ", true, lives);
        // win chack
        win = true;
        for (int i = 0; i < 50; i++) {
            if (alien_present[i] == true) {
                win = false;
            }
        }

        // Save data to file
        ofstream outFile("data.txt");
        outFile << x1 << endl; //1
        outFile << x2 << endl;//2
        outFile << y1 << endl;//3
        outFile << y2 << endl;//4
        outFile << peaky << endl;//5
        outFile << bull_x << endl;//6
        outFile << bull_y << endl;//7
        outFile << almovin_x << endl;//8
        outFile << almovf_x << endl;//9
        outFile << almovin_y << endl;//10
        outFile << almovf_y << endl;//11
        outFile << almovcount << endl;//12
        outFile << strike << endl;//13
        outFile << lives << endl;//14
        outFile << score << endl;//15
        outFile << win << endl;//16
        for (int i = 0; i < 50; i++) {
            outFile << alien_present[i] << endl;
        }//66
        outFile.close();

        //End Game if player has won
        if (win == true) {
            myRect(180, 130, 700, 300, 112, 41, 99);
            drawText(60, 200, 150, 112, 41, 99, "You Win");
            sleep(2500);
            break;
        }

        // End game if no lives are left
        if (lives == 0) {
            myRect(180, 130, 800, 300, 112, 41, 99);
            drawText(60, 200, 150, 112, 41, 99, "Game Over");
            sleep(2500);
            break;
        }
    }
    return 0;
}