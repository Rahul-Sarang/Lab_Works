import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class AdvCalc extends JFrame implements ActionListener {
    private JTextField display;
    private double num1, num2, result;
    private char operator;

    public AdvCalc() {
        // Create the frame
        setTitle("Advanced Calculator");
        setSize(400, 600);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // Create the display
            display = new JTextField();
        display.setFont(new Font("Arial", Font.BOLD, 36));
        display.setEditable(false);
        add(display, BorderLayout.NORTH);

        // Create the panel for buttons
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(5, 4));

        // Button labels including advanced operations
        String[] buttonLabels = {
                "7", "8", "9", "/",
                "4", "5", "6", "*",
                "1", "2", "3", "-",
                "0", ".", "=", "+",
                "√", "x²", "%", "C",
                "←", "(", ")", "xⁿ"
        };

        // Create buttons and add them to the panel
        for (String label : buttonLabels) {
            JButton button = new JButton(label);
            button.setFont(new Font("Arial", Font.BOLD, 36));
            button.addActionListener(this);
            panel.add(button);
        }

        add(panel, BorderLayout.CENTER);
    }

    public static void main(String[] args) {
        // Create the advanced calculator frame
        AdvCalc calculator = new AdvCalc();
        calculator.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String command = e.getActionCommand();

        try {
            // Handle number and decimal point input
            if (command.charAt(0) >= '0' && command.charAt(0) <= '9' || command.equals(".")) {
                display.setText(display.getText() + command);
            }
            // Handle operators
            else if (command.equals("+") || command.equals("-") || command.equals("*") || command.equals("/") || command.equals("xⁿ")) {
                num1 = Double.parseDouble(display.getText());
                operator = command.charAt(0);
                display.setText("");
            }
            // Handle square root
            else if (command.equals("√")) {
                num1 = Double.parseDouble(display.getText());
                result = Math.sqrt(num1);
                display.setText(String.valueOf(result));
            }
            // Handle square
            else if (command.equals("x²")) {
                num1 = Double.parseDouble(display.getText());
                result = num1 * num1;
                display.setText(String.valueOf(result));
            }
            // Handle percentage
            else if (command.equals("%")) {
                num1 = Double.parseDouble(display.getText());
                result = num1 / 100;
                display.setText(String.valueOf(result));
            }
            // Handle equals
            else if (command.equals("=")) {
                num2 = Double.parseDouble(display.getText());
                switch (operator) {
                    case '+': result = num1 + num2; break;
                    case '-': result = num1 - num2; break;
                    case '*': result = num1 * num2; break;
                    case '/': result = num1 / num2; break;
                    case 'x': result = Math.pow(num1, num2); break; // For xⁿ (power)
                }
                display.setText(String.valueOf(result));
            }
            // Handle Clear
            else if (command.equals("C")) {
                display.setText("");
            }
            // Handle Backspace
            else if (command.equals("←")) {
                String text = display.getText();
                if (!text.isEmpty()) {
                    display.setText(text.substring(0, text.length() - 1));
                }
            }
        } catch (NumberFormatException ex) {
            display.setText("Error");
        }
    }
}
