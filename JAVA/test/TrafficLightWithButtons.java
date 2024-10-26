import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TrafficLightWithButtons extends JFrame implements ActionListener {
    private JRadioButton redButton, yellowButton, greenButton;
    private Color redColor, yellowColor, greenColor;
    private JPanel lightPanel;

    public TrafficLightWithButtons() {
        // Set up the frame
        setTitle("Traffic Light Simulator with Buttons");
        setSize(200, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // Create the panel to display lights
        lightPanel = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                g.setColor(Color.BLACK);
                g.fillRect(50, 30, 70, 200);

                g.setColor(redColor);
                g.fillOval(60, 40, 50, 50);

                g.setColor(yellowColor);
                g.fillOval(60, 100, 50, 50);

                g.setColor(greenColor);
                g.fillOval(60, 160, 50, 50);
            }
        };
        lightPanel.setPreferredSize(new Dimension(200, 300));
        add(lightPanel, BorderLayout.CENTER);

        // Initialize colors to off (gray)
        redColor = Color.GRAY;
        yellowColor = Color.GRAY;
        greenColor = Color.GRAY;

        // Create the radio buttons
        redButton = new JRadioButton("Red");
        yellowButton = new JRadioButton("Yellow");
        greenButton = new JRadioButton("Green");

        // Group the buttons to allow only one selection
        ButtonGroup group = new ButtonGroup();
        group.add(redButton);
        group.add(yellowButton);
        group.add(greenButton);

        // Add action listeners
        redButton.addActionListener(this);
        yellowButton.addActionListener(this);
        greenButton.addActionListener(this);

        // Create a panel for the buttons
        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new FlowLayout());
        buttonPanel.add(redButton);
        buttonPanel.add(yellowButton);
        buttonPanel.add(greenButton);
        add(buttonPanel, BorderLayout.SOUTH);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == redButton) {
            redColor = Color.RED;
            yellowColor = Color.GRAY;
            greenColor = Color.GRAY;
        } else if (e.getSource() == yellowButton) {
            redColor = Color.GRAY;
            yellowColor = Color.YELLOW;
            greenColor = Color.GRAY;
        } else if (e.getSource() == greenButton) {
            redColor = Color.GRAY;
            yellowColor = Color.GRAY;
            greenColor = Color.GREEN;
        }
        lightPanel.repaint();  // Refresh the panel to show the selected light color
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            TrafficLightWithButtons frame = new TrafficLightWithButtons();
            frame.setVisible(true);
        });
    }
}