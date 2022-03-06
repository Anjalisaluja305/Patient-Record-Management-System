#include <bits/stdc++.h>
using namespace std;
  
// Node Class
class Node {
public:
    int patient_id;
    string First_Name;
    string Last_Name;
    string ward;
    string contact_no;
    Node* next;
};
  
// Stores the head of the Linked List
Node* head = new Node();
  
// Check Function to check that if
// Record Already Exist or Not
bool check(int x)
{
    // Base Case
    if (head == NULL)
        return false;
  
    Node* t = new Node;
    t = head;
  
    // Traverse the Linked List
    while (t != NULL) {
        if (t->patient_id == x)
            return true;
        t = t->next;
    }
  
    return false;
}
  
// Function to insert the record
void Insert_Record(int patient_id, string First_Name,string Last_Name,
                   string ward, string contact_no)
{
    // if Record Already Exist
    if (check(patient_id)) {
        cout << "Patient with this "
             << "Id Already Exists\n";
        return;
    }
  
    // Create new Node to Insert Record
    Node* t = new Node();
    t->patient_id = patient_id;
    t->First_Name = First_Name;
    t->Last_Name =Last_Name;
    t->ward = ward;
    t->contact_no = contact_no;
    t->next = NULL;
  
    // Insert at Begin
    if (head == NULL
        || (head->patient_id >= t->patient_id)) {
        t->next = head;
        head = t;
    }
  
    // Insert at middle or End
    else {
        Node* c = head;
        //while cond is for inserting node in end
        while (c->next != NULL
               && c->next->patient_id < t->patient_id) {
            c = c->next;
        }
        t->next = c->next;
        c->next = t;
    }
  
    cout << "Record Inserted "
         << "Successfully\n";
}
  
// Function to search record for any patient with patient id
void Search_Record(int patient_id)
{
    // if head is NULL
    if (!head) {
        cout << "No such Record "
             << "Avialable\n";
        return;
    }
  
    else {
        Node* p = head;
        while (p) {
            if (p->patient_id == patient_id) {
                cout << "Patient_ID\t"
                     << p->patient_id << endl;
                cout << "First_Name\t"
                     << p->First_Name << endl;
                cout << "Last_Name\t"
                     << p->Last_Name << endl;     
                cout << "Ward     \t"
                     << p->ward << endl;
                cout << "Contact_no\t"
                     << p->contact_no << endl;
                return;
            }
            p = p->next;
        }
  
        if (p == NULL)
            cout << "No such Record "
                 << "Avialable\n";
    }
}
  
// Function to delete patient record with given id
// if exist
int Delete_Record(int patient_id)
{
    Node* t = head;
    Node* p = NULL;
  
    // Deletion at Begin
    if (t != NULL
        && t->patient_id == patient_id) {
        head = t->next;
        delete t;
  
        cout << "Record Deleted "
             << "Successfully\n";
        return 0;
    }
  
    // Deletion Other than Begin
    while (t != NULL && t->patient_id != patient_id) {
        p = t;
        t = t->next;
    }
    if (t == NULL) {
        cout << "Record does not Exist\n";//if patient id doesn't exist in record
        return -1;
    }
    else
    {
        p->next = t->next;
        delete t;
        cout << "Record Deleted "
             << "Successfully\n";
  
        return 0;
    }
}
  
// Function to display the patient's Record
void Show_Record()
{
    Node* p = head;
    if (p == NULL) {
        cout << "No Record "
             << "Available\n";
    }
    else {
        cout << "ID\tFirst_Name\tLast_Name\tWard"
             << "\tContact no\n";
  
        // Until p is not NULL
        while (p != NULL) {
            cout << p->patient_id << "      \t"
                 << p->First_Name << "    \t"
                 <<p->Last_Name<<"   \t"
                 << p->ward << "  \t"
                 << p->contact_no << endl;
            p = p->next;
        }
    }
}
  
// Driver code
int main()
{
    head = NULL;
    string First_Name, Last_Name,ward;
    int patient_id;
	string contact_no;
  
    // Menu program
    while (true) {
        cout << "\n\t\tWelcome to Patient Record "
                "Management System\n\n\tPress\n\t1 To "
                "create a new Patient Record\n\t2 To delete a "
                "Patient record\n\t3 To Search a Patient "
                "Record\n\t4 To view all Patients "
                "record\n\t5 to Exit\n";
        int Choice;
        cout << "\nEnter your Choice:";
        // Enter Choice
        cin >> Choice;
        if (Choice == 1) {
            cout << "Enter First Name of Patient\n";
            cin >> First_Name;
            cout << "Enter Last Name of Patient\n";
            cin >> Last_Name;
            cout << "Enter Patient_Id\n";
            cin >> patient_id;
            cout << "Enter Contact no. of Patient\n";
            cin >> contact_no;
            cout << "Enter Ward that has been alloted to Patient\n";
            cin >> ward;
            Insert_Record(patient_id, First_Name, Last_Name,ward, contact_no);
        }
        else if (Choice == 2) {
            cout << "Enter Patient ID whose "
                    "record is to be deleted\n";
            cin >> patient_id;
            Delete_Record(patient_id);
        }
        else if (Choice == 3) {
            cout << "Enter Patient Id whose "
                    "record you want to Search\n";
            cin >> patient_id;
            Search_Record(patient_id);
        }
        else if (Choice == 4) {
            Show_Record();
        }
        else if (Choice == 5) {
            exit(0);
        }
        else {
            cout << "Invalid Choice "
                 << "Try Again\n";
        }
    }
    return 0;
}
