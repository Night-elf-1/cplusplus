#include <iostream>
#include <cassert>

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {
        assert(initialBalance >= 0); // 确保初始余额非负
    }

    void deposit(double amount) {
        assert(amount >= 0); // 确保存款金额非负
        balance += amount;
    }

    void withdraw(double amount) {
        assert(amount >= 0); // 确保取款金额非负
        assert(balance >= amount); // 确保账户余额充足
        balance -= amount;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount account(1000); // 创建一个初始余额为1000的账户

    std::cout << "Initial balance: " << account.getBalance() << std::endl;

    account.deposit(500); // 存入500
    std::cout << "Balance after deposit: " << account.getBalance() << std::endl;

    account.withdraw(200); // 取出200
    std::cout << "Balance after withdrawal: " << account.getBalance() << std::endl;

    // 下面的取款操作将触发assert，因为余额不足
    account.withdraw(1500);

    // 下面的存款操作也将触发assert，因为存款金额为负
    account.deposit(-300);

    return 0;
}