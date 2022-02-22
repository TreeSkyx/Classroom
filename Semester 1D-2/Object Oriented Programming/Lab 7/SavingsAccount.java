public class SavingsAccount extends Account{
    /*Constructor with no-arg*/
    public SavingsAccount(){
        super();
    }

    /*Constructor with specified data*/
    public SavingsAccount(int id, double balance){
        super(id, balance);
    }
    public void withdraw(double moneyAmount){
        if(moneyAmount <= getBalance()){
            setBalance(getBalance()-moneyAmount);
        }
        else{
            System.out.print("Error: Transtaction rejected");
        }
    }
}
