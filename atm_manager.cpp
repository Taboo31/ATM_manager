#include <iostream>
#include <string>

class ATMmanager{

    public:
        int user_balance;
        std::string username;

        ATMmanager(int balance, std::string user){
            user_balance = balance;
            username = user;
        }

        void update_balance(int& balance_to_add){
            user_balance += balance_to_add;
        }
        
        bool withdraw(int& amount_to_withdraw){
            if (amount_to_withdraw > user_balance) {
                return false;

            }
            else{
                user_balance -= amount_to_withdraw;
                return true;
            }
        }
        int get_balance(){
            return user_balance;
        }
};

bool manager(int& user_request , ATMmanager& user_account){

    switch(user_request){

        case 1: {
            int user_balance = user_account.get_balance();
            std::cout << user_balance;
            break;
        }

        case 2: {

            int balance_to_add;
            std::cout << "\nBalance to add : ";
            std::cin >> balance_to_add;

            user_account.update_balance(balance_to_add);
            break;
        }

        case 3: {

            int amount_to_withdraw;
            std::cout << "\nAmount to withdraw : ";
            std::cin >> amount_to_withdraw;

            bool successful = user_account.withdraw(amount_to_withdraw);

            if (successful){
                std::cout << "\nSuccessful withdraw";
            }
            else{
                std::cout << "\nUnsuccessful, amount too large";
            }
            break;
        }

        case 4: {
            return false; 
        }
        
        default: {
            std::cout << "\nincorrect input";
            break;
        }
    }
    return true;
}

int main(){

    bool run = true;
    ATMmanager user_account(1000, "Lewis");

    while (run){
        
        int user_input;
        printf("\n1. get balance\n");
        printf("2. add to balance\n");
        printf("3. withdraw from balance\n");
        printf("4. exit\n");

        std::cin >> user_input;

        run = manager(user_input, user_account);
    }
    return 0;
}



