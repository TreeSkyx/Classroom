import java.util.Scanner;

public class Pro6_64010815 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        Account[] accounts = new Account[10];

        initialBalance(accounts);

        do{
            System.out.print("Enter ID: ");
            int id = in.nextInt();

            if(CheckID(id, accounts)){
                int choice;
                do{
                    choice = mainMenu(in);
                    if(isTransaction(choice)){
                        executeTransaction(choice, accounts, id, in);
                    }
                }while (choice != 4);
            }
        }while(true);
    }

    public static void initialBalance(Account[] ac) {
        int initialBalance = 100;
        for(int i=0; i < ac.length; i++){
            ac[i] = new Account(i, initialBalance);
        }
    }

	public static boolean CheckID(int id, Account[] a) {
		for (int i = 0; i < a.length; i++) {
			if (id == a[i].getId())
				return true;
		}
		return false;
	}

    public static boolean isTransaction(int choice){
        return choice > 0 && choice < 4;
    }

    public static int mainMenu(Scanner in){
        System.out.println("Main Menu");
        System.out.println("1: check balance");
        System.out.println("2: withdraw");
        System.out.println("3: deposit");
        System.out.println("4: exit");
        System.out.print("Enter a choice: ");
        return in.nextInt();
    }

    public static void executeTransaction(
		int c, Account[] a, int id, Scanner input) {
		switch (c) {
			case 1: // Viewing the current balance
					System.out.println("The balance is " + a[id].getBalance());
					break;
			case 2: // Withdraw money
					System.out.print("Enter an amount to withdraw: ");
                    double money =  input.nextDouble();
                    if(money <= a[id].getBalance()){ 
					    a[id].withdraw(money);
                    }
                    else System.out.println("ํYour balance in this account less than your input");

					break;
			case 3: // Deposit money
					  System.out.print("Enter an amount to deposit: "); 
					  a[id].deposit(input.nextDouble());
                    break;

            default : System.out.println("Wrong Input");
		}
	}
}
