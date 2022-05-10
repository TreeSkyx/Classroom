import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.stage.Stage;

public class Pro1_64010815 extends Application {
    protected TextField tfLoanAmount = new TextField();
    protected TextField tfNumberOfYears = new TextField();
    protected TextArea textArea = new TextArea();

    @Override
    public void start(Stage primaryStage) {
        tfNumberOfYears.setPrefColumnCount(2);
        tfLoanAmount.setPrefColumnCount(7);
        textArea.setPrefColumnCount(35);

        Button btShowTable = new Button("Show Table");

        ScrollPane scrollPane = new ScrollPane();
    
        HBox paneForControls = new HBox(10);
        paneForControls.setAlignment(Pos.CENTER);
        paneForControls.getChildren().addAll(new Label("Loan Amount"),tfLoanAmount,new Label("Number of Years"),tfNumberOfYears,btShowTable);

        BorderPane pane = new BorderPane();
        pane.setTop(paneForControls);
        pane.setCenter(textArea);

        btShowTable.setOnAction(e -> {
        if(Double.parseDouble(tfLoanAmount.getText()) > 0 && Double.parseDouble(tfNumberOfYears.getText()) > 0){
            String output =  "";
            double monthlyInterestRate;
            double monthlyPayment;

            output += "Interrest Rate      Monthly Payment            Total Payment\n";
        
            for (double i = 5.0; i<= 8; i+=0.25){
                monthlyInterestRate = i/1200;
                monthlyPayment = Double.parseDouble(tfLoanAmount.getText()) * monthlyInterestRate*
                Math.pow((1+monthlyInterestRate), Double.parseDouble(tfNumberOfYears.getText())*12)/
                (Math.pow((1+monthlyInterestRate), Double.parseDouble(tfNumberOfYears.getText())*12) - 1);

                output += String.format("%-25.2f%-34.2f%8.2f\n", i,monthlyPayment,(monthlyPayment * 12) *
                Double.parseDouble(tfNumberOfYears.getText()));

            }
            textArea.setText(output);
        }
        else {
            String output =  "Error you must be entered Loan Amount and Number of Years more than 0";
            textArea.setText(output);
        }

        });

        Scene scene = new Scene(pane);
        primaryStage.setTitle("Loan GUI");
        primaryStage.setScene(scene);
        primaryStage.show();

    }

    public static void main(String[] args) {
        launch(args);
    }
}