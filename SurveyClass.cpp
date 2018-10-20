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
    
}

float SurveyClass::calculateMaximumExpense() {

}

float SurveyClass::calculateAverageExpense() {

}

SurveyClass::~SurveyClass() {
  if (members) delete members;
}
