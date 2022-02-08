public class Pro1_64010815 {
    public static void main(String[] args) {
        // Create account with specified id and balance
        Account account = new Account(1122, 20000);

        // Set annual interest rate (4.5%)
        account.setAnnualInterestRate(4.5);

        // Withdraw -> 2500
        account.withdraw(2500);

        // Deposit -> 3000
        account.deposit(3000);

        /* Display */
        System.out.println("Balance: " + account.getBalance());
        System.out.println("Monthly interest: " + account.getMonthlyInterest());
        System.out.println("Date Created: " + account.getDateCreated());
    }
}
