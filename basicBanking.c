
#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[30];
    int accountNumber;
    int balance;
}Account;

void displayMenu();
void getUserInput(int operation,void *input);
void createAccount(Account accounts[], int *numAccounts, int *nowAccountNumber);
void depositMoney(Account accounts[], int numAccounts);
void withdrawMoney(Account accounts[], int numAccounts);
void checkBalance(Account accounts[], int numAccounts);
int findAccount(Account accounts[], int numAccounts, int accountNumber);

int main(){
    Account accounts[100]; // Array of accounts.
    int numAccounts = 0; // Initial Account Index
    int nowAccountNumber = 1001; // First account number.
    int choice = 0;

    printf("Welcome to the Simple Banking System Designed by METU-NCC Student!\n\n");

    do{
        displayMenu();
        getUserInput(1,&choice);

        switch (choice) {
            case 1: // Create Account
                createAccount(accounts, &numAccounts, &nowAccountNumber);
                break;
            case 2: // Deposit Money
                depositMoney(accounts,numAccounts);
                break;
            case 3: // Withdraw Money
                withdrawMoney(accounts,numAccounts);
                break;
            case 4: // Check Balance
                checkBalance(accounts,numAccounts);
                break;
            case 5: // Quit
                printf("\nThank you for using our Simple Banking System\n");
                printf("Goodbye!");
                break;
            default: // Error for invalid input
                printf("Invalid input!\n");
                break;

        }
    }while(choice != 5);

    return 0;
}

void getUserInput(int operation, void *input){
    switch (operation) {
        case 1: // 1 For Integer Input
            scanf("%d",(int *)input);
            break;
        case 2: // 2 For Char Input
            scanf("%s",(char *)input);
            break;
    }
}

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Create New Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Check Balance\n");
    printf("5. Quit\n");
    printf("Enter your choice:");
}

void createAccount(Account accounts[], int *numAccounts, int *nowAccountNumber) {
    char name[50];
    int firstDeposit;

    printf("\nEnter your name:");
    getUserInput(2,name);

    printf("Enter initial deposit:");
    getUserInput(1,&firstDeposit);

    strcpy(accounts[*numAccounts].name,name); // Applies name for the account
    accounts[*numAccounts].accountNumber = *nowAccountNumber; // Sets the number of account first 1001
    accounts[*numAccounts].balance = firstDeposit; // Sets the initial deposit for the new account.

    printf("Account created successfully!\n");
    printf("Account Holder Name is %s\n",name);
    printf("Account number is %d\n",*nowAccountNumber);

    (*nowAccountNumber)++;  // Creates a new account number.
    (*numAccounts)++; // Moves to next array of structure

}

void depositMoney(Account accounts[], int numAccounts){
    int accountNumber;
    int deposit;

    printf("\nEnter account number:");
    getUserInput(1,&accountNumber);

    printf("Enter deposit amount:");
    getUserInput(1,&deposit);

    int accountIndex = findAccount(accounts,numAccounts,accountNumber);
    if(accountIndex != -1) {
        accounts[accountIndex].balance += deposit;
        printf("Deposit successful! New balance: %d\n",accounts[accountIndex].balance);
    }else
        printf("Account not found!\n");

}

void withdrawMoney(Account accounts[], int numAccounts){
    int accountNumber;
    int withdraw;

    printf("\nEnter account number:");
    getUserInput(1,&accountNumber);

    printf("Enter withdrawal amount:");
    getUserInput(1,&withdraw);

    int accountIndex = findAccount(accounts,numAccounts,accountNumber);
    if(accountIndex != -1) {
        if(accounts[accountIndex].balance < withdraw){ // Check if there is enough balance in the account for withdrawal process.
            printf("Not enough balance in your account!\n");
        } else {
            accounts[accountIndex].balance -= withdraw;
            printf("Withdrawal successful! New balance:%d\n", accounts[accountIndex].balance);
        }
    } else
        printf("Account not found!\n");

}

void checkBalance(Account accounts[], int numAccounts){
    int accountNumber;

    printf("\nEnter your account number:");
    getUserInput(1,&accountNumber);

    int accountIndex = findAccount(accounts,numAccounts,accountNumber);
    if(accountIndex != -1){
        printf("Current balance: %d",accounts[accountIndex].balance);
    }
    else
        printf("Wrong account number!");
}

int findAccount(Account accounts[], int numAccounts, int accountNumber) {
    for (int i = 0; i < numAccounts; i++)
        if (accounts[i].accountNumber == accountNumber) { // Finds if a account related to account number exist.
    return i;
}
    return -1;
}













