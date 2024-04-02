import java.awt.*;
import java.awt.event.*;
import java.applet.*;

public class CalcApp extends Applet implements ActionListener {
    TextField t1, t2, t3;
    Button addButton, subButton, mulButton, divButton;

    public void init() {
        setBackground(Color.cyan);

        t1 = new TextField(10);
        t2 = new TextField(10);
        t3 = new TextField(10);
        t1.setFont(new Font("Arial", Font.PLAIN, 14));
        t2.setFont(new Font("Arial", Font.PLAIN, 14));
        t3.setFont(new Font("Arial", Font.PLAIN, 14));
        t3.setEditable(false);

        addButton = new Button("Add");
        subButton = new Button("Substract");
        mulButton = new Button("Multiply");
        divButton = new Button("Divide");
        addButton.setBounds(50, 100, 80, 50);
        addButton.setBounds(70, 100, 80, 50);
        addButton.setBounds(90, 100, 80, 50);
        addButton.setBounds(110, 100, 80, 50);

        add(new Label("Enter the value 1:"));
        add(t1);
        add(new Label("Enter the value 2:"));
        add(t2);
        add(new Label("Result:"));
        add(t3);
        add(addButton);
        add(subButton);
        add(mulButton);
        add(divButton);

        addButton.addActionListener(this);
        subButton.addActionListener(this);
        mulButton.addActionListener(this);
        divButton.addActionListener(this);

    }

    public void actionPerformed(ActionEvent a) {
        int num1 = 0, num2 = 0, result = 0;
        try {
            num1 = Integer.parseInt(t1.getText());
            num2 = Integer.parseInt(t2.getText());
        } catch (NumberFormatException ex) {
            t3.setText("Invalid Input");
            return;
        }

        if (a.getSource() == addButton) {
            result = num1 + num2;
        } else if (a.getSource() == subButton) {
            result = num1 - num2;
        } else if (a.getSource() == mulButton) {
            result = num1 * num2;
        } else if (a.getSource() == divButton) {
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                t3.setText("Error:Division By zero.");
                return;
            }
        }
        t3.setText(String.valueOf(result));
        System.out.println("Result:" + result);
    }
}