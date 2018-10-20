#include "SurveyClass.h"

SurveyClass::SurveyClass() {
    members = new LinkedList();
}

SurveyClass::SurveyClass(const SurveyClass &other) {
    members = new LinkedList(*other.members);
}

SurveyClass& SurveyClass::operator=(const SurveyClass &list) {
    if (members) delete members;
    members = new LinkedList(*list.members);
    return *this;
}

SurveyClass::SurveyClass(SurveyClass &&other) {
    members = new LinkedList(move(*other.members));
}

SurveyClass& SurveyClass::operator=(SurveyClass &&list) {
    if (members) delete members;
    members = new LinkedList(move(*list.members));
    return *this;
}

void SurveyClass::handleNewRecord(string _name, float _amount) {
    members->updateNode(_name, _amount);
}

float SurveyClass::calculateMinimumExpense() {
    float min;
    Node* temp=members->head;
    min=temp->amount;
    while(temp){
      if(temp->amount<min){
        min=temp->amount;
      }
      temp=temp->next;
    }
    int to_round=min;
    float to_round2=min-to_round;
    cout <<min<<to_round<<to_round2<<endl;
    to_round2=to_round2*100;
    to_round=int(to_round2);
    min=int(min)+(to_round)/100.0;
    return min;
}

float SurveyClass::calculateMaximumExpense() {
    float max;
    Node* temp=members->head;
    max=temp->amount;
    while(temp){
      if(temp->amount>max){
        max=temp->amount;
      }
      temp=temp->next;
    }
    int to_round=max;
    float to_round2=max-to_round;
    to_round2=to_round2*100;
    to_round=int(to_round2);
    max=int(max)+(to_round)/100.0;
    return max;
}

float SurveyClass::calculateAverageExpense() {
    float avg;
    Node* temp=members->head;
    float sum=0;
    int i=0;
    while(temp){
      sum=sum+temp->amount;
      i++;
      temp=temp->next;
    }
    avg=sum/i;
    int to_round=avg;
    float to_round2=avg-to_round;
    to_round2=to_round2*100;
    to_round=int(to_round2);
    avg=int(avg)+(to_round)/100.0;
    return avg;
}

SurveyClass::~SurveyClass() {
  if (members) delete members;
}
