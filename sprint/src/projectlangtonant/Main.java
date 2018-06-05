package projectlangtonant;

import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;


public class Main extends Application {

    int tmpDirection = 8;
    String tmpHandling = "RL";
    Scene scene;
    AntLoop antLoop;

    @Override
    public void start(Stage window) throws Exception{
        window.setTitle("Langton Ant");

        /**
         * Creating box containing handling stuff
         */
        TextField inputHandling = new TextField();
        Button buttonHandling = new Button("Set handling");
        buttonHandling.setOnAction( e -> antLoop.changeHandling(inputHandling.getText()));
        Label handlingText = new Label("Handling:");
        VBox handlingBox = new VBox(10);
        handlingBox.setPadding(new Insets(20,20,20,10));
        handlingBox.getChildren().addAll(handlingText,inputHandling, buttonHandling);

        /**
         * Creating box containing direction stuff
         */
        GridPane gridPane = new GridPane();
        gridPane.setPadding(new Insets(20,20,20,20));
        gridPane.setVgap(20);
        gridPane.setHgap(20);
        Button buttonDirectionN = new Button("N");
        buttonDirectionN.setOnAction( e -> tmpDirection = 8);
        gridPane.setConstraints(buttonDirectionN, 1,0);
        Button buttonDirectionW = new Button("W");
        buttonDirectionW.setOnAction( e -> tmpDirection = 4);
        gridPane.setConstraints(buttonDirectionW, 0,1);
        Button buttonDirectionS = new Button("S");
        buttonDirectionS.setOnAction( e -> tmpDirection = 2);
        gridPane.setConstraints(buttonDirectionS, 1,2);
        Button buttonDirectionE = new Button("E");
        buttonDirectionE.setOnAction( e -> tmpDirection = 6);
        gridPane.setConstraints(buttonDirectionE, 2,1);
        gridPane.getChildren().addAll(buttonDirectionN,buttonDirectionW,buttonDirectionS,buttonDirectionE);
        Label directionText = new Label("Direction:");
        VBox directionOptions = new VBox();
        directionOptions.getChildren().addAll(directionText, gridPane);
        /////////////////
        Button startButton = new Button("START");
        startButton.setStyle("-fx-background-color: MediumSeaGreen");
        startButton.setPrefSize(150,50);
        Button pauseButton = new Button("PAUSE");
        pauseButton.setStyle("-fx-background-color: Yellow");
        pauseButton.setPrefSize(150,50);
        Button stopButton = new Button("STOP");
        stopButton.setStyle("-fx-background-color: Red");
        stopButton.setPrefSize(150,50);
        VBox controllButtons = new VBox( 20);
        controllButtons.getChildren().addAll(startButton, pauseButton, stopButton);
        /////////////////
        VBox layoutOptions = new VBox(20);
        layoutOptions.getChildren().addAll(handlingBox, directionOptions, controllButtons);
        /////////////////
        Canvas canvas = new Canvas(600, 600);
        GraphicsContext gc = canvas.getGraphicsContext2D();
        /////////////////
        HBox layout = new HBox(20);
        layout.getChildren().addAll(canvas,layoutOptions);
        /////////////////
        scene = new Scene(layout, 800, 600);
        window.setResizable(false);
        window.setScene(scene);
        window.show();
        /////////////////

        antLoop = new AntLoop();
        antLoop.mainLoop(gc, startButton, pauseButton, stopButton);
        antLoop.changeHandling(tmpHandling);
    }

      public static void main(String[] args) {
        launch(args);
    }
}
