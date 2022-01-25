public class Pro1_64010815 {
    public static void main(String[] args) {
    int n=0,num=1;
    while(n<100){
        int temp,r,sum=0,count=0;
        temp = num;
        /* Check for the prime number */
        for(int i=1;i<=temp;i++){
            if(temp%i==0){
                count++;
            }
            if(count>2) continue; //skip if number isn't the prime number
        }
        /* Check for the palindome number*/
        while(num>0){
            r = num%10;
            sum = (sum*10)+r;
            num=num/10;
        }
        /* Print Palindome prime number */
        if(temp==sum && count==2){
            System.out.print(temp+" ");
            n++;
            if(n%10==0){
                System.out.println(" ");
            }
        }
        num = temp; //return number for next loop
        num++; // move to next number
    }
    }
}
