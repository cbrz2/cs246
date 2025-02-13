#include "BankAccount.h"

int main()
{
    srand(time(nullptr));
    dsn::Account a, b = a, c(200.0);
    a = c;

    std::cout << dsn::Account::accounts() << "\n";

    {
        dsn::Account d(599.0);
        std::cout << d.accounts() << "\n";
    }
    std::cout << a.accounts() << "\n";

    std::cout << "\n======================================\n";
    std::cout << "a = " << a.accountNumber() << "\n";
    std::cout << "b = " << b.accountNumber() << "\n";
    std::cout << "c = " << c.accountNumber() << "\n";
    
    return 0;
}