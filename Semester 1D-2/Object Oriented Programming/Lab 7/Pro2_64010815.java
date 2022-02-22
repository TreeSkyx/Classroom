public class Pro2_64010815 {
    public static void main(String[] args) {
        NewAccount account = new NewAccount("George",1122,1000);

        account.setAnnualInterestRate(1.5);
        
        account.deposit(30);
        account.deposit(40);
        account.deposit(50);

        account.withdraw(5);
        account.withdraw(4);
        account.withdraw(2);

        System.out.println("Name: " + account.getName());
        System.out.println("Account ID: " + account.getId());
        System.out.println("Annual Interest rate: " + account.getAnnualInterestRate());
        System.out.println("Balance: " + account.getBalance());
        System.out.println("Date\t\t\t\tType\tAmount\tBalance");
        for (int i = 0; i < account.getTransactions().size(); i++) {
			System.out.println((account.getTransactions()).get(i).getDate() +
			"\t" + (account.getTransactions()).get(i).getType() +
            "\t" + (account.getTransactions()).get(i).getAmount() +
			"\t" + (account.getTransactions()).get(i).getBalance());
		}

    }
}
