public class Pro1_64010815 {
    public static void main(String[] args) {
        Account account = new Account(1234, 5000);
        account.withdraw(10000);
        System.out.print("Account");
        System.out.println(account.toString());

        CheckingAccount ovd = new CheckingAccount(1423, 5000,5000);
        System.out.println("\nChecking Account");
        ovd.withdraw(10000);
        System.out.println(ovd.toString());


        SavingsAccount sav = new SavingsAccount(1342, 5000);
        System.out.println("\nSaving Account");
        sav.withdraw(10000);
        System.out.println(sav.toString());
    }
}
