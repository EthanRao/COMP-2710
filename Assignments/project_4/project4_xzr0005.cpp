/*
 * File name: project4_xzr0005.cpp
 * Name: Xi Rao
 * Auburn UserID: xzr0005
 */ 

#include <iostream>
#include <cstdlib>
#include <string>
#include <assert.h>


using namespace std;

struct triva_node {
   string question;
   string answer;
   int point;
   triva_node *next;
};

//create a pointer to triva_node
//typedef triva_node *ptr_node;

class trivaList {
   public:
   int count;
   triva_node *first, *current;
   trivaList() {
      count = 0;
      first = NULL;
      current = NULL;
   }
};

void init_question_list(trivaList &q_list) {
   triva_node *q1 = new triva_node;
   triva_node *q2 = new triva_node;
   triva_node *q3 = new triva_node;

   //Trivia 1
   q1 -> question = "How long was the shortest war on record? (Hint: how many minutes)";
   q1 -> answer = "38";
   q1 -> point = 100;
   q1 -> next = q2;

   //Trivia 2
   q2 -> question = "What was Bank of America’s original name? (Hint: Bank of Italy or Bank of Germany)";
   q2 -> answer = "Bank of Italy";
   q2 -> point = 50;
   q2 -> next = q3;

   //Trivia3
   q3 -> question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)?";
   q3 -> answer = "Wii Sports";
   q3 -> point = 20;
   q3 -> next = NULL;

   q_list.first = q1;
   q_list.current = q3;
   q_list.count += 3;
}

void add_question(trivaList &q_list) {
   string result;
   triva_node *new_ptr = new triva_node;
   triva_node *end_ptr = q_list.first;
   while (end_ptr -> next != NULL) {
      end_ptr = end_ptr -> next;
   }
   if (new_ptr == NULL) {
      exit(1);
   }
   cout << "Enter a question: ";
   getline(cin, new_ptr -> question);

   cout << "Enter an answer: ";
   getline(cin, new_ptr -> answer);

   cout << "Enter award points: ";
   cin >> new_ptr -> point;
   cin.get();
   if (end_ptr == NULL) {
      q_list.first = new_ptr;
   }
   else {
      end_ptr -> next = new_ptr;
   }
   q_list.count++;
}


int ask_question(trivaList q_list, int num_ask) {
   triva_node *currentNode = q_list.first;
   string user_answer;
   int p = 0;
   if (num_ask < 1) {
      cout << "Warning - the number of trivia to be asked must equal to or be larger than 1.";
      return 0;
   }
   if (currentNode == NULL) {
      return 0;
   }
   else if (q_list.count < num_ask) {
      cout << "\nWarning - There is only " << q_list.count << " trivia in the list.";
      num_ask = q_list.count;
   }
   else {
      for (int i = 0; i < num_ask; i++) {
         cout << "Question: " << currentNode -> question << "\nAnwser: ";
         getline(cin, user_answer);
         if (user_answer.compare(currentNode -> answer) == 0) {
            cout << "Your answer is correct! You receive " << currentNode -> point << " points.";
            p += currentNode -> point;
         }
         else {
            cout << "Your answer is wrong. The correct answer is " << currentNode -> answer;
         
         }
         cout << "\nYour total points: " << p << "\n\n";
         currentNode = currentNode -> next;
      }
   }
   return 0;
}

//Test cases and using test driver
//create two version
//#define UNIT_TESTING
void Unit_Test() {
   trivaList node;
   init_question_list(node);
   cout << "***This is a debugging version ***\n";

   //case 1
   cout << "Unit Test Case 1: Ask no question. The program should give a warning message.\n";
   assert(0 == ask_question(node, 0));
   cout << "\nCase 1 Passed\n\n";

   //case 2.1
   cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer.\n";
   assert(0 == ask_question(node, 1));
   cout << "Case 2.1 passed\n\n";

   //case 2.2
   cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer.\n";
   assert(0 == ask_question(node, 1));
   cout << "Case 2.2 passed\n\n";

   //case 3
   cout << "Unit Test Case 3: Ask all the questions of the last trivia in the linked list.\n";
   assert(0 == ask_question(node, 3));
   cout << "Case 3 passed\n\n";

   //case 4
   cout << "Unit Test Case 4: Ask 5 questions in the linked list.";
   assert(0 == ask_question(node, 5));
   cout << "\nCase 4 passed\n\n";

   cout << "*** End of the Debugging Version ***\n";
}

#define triva_quiz

int main() {
   Unit_Test();

#ifdef triva_quiz
   trivaList quiz;
   init_question_list(quiz);
   cout << "\n";
   cout << "*** Welcome to Xi Rao’s trivia quiz game ***\n";

   string result;
   bool addQ = true;
   do {
      add_question(quiz);
      cout << "Continue? (Yes/No): ";
      cin >> result;
      cin.ignore();
      if (result == "No" || result == "no") {
         addQ = false;
      }
   }
   while (addQ);
   cout << "\n";
   ask_question(quiz, quiz.count);

   cout << "*** Thank you for playing the trivia quiz game. Goodbye! ***\n";
   return 0;
}
#endif

#ifdef UNIT_TESTING
Unit_Test();
return 0;
}
#endif

