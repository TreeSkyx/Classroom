import java.util.Date;

public class Account {
    /*  Data fields */
    private int id;
    private double balance;
    private double annualInterestRate;
    private Date dateCreated;

    /* Constructors */
    // default
    Account(){
        id = 0;
        balance = 0;
        annualInterestRate = 0;
        dateCreated = new Date();
    }

    // Specific ID and Balance
    Account(int newId, double newBalance){
        id = newId;
        balance = newBalance;
        dateCreated = new Date();
    }

    /* Mutator methods */
    // Set Id
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
    }

    public void deposit(double moneyAmount){
        balance += moneyAmount;
    }
}
