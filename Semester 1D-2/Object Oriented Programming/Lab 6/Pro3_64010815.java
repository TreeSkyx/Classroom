public class Pro3_64010815 {
    public static void main(String[] args) {
        Queue q = new Queue();

        // Add 20 numbers into the queue
        for(int i=1;i<=20;i++){
                q.enqueue(i); 
        }

        // remove these number & display
        while(!q.empty()){
            System.out.print(q.dequeue() + " ");
        }
    }
}
