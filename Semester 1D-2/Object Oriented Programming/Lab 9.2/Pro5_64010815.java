import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.control.Button;
import javafx.geometry.Pos;
import javafx.stage.Stage;

public class Pro5_64010815 extends Application {
    @Override
    public void start(Stage primaryStage){
        FanPane fanPane = new FanPane();

        Button bPause = new Button("Pause");
        Button bResume = new Button("Resume");
        Button bReverse = new Button("Reverse");

        HBox hBox = new HBox(5);
        hBox.setAlignment(Pos.CENTER);

        hBox.getChildren().addAll(bPause,bResume,bReverse);

        BorderPane borderPane = new BorderPane();
        borderPane.setCenter(fanPane);
        borderPane.setBottom(hBox);

        bPause.setOnAction(e -> {
            fanPane.pause();
        });
        bResume.setOnAction(e -> {
            fanPane.play();
        });
        bReverse.setOnAction(e -> {
            fanPane.reverse();
        });

        Scene scene = new Scene(borderPane, 250, 250);
        primaryStage.setTitle("Exercise15_28");
        primaryStage.setScene(scene);
        primaryStage.show();
        fanPane.requestFocus();

    }

    public static void main(String[] args) {
        launch(args);
    }
}
