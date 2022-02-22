public class CheckingAccount extends Account {
    /* Data field */
    private double overdraftLimit;

    /* Contruct with specified data */
    public CheckingAccount(int id, double balance, double overdraftLimit) {
        super(id, balance);
        this.overdraftLimit = overdraftLimit;
    }

    public void setOverdraftLimit(double overdraftLimit) {
        this.overdraftLimit = overdraftLimit;
    }

    public double getOverdraftLimit() {
        return overdraftLimit;
    }

    public void withdraw(double moneyAmount) {
        if (moneyAmount - getBalance() <= overdraftLimit) {
            setBalance(getBalance() - moneyAmount);
        } else {
            System.out.println("Error : Exceeds overdarft limit");
        }
    }

    public String toString() {
		return "Overdraft limit: " + 
		String.format("%.2f", overdraftLimit)
        + super.toString();
	}

}
