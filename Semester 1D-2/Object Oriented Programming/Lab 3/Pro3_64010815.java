import java.util.Scanner;

public class Pro3_64010815 {
    public static void main(String[] args) {
        /* User Input */
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the size for the matrix: ");
        int n = input.nextInt();
        if(n>=2){
        /* Create Random Matrix*/
        int matrix[][] = new int[n][n];
        for(int i=0;i<n;i++){
            for(int k=0;k<n;k++)
                matrix[i][k] = (int)(Math.random()*2);
        }

        /*Display Matrix*/
        for(int i=0;i<matrix.length;i++){
            for(int k=0;k<matrix[i].length;k++){
                System.out.print(matrix[i][k]+" ");
            }
            System.out.println("");
        }

        /*Check number in a row*/
        int count=0;
        for(int i=0;i<matrix.length;i++){
            boolean num_same = true;
            for(int k=1;k<matrix[i].length;k++){
                if(matrix[i][0]!=matrix[i][k]){
                    num_same = false;
                    break;
                }
            }
            if(num_same){
                System.out.println("All "+matrix[i][0]+"s on row "+(i+1));
                count++;
            }
        }
        if(count==0){
            System.out.println("No same numbers on a row");
        }

        /*Check number in a column*/
        count=0;
        for(int i=0;i<matrix[0].length;i++){
            boolean num_same = true;
            for(int k=1;k<matrix.length;k++){
                if(matrix[0][i]!=matrix[k][i]){
                    num_same = false;
                    break;
                }
            }
            if(num_same){
                System.out.println("All "+matrix[i][0]+"s on column "+(i+1));
                count++;
            }
        }
        if(count==0){
            System.out.println("No same numbers on a row");
        }

        /*Check Superdiagonal*/
        boolean num_super = true;
        for(int i=2;i<matrix.length;i++){
            if(matrix[0][1]!=matrix[i-1][i]){
                num_super = false;
                break;
            }
        }
        if(num_super){
            System.out.println("All "+matrix[0][1]+"s on the superdiagonal ");
        }
        else{
            System.out.println("No same numbers on the superdiagonal");
        }

        /*Check Diagonal (left-> right)*/
        boolean num_diaonal = true;
        for(int i=1;i<matrix.length;i++){
            if(matrix[0][0]!=matrix[i][i]){
                num_diaonal = false;
                break;
            }
        }
        if(num_diaonal){
            System.out.println("All "+matrix[0][0]+"s on the diagonal ");
        }
        else{
            System.out.println("No same numbers on the diagonal");
        }

        /*Check Subdiagonal*/
        boolean num_sub = true;
        for(int i=2;i<matrix.length;i++){
            if(matrix[1][0]!=matrix[i][i-1]){
                num_sub = false;
                break;
            }
        }
        if(num_sub){
            System.out.println("All "+matrix[1][0]+"s on the subdiagonal ");
        }
        else{
            System.out.println("No same numbers on the subdiagonal");
        }
    }
    else System.out.println("Error! : Please Enter number more than 1");
    //Error1 : User try to input unreal size of matrix
    }
}
