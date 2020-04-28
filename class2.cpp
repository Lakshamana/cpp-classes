#include <iostream>

using namespace std;

class BankAccount {
    private:
        int id;
        double totalValue;
    
    public:
        BankAccount(int id) {
            this->id = id;
            this->totalValue = 0;
        }

        int getTotalValue() {
            return this->totalValue;
        }

        void deposit(double val) {
            if (val > 0)
                this->totalValue += val;
        }

        double withdraw(double val) {
            if (val > 0 && this->totalValue >= val) 
                this->totalValue -= val;
            return this->totalValue;
        }
};

// Using by-reference argument passing
void foo(BankAccount *b) {
    b->deposit(100);
}

// Using by-reference argument passing with &
void foo(BankAccount& b) {
    // g++ auto deferences b
    b.deposit(100);
}

int main(int argc, char *argv[]) {
    BankAccount b(0);
    b.deposit(50);
    // foo(&b);
    foo(b); // Uses foo (BankAccount&)
    cout << "After transaction: " << b.getTotalValue() << endl; // 150
    return 0;
}