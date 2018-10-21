#include "SurveyClass.h"

SurveyClass::SurveyClass() {
    members = new LinkedList();
}

SurveyClass::SurveyClass(const SurveyClass &other) {
    members = new LinkedList(*other.members);
}

SurveyClass& SurveyClass::operator=(const SurveyClass &list) {
    *members = *list.members;
    return *this;
}

SurveyClass::SurveyClass(SurveyClass &&other) {
    members = new LinkedList(move(*other.members));
}

SurveyClass& SurveyClass::operator=(SurveyClass &&list) {
    *members = move(*list.members);
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
    int rounder = 1000*min;
    rounder/=10;
    min=rounder/100.0;
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
    int rounder = 1000*max;
    rounder/=10;
    max=rounder/100.0;
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
    int rounder = 1000*sum/i;
    rounder/=10;
    avg=rounder/100.0;
    return avg;
}

SurveyClass::~SurveyClass() {
  if (members) delete members;
}
