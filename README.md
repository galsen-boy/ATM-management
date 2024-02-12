#   💸 ATM MANAGEMENT SYSTEM
##  Description
The objective of this project is to show that you have acquired programming logic and that you are able to adapt to new languages.

The programming language you are about to use is C. You will not be asked to create a project from scratch, instead you will have to add features or fix the code of a given application.

##  Steps
+   [x] Login
+   [x] Register
+   [x] Create a new account
+   [x] Check the details of existing accounts
+   [x] Remove existing accounts
+   [x] Update information of existing accounts
+   [x] Check list of owned accounts
+   [x] Make transactions
+   [x] Transfer Ownership
   +   [ ] Notify user
   +   [ ] Use SQLite

### Features
The following features must be implemented by yourself.

1. The **Registration** feature, you must be able to register new users, users with the same name can not exist (names must be unique). They must be saved in the right file.

2. The **Update information of existing account** feature, users must be able to update their country or phone number.

   2.1. You must ask users to input the account `id` they want to change, followed by a prompt asking which field they want to also change (the only fields that are permitted to update is the phone number and the country).

   2.2. Whenever users update an account, it must be saved into the corresponding file.

3. The **Checking the details of existing accounts** feature, users must be able to check just one account at a time.

   3.1. For this they must be asked to input the account id they want to see

   3.2. If the account is either `savings`, `fixed01`, `fixed02` and `fixed03` the system will display
   the information of that account and the interest you will acquire depending on the account:

   - savings: interest rate 0.07%
   - fixed01(1 year account): interest rate 0.04%
   - fixed02(2 year account): interest rate 0.05%
   - fixed03(3 year account): interest rate 0.08%
   - If the account is current you must display `You will not get interests because the account is of type current`

4. The **Make transaction** feature, users must be able to create transactions, withdrawing or depositing money to a certain account. All transactions
   must be updated and saved into the corresponding file.

5. The **Remove existing account** feature, users must be able to delete their own account, the same must happen here, updates must be saved into the corresponding file.

6. The **Transfer owner** feature, users can transfer their account to another user, by:

   6.1. Identifying the account and the user they want to transfer the ownership to

   6.2. Saving the information in the corresponding file

##  Source
[File Permission](https://stackoverflow.com/questions/1466000/difference-between-modes-a-a-w-w-and-r-in-built-in-open-function)