import java.util.ArrayList;
import java.util.Date;

public class NewAccount {
    /*  Data fields */
    private String name;
    private int id;
    private double balance;
    private double annualInterestRate;
    private Date dateCreated;
    private ArrayList<Transaction> transactions;

    /* Constructors */
    // default
    NewAccount(){
        name = "";
        id = 0;
        balance = 0;
        annualInterestRate = 0;
        dateCreated = new Date();
        transactions = new ArrayList<Transaction>();
    }

    // Specific ID and Balance
    NewAccount(int newId, double newBalance){
        name = "";
        id = newId;
        balance = newBalance;
        dateCreated = new Date();
        transactions = new ArrayList<Transaction>();
    }

    // Specific Name, ID and Balance
    NewAccount(String newName, int newId, double newBalance){
        name = newName;
        id = newId;
        balance = newBalance;
        dateCreated = new Date();
        transactions = new ArrayList<Transaction>();
    }


    /* Mutator methods */
    // Set Id
    public void setName(String newName){
        name = newName;
    }
    public void setId(int newId){
        id = newId;
    }

    // Set Balance
    public void setBalance(double newBalance){
        balance = newBalance;
    }
    
    // Set annualInterestRate
    public void setAnnualInterestRate(double newAnnualInterestRate){
        annualInterestRate = newAnnualInterestRate;
    }

    /* Accessor */
    // Return Id
    public String getName(){
        return name;
    }
    public int getId(){
        return id;
    }

    // Return Balance
    public double getBalance(){
        return balance;
    }

    // Return annualInterestRate
    public double getAnnualInterestRate(){
        return annualInterestRate;
    }

    // Return dataCreated
    public String getDateCreated(){
        return dateCreated.toString();
    }

    // Return monthly interest rate
    public double getMonthlyInterestRate(){
        return annualInterestRate/12;
    }

    /* Medthod */
    // Return monthly interest
    public double getMonthlyInterest(){
        return balance * (getAnnualInterestRate() / 100 );
    }
    
    public void withdraw(double moneyAmount){
        balance -= moneyAmount;
        transactions.add(new Transaction('W', moneyAmount, balance, "Withdraw from account"));
    }

    public void deposit(double moneyAmount){
        balance += moneyAmount;
        transactions.add(new Transaction('D', moneyAmount, balance, "Deposit from account"));
    }

    public ArrayList<Transaction> getTransactions() {
		return transactions;
    }
}
