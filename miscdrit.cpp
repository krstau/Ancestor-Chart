#include <iostream>

template<typename T>
class BinaryTree {




};
template<typename T>
class Node {


private:
    T data;
    Node *left;
    Node *right;
    this->data = data;

};

BinaryTree::~BinaryTree(){

}


class Tree {
    Node root;

public:
    Tree(Node _root) : root(_root) {};
};




int main() {
    Person person("", "", "");
    std::cout << "";
    Tree tree();
    return 0;
}





#endif //ANCESTOR_CHART_BINARYTREE_H
//WIP BELOW

//std::cout << "Create your root person: " << "/n";
//Person rootPerson = createPerson();
//Node rootNode = Node(rootPerson);
//BinaryTree tree = BinaryTree(rootNode);

/*  Questions:
    1. Gender as enum
    2. Search algorithm depth first
    3. BinaryTree add nodes
    4. (format info for printing)
    5. Templates (answered)
    6. Feedback hide Node
    7. (Unit tests)
 */



// TODO: 1. Unit tests


/*
std::vector<Person> people; // People-vector storing persons



Person findPersonByName(const std::string &firstName, const std::string &lastName,
                        const std::vector<Person> &people) { // Function to find a person by name in people-vector
    //TODO: Return optional
    auto personIterator = find_if(begin(people), end(people), [&](const auto &person) {
        return person.getFirstName() == firstName && person.getLastName() == lastName;
    });
    return *personIterator;
}

void erasePerson(const std::string &firstName, const std::string &lastName,
                 std::vector<Person> &people) { // Function to erase a person from people-vector
    auto personIterator = find_if(begin(people), end(people), [&](const auto &person) {
        return person.getFirstName() == firstName && person.getLastName() == lastName;
    });
    if (personIterator != people.end()) {
        people.erase(personIterator);
    }
}

void printPeople() { // Function to print all persons in people-vector
    for (const auto &person: people)
        std::cout << person.getFirstName() << " " << person.getLastName() << "\n";
}



void addPerson() { // Function to add persons to the people-vector
    Person person = createPerson();
    people.emplace_back(person);
    std::cout << person.getFirstName() << " " << person.getLastName() << " aged " << person.getAge()
              << " has been added!" << "\n";
}

void deletePerson() { // Function to delete a person in people-vector
    std::string firstName;
    std::string lastName;
    std::cout << "Enter the firstname of the person that you want to delete:";
    std::cin >> firstName;
    std::cout << "Enter the lastname of the person that you want to delete: ";
    std::cin >> lastName;
    erasePerson(firstName, lastName, people);
}

void displayMenu() { // Function to display menu
    bool quit = false;
    while (!quit) {
        std::cout << R"(:cout << "Enter in the firstname of the person that you want to display: ";
    std
    _                        _              ____ _                _
   / \   _ __   ___ ___  ___| |_ ___  _ __ / ___| |__   __ _ _ __| |_
  / _ \ | '_ \ / __/ _ \/ __| __/ _ \| '__| |   | '_ \ / _` | '__| __|
 / ___ \| | | | (_|  __/\__ \ || (_) | |  | |___| | | | (_| | |  | |_
/_/   \_\_| |_|\___\___||___/\__\___/|_|   \____|_| |_|\__,_|_|   \__|
)" << "\n";
        std::cout << "Main menu:" << "\n";
        std::cout << "1: Print persons" << "\n";
        std::cout << "2: Print individual" << "\n";
        std::cout << "3: Add person" << "\n";
        std::cout << "4: Edit person" << "\n";
        std::cout << "5: Delete person" << "\n";
        std::cout << "0: Exit" << "\n" << "\n";
        std::cout << "Enter choice:";
        int choice;
        while (!(std::cin >> choice)) {
            std::cout << "Invalid input, please input a number" << "\n";
            std::cin.clear();
            std::cin.ignore(132, '\n');
        }

        switch (choice) {
            case 1: {
                printPeople();
                break;
            }
            case 2: {
                printPerson();
                break;
            }
            case 3: {
                addPerson();
                break;
            }
            case 4: {
                // TODO editPerson(); Work in progress
                break;
            }
            case 5: {
                deletePerson();
                break;
            }
            case 0:
                quit = true;
                break;
            default:
                std::cout << "Please enter a number between 0 and 5: " << "\n";
                break;
        }
    }
}

/*
void printPersonName(const Person& person) {
    cout << "Firstname: " << person.getFirstName() << '\n';
    cout << "Lastname: " << person.getLastName() << '\n';
}

vector<Person> findPersonsByName(const vector<Person> &people, const string &firstName = "", const string &lastName = "") {
    vector<Person> foundPersons;
    for (const auto &person: people) {
        if (person.getFirstName() == firstName && person.getLastName() == lastName) {
            foundPersons.emplace_back(person);
        }
    }
    return foundPersons;
}
*/

/*
    if (personIt == end(people))
        cout << "We couldn't find the name you wrote. Try again" << endl;
    else
    {
        cout << "Info about this person: ";
        printPerson(*personIt);
    }
*/



/*
Person modifyPerson(Person& person){
    firstName = person.getFirstName();
    lastName = person.getLastName();
    age = person.getAge();
    gender = person.getGender();
    cout << "Enter firstname of person: ";
    cin >> firstName;
    person.setFirstName(firstName);
    cout << "Enter lastname of person: ";
    cin >> lastName;
    person.setLastName(lastName);
    cout << "Enter age of person: ";
    cin >> age;
    person.setAge(age);
    cout << "Enter gender of person: ";
    cin >> gender;
    person.setGender(gender);
    return person;
}*/

/*
void editPerson(){
    string firstName;
    string lastName;
    cout << "Enter the firstname of the person that you want to edit: ";
    cin >> firstName;
    cout << "Enter the lastname of the person that you want to edit: ";
    cin >> lastName;
    Person person = findPersonByName(firstName, lastName, people);
    modifyPerson(person);


Person createRootPerson(){
    cout << "Who's ancestors will you chart?" << "\n";                                                                  //duplicate text
    Person rootPerson = createPerson();
    Node root(rootPerson);
    people.emplace_back(rootPerson);
    return rootPerson;
}

 void connectLeftNode(Node *parent, Node *Node){
   parent->getLeftPtr() = Node;
void connectRightNode(Node *parent, Node *Node){
   parent = Node->setRightPtr(Nde *parent);
}