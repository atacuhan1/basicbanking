# Basic Banking

Menu-driven console banking system written in C for a METU NCC course. Accounts live in memory for the current run: the program assigns numbers starting at `1001` and keeps up to 100 accounts.

## What you can do

1. Create an account with a name and an opening deposit
2. Deposit money
3. Withdraw money, if the balance is enough
4. Check a balance
5. Quit

## Build and run

```bash
gcc basicBanking.c -o basicbanking
./basicbanking
```
