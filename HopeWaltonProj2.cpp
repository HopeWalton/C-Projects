//Author: Hope Walton
//Version: 06/13/2024


#include <iostream>
using namespace std;

class CDAccount
{
public:
    CDAccount();
    //Initilizes the dollar, cent, interest_rate, balance, and term to 0
    
    CDAccount(double new_balance, double new_interest_rate, int new_term);
    //Initilizes the dollar and cent variables from the balance inputed by the user
    //Initilizes the interest rate, inputed as a percentage
    //Initilizes the term variable
    
    double get_initial_balance() const;
    //Returns the initial balance before maturity
    
    double get_balance_at_maturity() const;
    //Returns the balance after account maturity has been reached, including interest
    
    double get_interest_rate() const;
    //Returns the interest rate as a fraction
    
    int get_term() const;
    //Returns the current term amount in months
    
    void input(istream& in);
    //Precondition: The istream reference in must be a valid, open input stream.
    //Postcondition: The istream in may be modified, depending on the input operation performed within the function.
    //The state of the CDAccount object calling the function may be modified to reflect the inputted values for balance, interest rate, and term.
    //Any state changes to the stream in caused by the function are reflected after the function execution.
    
    void output(ostream& out);
    //Precondition: The ostream reference out must be a valid, open output stream.
    //Postcondition: The ostream out may be modified, depending on the output operation performed within the function.
    //The state of the CDAccount object calling the function remains unchanged.
    //Any state changes to the stream out caused by the function are reflected after the function execution.

private:
    int dollar;
    int cent;
    double interest_rate;
    int term; // Months until maturity
    
};

int main()
{
    CDAccount account1(13.25, 5.0, 2);
    cout << "Parameterized constructor:" << endl;
    account1.output(cout);

    CDAccount account2;
    cout << "Default constructor:" << endl;
    account2.output(cout);

    CDAccount account3;
    account3.input(cin);

    int choice;
    do {
        cout << "\nMain Menu:\n";
        cout << "1. View intial balance.\n";
        cout << "2. View interest rate.\n";
        cout << "3. View term period.\n";
        cout << "4. View balace at maturity.\n";
        cout << "5. Exit\n";
        cout << "Choose an option: " << endl;
        cin >> choice;
        cout << endl;

        switch (choice){
            case 1:
                cout << account3.get_initial_balance() << endl;
                break;
            case 2:
                cout << account3.get_interest_rate() * 100 << "%" << endl;
                break;
            case 3:
                cout << account3.get_term() << endl;;
                break;
            case 4:
                cout << account3.get_balance_at_maturity() << endl;;
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
        default:
            cout << "Invalid option, please try again." << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}

CDAccount::CDAccount() : dollar(0), cent(0), interest_rate(0.0), term(0) 
{
}

CDAccount::CDAccount(double new_balance, double new_interest_rate, int new_term) :
   dollar(int(new_balance)), cent((int)((new_balance - dollar) * 100)), interest_rate(new_interest_rate), term(new_term)
{
}

double CDAccount::get_initial_balance() const {
    return dollar + 0.01*cent;
}

double CDAccount::get_balance_at_maturity() const {
    double interest = (dollar + 0.01 * cent) * get_interest_rate() * (term / 12.0);
    return (dollar + 0.01 * cent) + interest;
}

double CDAccount::get_interest_rate() const {
    double fraction = interest_rate / 100;
    return fraction;
}

int CDAccount::get_term() const {
    return term;
}

void CDAccount::input(istream& in)
{
    double balance;
    cout << "Please enter a balance:" << endl;

    while (!(in >> balance) || balance < 0) {
        cout << "Invalid input. Please enter a positive balance:" << endl;
        in.clear();
        in.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    dollar = (int)balance;
    cent = (int)((balance - dollar) * 100);

    cout << "Enter interest rate:" << endl;

    while (!(in >> interest_rate) || interest_rate < 0) {
        cout << "Invalid input. Please enter a positive interest rate:" << endl;
        in.clear();
        in.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter term period in months:" << endl;

    while (!(in >> term) || term < 0) {
        cout << "Invalid input. Please enter a positive term period in months:" << endl;
        in.clear();
        in.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void CDAccount::output(ostream& out) {
    out.setf(ios::fixed);
    out.setf(ios::showpoint);
    out.precision(2);

    out << "CD Account interest rate: " << get_interest_rate() * 100 << "%" << endl;
    out << "CD Account initial balance: " << get_initial_balance() << endl;
    out << "When your CD Account matures in " << get_term() << " months, " << endl;
    out << "it will have a balance of: " << get_balance_at_maturity() << " dollars." << endl;
    out << endl;
}