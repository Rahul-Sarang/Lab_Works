import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class AnimatedGame extends JPanel implements ActionListener {

    private int xPos = 0; // X position of the character
    private Timer timer;

    public AnimatedGame() {
        timer = new Timer(20, this); // Timer to control the animation speed
        timer.start(); // Start the animation
    }

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        drawCharacter(g); // Draw the character
    }

    private void drawCharacter(Graphics g) {
        g.setColor(Color.BLUE);
        g.fillRect(xPos, 150, 50, 50); // A simple blue square as the character
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        xPos += 5; // Move the character to the right
        if (xPos > getWidth()) {
            xPos = 0; // Reset position if character moves off-screen
        }
        repaint(); // Repaint the panel to update the character's position
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Animated Adventure Game");
        AnimatedGame game = new AnimatedGame();

        // Set up the game window
        frame.add(game);
        frame.setSize(800, 400); // Window size
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);

        // Display a welcome message
        JOptionPane.showMessageDialog(frame, "Welcome to the Adventure Game! Watch the character move!");
    }
}
