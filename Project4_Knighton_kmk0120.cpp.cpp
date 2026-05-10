//-------------------------------------------------------------------------------------------------------//
//          Author:         Katie Knighton kmk0120                                                       //
//          Project Name:   Project4_Knighton_kmk0120.cpp                                                //
//          Version:        Version1                                                                     //
//          Rescources:     https://www.youtube.com/watch?app=desktop&v=lSIoWv92rrU                      //
//                          https://stackoverflow.com/questions/35511934/node-pointer-in-the-definition-of-node-itself-how-does-it-work

//-------------------------------------------------------------------------------------------------------//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//start initializing variables//
// this is just to count num questions//
int numQ = 0;
int numP = 0;

//node structure//
struct QNode{
    string question;
    string answer;
    int points;
    int numChoices = 0;
    string choiceA;
    string choiceB;
    string choiceC;
    string choiceD;
    string choiceE;
    QNode *next;
    string type;
};
typedef QNode* pointerNode;


//functions//


void editQuestion(pointerNode & Qlist, int numQuestionEdit);
void deleteQuestion(pointerNode & Qlist, int numQuestionDelete);
void mcq(pointerNode & Qlist);
void tf(pointerNode & Qlist);
void wr(pointerNode & Qlist);
void startTest(pointerNode & Qlist);
void UnitTest();


#ifdef UNIT_TESTING

void UnitTests() {
    // Test Case 1: verify total number of questions and points work in final assesment
    {
        pointerNode list = new QNode;
        Qnode-> po
        cout << "Test Case 1 Passed" << endl;
    }

}

int main() {
    cout << "*** Running Unit Tests ***" << endl;
    runTests();
    cout << "*** All Unit Tests Passed ***" << endl;
    return 0;
}

#else
//main//
int main(){

    
    pointerNode nodeList = new QNode;
    string actionInput;
    string inputTypeQuestion;
    int numQuestionEdit;
    int numQuestionDelete;
    string inputYN;
    int check = 2;

    //user output welcome
    cout << " *** Welcome to Katie's Testing Service *** \n";
    cout << "\n";

    do{
        cout << "\n";
        cout << "Do you want to?\n";
        cout << "   1. Create a new question.\n";
        cout << "   2. Edit question.\n";
        cout << "   3. Delete question.\n";
        cout << "   4. Finish.\n";
        cout << "Select an action: ";
        cin >> actionInput;
        cout << "\n";

        if(actionInput.compare("quit")==0 || actionInput.compare("Quit") == 0 || actionInput.compare("1") == 0 || actionInput.compare("2")==0 || actionInput.compare("3")==0 || actionInput.compare("4")== 0){
            //action input differnt outcombs//
            if(actionInput.compare("1") == 0){
                
                cout << "=== QUESTION " << numQ+1 << " ===\n";
                cout << "Type of question[mcq/tf/wr]: \n";
                cin >> inputTypeQuestion;

                while(check == 2){
                    if (inputTypeQuestion.compare("quit") == 0 || inputTypeQuestion.compare("Quit") == 0 || inputTypeQuestion.compare("mcq")==0 || inputTypeQuestion.compare("tf")== 0 || inputTypeQuestion.compare("wr")== 0){
                        check = 1;
                        if(inputTypeQuestion.compare("quit")== 0 || inputTypeQuestion.compare("Quit")== 0){
                           cout << "*** Thank you for using the testing service. Goodbye ***\n";
                           return 0;

                        }
                        
                        if (inputTypeQuestion.compare("mcq")== 0){
                            mcq(nodeList);


                        }
                        if (inputTypeQuestion.compare("tf")== 0){
                            tf(nodeList);
                        }
                        if (inputTypeQuestion.compare("wr")== 0){
                            wr(nodeList);
                        }
                    }
                    else{
                        cout << "Input for type of question is invalid please try again.\n";
                        cin >> inputTypeQuestion;
                    }
                }
            
            }

            if(actionInput.compare("2") == 0){
                if(numQ != 0){
                    cout << "Select a question to edit [1-" << numQ << "]: \n";
                    cin >> numQuestionEdit;
                    if (numQuestionEdit >= 1 && numQuestionEdit <=numQ){
                        editQuestion(nodeList, numQuestionEdit);
                    }
                    else{
                        cout << "Question is invalid. Bringing you back to the selection. Try selecting edit again and entering a valid question number.\n";
                    }


                }
                else {
                    cout << "You have not made any questions in order to be able to edit them. Try creating some questions first! Bringing you back to selection.\n";
                }
            }
            if(actionInput.compare("3") == 0){
                if(numQ != 0){
                    cout << "Select a question to delete [1-" << numQ << "]: \n";
                    cin >> numQuestionDelete;
                    if (numQuestionDelete >= 1 && numQuestionDelete <= numQ){
                        deleteQuestion(nodeList, numQuestionDelete);
                    }
                    else{
                        cout << "Question is invalid. Bringing you back to the selection. Try selecting delete again and entering a valid question number.\n";

                    }
                }
                else {
                    cout <<"You have not made any questions in order to be able to delete them. Try creating some questions first! Bringing you back to selection.\n";
                }
            }

              
            if (actionInput.compare("4") == 0){
                cout << "=== SESSION LOG ===\n";
                cout << "Total quesions: " << numQ << "\n";
                cout << "Total point values: " << numP << "\n";
                cout << "\n";
                cout << "!!! Begin assessment?[y/n]: \n";
                cin >> inputYN;
                if(inputYN.compare("quit")==0 || inputYN.compare("Quit")==0 || inputYN.compare("y")==0 || inputYN.compare("Y") == 0 || inputYN.compare("n")== 0 || inputYN.compare("N") == 0){
                    if(inputYN.compare("quit") == 0 || inputYN.compare("Quit") == 0){
                        cout << "*** Thank you for using the testing service. Goodbye! ***\n";
                        return 0;
                    }
                    if (inputYN.compare("y")== 0 || inputYN.compare("Y") == 0){
                        startTest(nodeList);
                    }
                    if (inputYN.compare("n")== 0 || inputYN.compare("N") == 0){
                        cout << "You chose not to begin the assesment. Bringing you back to selection. \n";
                    }
                }
                else {
                    cout << "invalid input. Bringing you back to the selection. Try choosing Finish again during selection and typing a valid input.\n";

                }
            
            }
            if (actionInput.compare("quit")== 0 || actionInput.compare("Quit") == 0){
                cout << "*** Thank you for using the testing service. Goodbye! ***\n";
                return 0;
            }
        }
        else{
            cout << "Invalid selection. Please choose 1, 2, 3, or 4.\n";
        }

    }while(actionInput.compare("quit") != 0 || actionInput.compare("Quit") != 0);

    cout << "*** Thank you for using the testing service. Goodbye! ***\n";
    return 0;


}
#endif

void mcq(pointerNode & Qlist){
    pointerNode newPtr = new QNode;
    int check = 0;
    newPtr->type = "mcq";
    
    

    cout << "Enter a question\n";
    getline(cin, newPtr->question);
    cout << "At anytime type 'quit' to quit\n";
    cout << "\n";
    cout << "Enter choice A: \n";
    getline(cin, newPtr->choiceA);
    if (newPtr->choiceA == "quit" || newPtr->choiceA == "Quit"){
        cout << "Select correct answer:\n";
        getline(cin, newPtr->answer);
        while(check = 0){
            if (newPtr->answer == "A" || newPtr->answer == "a"){
                check = 1;
                
            }
            else {
                cout << "Invalid answer please try again.";
                getline(cin, newPtr->answer);
            }
        }
        cout << "Enter point value:\n";
        cin >> newPtr->points;
        cin.ignore();
        numP = numP+newPtr->points;
        newPtr->next=NULL;
        newPtr->numChoices = 1;

        QNode* last = Qlist;
        while(last->next != NULL){
            last = last->next;
        }
        last->next =newPtr;
        numQ++;
        cout << "Question saved.\n";
        
        
        return;
    }
    else{
        newPtr->numChoices++;
        cout << "Enter choice B:\n";
        getline(cin,newPtr->choiceB);
        if (newPtr->choiceB == "quit" || newPtr->choiceB == "Quit"){
            cout << "Select correct answer:\n";
            getline(cin, newPtr->answer);
            while(check = 0){
                if (newPtr->answer == "A" || newPtr->answer == "a" || newPtr->answer == "B" || newPtr->answer == "b"){
                    check = 1;
                
                }
                else {
                    cout << "Invalid answer please try again.";
                    getline(cin, newPtr->answer);
                }
            }
            cout << "Enter point value:\n";
            cin >> newPtr->points;
            cin.ignore();
            newPtr->next=NULL;
            numP = numP+newPtr->points;
            newPtr->numChoices = 2;

            QNode* last = Qlist;
            while(last->next != NULL){
                last = last->next;
            }
            last->next =newPtr;
            numQ++;
            cout << "Question saved.\n";
            
            return;
        }
        else{
            newPtr->numChoices++;
            cout << "Enter choice C:\n";
            getline(cin, newPtr->choiceC);
            if (newPtr->choiceC == "quit" || newPtr->choiceC == "Quit"){
                cout << "Select correct answer:\n";
                getline(cin, newPtr->answer);
                while(check = 0){
                    if (newPtr->answer == "A" || newPtr->answer == "a" || newPtr->answer == "B" || newPtr->answer == "b" || newPtr->answer == "C" || newPtr->answer == "c"){
                        check = 1;
                
                    }
                    else {
                        cout << "Invalid answer please try again.";
                        getline(cin, newPtr->answer);
                    }
                }
                cout << "Enter point value:\n";
                cin >> newPtr->points;
                cin.ignore();
                newPtr->next=NULL;
                newPtr->numChoices = 3;
                numP = numP+newPtr->points;

                QNode* last = Qlist;
                while(last->next != NULL){
                    last = last->next;
                }
                last->next =newPtr;
                numQ++;
                cout << "Question saved.\n";
                return;
            }
            else{
                newPtr->numChoices++;
                cout << "Enter choice D:\n";
                getline(cin, newPtr->choiceD);
                if (newPtr->choiceD == "quit" || newPtr->choiceD == "Quit"){
                    cout << "Select correct answer:\n";
                    getline(cin, newPtr->answer);
                    while(check = 0){
                        if (newPtr->answer == "A" || newPtr->answer == "a" || newPtr->answer == "B" || newPtr->answer == "b" || newPtr->answer == "C" || newPtr->answer == "c" || newPtr->answer == "D" || newPtr->answer == "d" ){
                            check = 1;
                
                        }
                        else {
                            cout << "Invalid answer please try again.";
                            getline(cin, newPtr->answer);
                        }
                    }
                    cout << "Enter point value:\n";
                    cin >> newPtr->points;
                    cin.ignore();
                    newPtr->next=NULL;
                    newPtr->numChoices = 4;
                    numP = numP+newPtr->points;

                    QNode* last = Qlist;
                    while(last->next != NULL){
                        last = last->next;
                    }
                    last->next =newPtr;
                    numQ++;
                    cout << "Question saved.\n";
                    return;
                }
                else{
                    newPtr->numChoices++;
                    cout << "Enter choice E:\n";
                    getline(cin,newPtr->choiceE);
                    if (newPtr->choiceE == "quit" || newPtr->choiceE == "Quit"){
                        cout << "Select correct answer:\n";
                        getline(cin, newPtr->answer);
                        while(check = 0){
                            if (newPtr->answer == "A" || newPtr->answer == "a" || newPtr->answer == "B" || newPtr->answer == "b" || newPtr->answer == "C" || newPtr->answer == "c" || newPtr->answer == "D" || newPtr->answer == "d" || newPtr->answer == "E" || newPtr->answer == "e" ){
                                check = 1;
                
                            }
                            else {
                                cout << "Invalid answer please try again.";
                                getline(cin, newPtr->answer);
                            }
                        }
                        cout << "Enter point value:\n";
                        cin >> newPtr->points;
                        cin.ignore();
                        newPtr->next=NULL;
                        newPtr->numChoices = 5;
                        numP = numP+newPtr->points;

                        QNode* last = Qlist;
                        while(last->next != NULL){
                            last = last->next;
                        }
                        last->next =newPtr;
                        numQ++;

                        cout << "Question saved.\n";
                        return;
                    }
                    else{
                        newPtr->numChoices++;
                    }

                }
            }
            
        }


    }


}

void tf(pointerNode & Qlist){
    pointerNode newPtr = new QNode;
    int check = 0;
    newPtr->type = "tf";

    cout << "Enter a question\n";
    getline(cin, newPtr->question);
    cout << "Enter an answer make sure it is true of false.\n";
    getline(cin, newPtr->answer);
    while(check = 0){
        if (newPtr->answer == "true" || newPtr->answer == "True" || newPtr->answer == "false" || newPtr->answer == "False"){
            check = 1;
        }
        else{
            cout << "Invalid answer. Please try to put in a valid answer. Make sure it is true of false.\n";
            getline(cin,newPtr->answer);
        }
        
    }
    cout << "Enter point value:\n";
    cin >> newPtr->points;
    cin.ignore();
    newPtr->next=NULL;
    numP = numP+newPtr->points;

    QNode* last = Qlist;
    while(last->next != NULL){
        last = last->next;
    }
    last->next =newPtr;
    numQ++;
    cout << "Question saved.\n";
    return;

}

void wr(pointerNode & Qlist){
    pointerNode newPtr = new QNode;
    newPtr->type = "wr";
    cout << "Enter a question\n";
    getline(cin, newPtr->question);
    cout << "Enter an answer .\n";
    getline(cin, newPtr->answer);
    cout << "Enter point value:\n";
    cin >> newPtr->points;
    cin.ignore();
    newPtr->next=NULL;
    numP = numP+newPtr->points;

    QNode* last = Qlist;
    while(last->next != NULL){
        last = last->next;
    }
    last->next =newPtr;
    numQ++;
    cout << "Question saved.\n";
    return;


}

void editQuestion(pointerNode & Qlist, int numQuestionEdit){
    pointerNode currPtr = Qlist;
    for (int i = 1; i < numQuestionEdit; ++i) {
        currPtr = currPtr->next;
    }
    cout << "===============================" << endl;
    cout << "=== QUESTION " << numQuestionEdit << " SAVED VALUES ===" << endl;
    cout << "===============================" << endl;
    cout << "1. Type: " << currPtr->type << endl;
    cout << "2. Question: " << currPtr->question << endl;
    if (currPtr->type == "mcq") {
            cout << "3. Answer choices:" << endl;
            for (int i = 0; i < currPtr->numChoices; ++i) {
                if(i = 1){
                    cout << currPtr->choiceA << "\n";

                }
                if(i = 2){
                    cout << currPtr->choiceB << "\n";
                    
                }
                if(i = 3){
                    cout << currPtr->choiceC << "\n";
                    
                }
                if(i = 4){
                    cout << currPtr->choiceD << "\n";
                    
                }
                if(i = 5){
                    cout << currPtr->choiceE << "\n";
                    
                }
            }
        }
        cout << "4. Correct answer: " << currPtr->answer << endl;
        cout << "===============================" << endl;

        int choice;
        cout << "Type a number to edit, or type quit(): ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter new type: ";
                cin >> currPtr->type;
                break;
            case 2:
                cout << "Enter new question: ";
                cin.ignore();
                getline(cin, currPtr->question);
                break;
            case 3:
                if (currPtr->type == "mcq") {
                    string choice;
                    currPtr->numChoices = 0;
                    cout << "Enter new choices (type 'done' to finish):" << endl;
                    while (true) {
                        cout << "Enter choice for A:\n";
                        getline(cin, currPtr->choiceA);
                        if(currPtr->choiceA == "done" ||currPtr->choiceA == "Done"){
                            break;
                        }
                        currPtr->numChoices++;
                        cout << "Enter choice for B:\n";
                        getline(cin, currPtr->choiceB);
                        if(currPtr->choiceB == "done" ||currPtr->choiceB == "Done"){
                            break;
                        }
                        currPtr->numChoices++;
                        cout << "Enter choice for C:\n";
                        getline(cin, currPtr->choiceC);
                        if(currPtr->choiceC == "done" ||currPtr->choiceC == "Done"){
                            break;
                        }
                        currPtr->numChoices++;
                        cout << "Enter choice for D:\n";
                        getline(cin, currPtr->choiceD);
                        if(currPtr->choiceD == "done" ||currPtr->choiceD == "Done"){
                            break;
                        }
                        currPtr->numChoices++;
                        cout << "Enter choice for E:\n";
                        getline(cin, currPtr->choiceE);
                        if(currPtr->choiceE == "done" ||currPtr->choiceE == "Done"){
                            break;
                        }
                        currPtr->numChoices++;
                        
                    }
                    } else {
                        cout << "[Invalid choice for this question type]" << endl;
                    }
                    break;
                case 4:
                    cout << "Enter new correct answer: ";
                    cin.ignore();
                    getline(cin, currPtr->answer);
                    break;
                default:
                    cout << "[Invalid choice]" << endl;
                    break;
            }
}

void deleteQuestion(pointerNode & Qlist, int numQuestionDelete){
    pointerNode currPtr = Qlist;
    if (numQuestionDelete == 1) {
            currPtr = currPtr->next;
        } else {
            
            for (int i = 1; i < numQ - 1; ++i) {
                currPtr = currPtr->next;
            }
            currPtr->next = currPtr->next->next;
        }
        numQ--;
}
void startTest(pointerNode & Qlist){
    pointerNode currPtr = Qlist;
        int correctAnswers = 0;
        double score = 0.0;

        while (currPtr) {
            cout << "Question: " << currPtr->question << endl;
            if (currPtr->type == "mcq") {
                for (int i = 0; i < currPtr->numChoices; ++i) {
                    if(i = 1){
                        cout << currPtr->choiceA << "\n";

                    }
                    if(i = 2){
                        cout << currPtr->choiceB << "\n";
                    
                    }
                    if(i = 3){
                        cout << currPtr->choiceC << "\n";
                    
                    }
                    if(i = 4){
                        cout << currPtr->choiceD << "\n";
                    
                    }
                    if(i = 5){
                        cout << currPtr->choiceE << "\n";
                    
                    }
                }
            }
            string answer;
            cout << "Your answer: ";
            cin.ignore();
            getline(cin, answer);

            transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
            transform(currPtr->answer.begin(), currPtr->answer.end(), currPtr->answer.begin(), ::tolower);

            if (answer == currPtr->answer) {
                cout << "[Your answer is correct!]" << endl;
                correctAnswers++;
                score += currPtr->points;
            } else {
                cout << "[Your answer is incorrect. The correct answer is " << currPtr->answer << ".]" << endl;
            }

            currPtr = currPtr->next;
        }

        cout << "/!\\ Assessment Complete." << endl;
        cout << "=== SESSION LOG ===" << endl;
        cout << "Correct answers: " << correctAnswers << "/" << numQ << endl;
        cout << "Final score: " << score << "/" << numP << endl;
        cout << "*** Thank you for using the testing service. Goodbye! ***" << endl;
    }
