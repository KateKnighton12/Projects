/*
Katie Knighton
kmk0120
project2_Knighton_kmk0120.cpp



used https://www.tutorialspoint.com/cplusplus/cpp_references.htm to learn about references
used https://stackoverflow.com/questions/13871617/winmain-and-main-in-c-extended to look at some issue with main function
*/

# include <iostream>
# include <stdlib.h>
# include <assert.h>
# include <ctime>
using namespace std;

bool Aaron_alive;
bool Bob_alive;
bool Charlie_alive;

const int NUM_OF_RUNS = 10000;
const time_t START_TIME = time(0);
const int DECIMAL_PRECISION = 2;


//prototypes
void pause();
bool shootTarget(int probability);
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
void Aaron_shoots1(bool& B_alive, bool& C_alive);
void Bob_shoots(bool& A_alive, bool& C_alive);
void Charlie_shoots(bool& A_alive, bool& B_alive);
void Aaron_shoots2(bool& B_alive, bool& C_alive);
void Strategy(int strategy_num, int& Aaron_wins, int& Bob_wins, int& Charlie_wins);
void test_at_least_two_alive(void);
void test_Aaron_shoots1(void);
void test_Bob_shoots(void);
void test_Charlie_shoots(void);
void test_Aaron_shoots2(void);





int main() {

    //initialize win counter variables
    int Strategy1_Aaron_wins = 0,
        Strategy1_Bob_wins = 0,
        Strategy1_Charlie_wins = 0,
        Strategy2_Aaron_wins = 0,
        Strategy2_Bob_wins = 0,
        Strategy2_Charlie_wins = 0;

    srand(START_TIME);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(DECIMAL_PRECISION);

    cout << "\n*** Welcome to Katie's Truel of Fates Simulator ***\n";


    //unit tests
    test_at_least_two_alive();
    test_Aaron_shoots1();
    test_Bob_shoots();
    test_Charlie_shoots();
    test_Aaron_shoots2();


    //strategies
    Strategy(1, Strategy1_Aaron_wins, Strategy1_Bob_wins, Strategy1_Charlie_wins);

    cout << "Aaron won " << Strategy1_Aaron_wins << "/" << NUM_OF_RUNS << " duels or " << (float)100*Strategy1_Aaron_wins/NUM_OF_RUNS << "%\n";
    cout << "Bob won " << Strategy1_Bob_wins << "/" << NUM_OF_RUNS << " duels or " << (float)100*Strategy1_Bob_wins/NUM_OF_RUNS << "%\n";
    cout << "Charlie won " << Strategy1_Charlie_wins << "/" << NUM_OF_RUNS << " duels or " << (float)100*Strategy1_Charlie_wins/NUM_OF_RUNS << "%\n\n";

    Strategy(2, Strategy2_Aaron_wins, Strategy2_Bob_wins, Strategy2_Charlie_wins);

    cout << "Aaron won " << Strategy2_Aaron_wins << "/" << NUM_OF_RUNS << " duels or " << (float)100*Strategy2_Aaron_wins/NUM_OF_RUNS << "%\n";
    cout << "Bob won " << Strategy2_Bob_wins << "/" << NUM_OF_RUNS << " duels or " << (float)100*Strategy2_Bob_wins/NUM_OF_RUNS << "%\n";
    cout << "Charlie won " << Strategy2_Charlie_wins << "/" << NUM_OF_RUNS << " duels or " << (float)100*Strategy2_Charlie_wins/NUM_OF_RUNS << "%\n\n";

    if(Strategy2_Aaron_wins > Strategy1_Aaron_wins) {
        cout << "Strategy 2 is better than strategy 1.\n";
    }

    return 0;
}

//coppied from Project2.pdf
void pause() {
    cout << "Press Enter to continue...";
    cin.ignore().get();
}

bool shootTarget(int probability) {

    //coppied from Project2.pdf
    int shoot_rand;
    shoot_rand = rand()%100;

    return (shoot_rand <= probability);
}

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
    return ((A_alive && B_alive) || (B_alive && C_alive) || (C_alive && A_alive));
}

void Aaron_shoots1(bool& B_alive, bool& C_alive) {

    int shot_accuracy = 32;

    if(C_alive) {
        if(shootTarget(shot_accuracy)) {
            C_alive = false;
        }
    }
    else {
        if(shootTarget(shot_accuracy)) {
            B_alive = false;
        }
    }
}

void Bob_shoots(bool& A_alive, bool& C_alive) {

    int shot_accuracy = 49;

    if(C_alive) {
        if(shootTarget(shot_accuracy)) {
            C_alive = false;
        }
    }
    else {
        if(shootTarget(shot_accuracy)) {
            A_alive = false;
        }
    }

}

void Charlie_shoots(bool& A_alive, bool& B_alive) {

    if(B_alive) {
        B_alive = false;
    }
    else {
        A_alive = false;
    }

}

void Aaron_shoots2(bool& B_alive, bool& C_alive) {

    if(!B_alive || !C_alive) {
        Aaron_shoots1(B_alive, C_alive);
    }

}

void Strategy(int strategy_num, int& Aaron_wins, int& Bob_wins, int& Charlie_wins) {

    cout << "Ready to test Strategy" << strategy_num << " (run 10000 times)\n";
    pause();

    for(int i=0; i<NUM_OF_RUNS; i++) {

        Aaron_alive = true;
        Bob_alive = true;
        Charlie_alive = true;

        while(at_least_two_alive(Aaron_alive, Bob_alive, Charlie_alive)) {

            if(Aaron_alive) {
                if(strategy_num == 1) Aaron_shoots1(Bob_alive, Charlie_alive);
                else Aaron_shoots2(Bob_alive, Charlie_alive);
            }

            if(Bob_alive) Bob_shoots(Aaron_alive, Charlie_alive);
            if(Charlie_alive) Charlie_shoots(Aaron_alive, Bob_alive);
        }

        if(Aaron_alive) Aaron_wins++;
        else if(Bob_alive) Bob_wins++;
        else Charlie_wins++;

        
    }

}

void test_at_least_two_alive(void) {
    cout << "Unit Testing 1: Function - at_least_two_alive()\n";

    //111
    cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(true, true, true));
    cout << "\tCase passed ...\n";

    //011
    cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(false, true, true));
    cout << "\tCase passed ...\n";

    //101
    cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
    assert(true == at_least_two_alive(true, false, true));
    cout << "\tCase passed ...\n";

    //001
    cout << "\tCase 4: Aaron dead, Bob dead, Charlie alive\n";
    assert(false == at_least_two_alive(false, false, true));
    cout << "\tCase passed ...\n";

    //110
    cout << "\tCase 5: Aaron alive, Bob alive, Charlie dead\n";
    assert(true == at_least_two_alive(true, true, false));
    cout << "\tCase passed ...\n";

    //010
    cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
    assert(false == at_least_two_alive(false, true, false));
    cout << "\tCase passed ...\n";

    //100
    cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
    assert(false == at_least_two_alive(true, false, false));
    cout << "\tCase passed ...\n";

    //000
    cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
    assert(false == at_least_two_alive(false, false, false));
    cout << "\tCase passed ...\n";

    pause();
}

void test_Aaron_shoots1(void) {
    cout << "Unit Testing 2: Function - Aaron_shoots1()\n";

    //11
    cout << "\tCase 1: Bob alive, Charlie alive\n";
    Aaron_shoots1(Bob_alive = true, Charlie_alive = true);
    assert(true == Bob_alive);
    cout << "\t\tAaron is shooting at Charlie\n";

    //01
    cout << "\tCase 2: Bob dead, Charlie alive\n";
    Aaron_shoots1(Bob_alive = false, Charlie_alive = true);
    assert(false == Bob_alive);
    cout << "\t\tAaron is shooting at Charlie\n";

    //10
    cout << "\tCase 3: Bob alive, Charlie dead\n";
    Aaron_shoots1(Bob_alive = true, Charlie_alive = false);
    assert(false == Charlie_alive);
    cout << "\t\tAaron is shooting at Bob\n";

    pause();
}

void test_Bob_shoots(void) {
    cout << "Unit Testing 3: Function - Bob_shoots()\n";

    //11
    cout << "\tCase 1: Aaron alive, Charlie alive\n";
    Bob_shoots(Aaron_alive = true, Charlie_alive = true);
    assert(true == Aaron_alive);
    cout << "\t\tBob is shooting at Charlie\n";

    //01
    cout << "\tCase 2: Aaron dead, Charlie alive\n";
    Bob_shoots(Aaron_alive = false, Charlie_alive = true);
    assert(false == Aaron_alive);
    cout << "\t\tBob is shooting at Charlie\n";

    //10
    cout << "\tCase 3: Aaron alive, Charlie dead\n";
    Bob_shoots(Aaron_alive = true, Charlie_alive = false);
    assert(false == Charlie_alive);
    cout << "\t\tBob is shooting at Aaron\n";

    pause();
}

void test_Charlie_shoots(void) {
    cout << "Unit Testing 4: Function - Charlie_shoots()\n";

    //11
    cout << "\tCase 1: Aaron alive, Bob alive\n";
    Charlie_shoots(Aaron_alive = true, Bob_alive = true);
    assert(false == Bob_alive);
    cout << "\t\tCharlie is shooting at Bob\n";

    //01
    cout << "\tCase 2: Aaron dead, Bob alive\n";
    Charlie_shoots(Aaron_alive = false, Bob_alive = true);
    assert(false == Bob_alive);
    cout << "\t\tCharlie is shooting at Bob\n";

    //10
    cout << "\tCase 3: Aaron alive, Bob dead\n";
    Charlie_shoots(Aaron_alive = true, Bob_alive = false);
    assert(false == Aaron_alive);
    cout << "\t\tCharlie is shooting at Aaron\n";

    pause();
}

void test_Aaron_shoots2(void) {
    cout << "Unit Testing 5: Function - Aaron_shoots2()\n";

    //11
    cout << "\tCase 1: Aaron alive, Charlie alive\n";
    Aaron_shoots2(Aaron_alive = true, Charlie_alive = true);
    assert(true == Aaron_alive && true == Charlie_alive);
    cout << "\t\tAaron intentionally misses his shot\n\t\tBoth Bob and Charlie are alive.\n";

    //01
    cout << "\tCase 2: Bob dead, Charlie alive\n";
    Aaron_shoots2(Bob_alive = false, Charlie_alive = true);
    assert(false == Bob_alive);
    cout << "\t\tAaron is shooting at Charlie\n";

    //10
    cout << "\tCase 3: Bob alive, Charlie dead\n";
    Aaron_shoots2(Bob_alive = true, Charlie_alive = false);
    assert(false == Charlie_alive);
    cout << "\t\tAaron is shooting at Bob\n";

    pause();
}