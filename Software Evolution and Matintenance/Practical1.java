
import java.awt.FlowLayout;

import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
public class Practical1 implements ItemListener
{
 
FlowLayout layout = new FlowLayout();
 JComboBox <String> fruitbox = new JComboBox<>();
 JComboBox <String>herobox = new JComboBox<>();
 
 JLabel fruitlist = new JLabel("Fruit List");
 JLabel herolist = new JLabel("Hero List");
 JLabel selectEvent = new JLabel("Price will be shown on text box for selected fruit");
 JLabel heroEvent = new JLabel("Score will be shown on text box for selected hero");
 JTextField fruitprice = new JTextField(20);
 JTextField heroscore = new JTextField(20);
 
 
 int[] listprice = {10, 9 , 6, 12};
 int[] listscore = {95, 85, 90,80};
 int totalprice = 0; 
int score = 0;

 String output;
 String output2;
 int SelectNum;
 
 public Practical1() 
 {
    JPanel mypane = new JPanel();
 	
         
	mypane.setLayout(layout);
	mypane.add(fruitlist);
	fruitbox.addItemListener(this);
	fruitbox.addItem("Orange");
	fruitbox.addItem("Apple");
	fruitbox.addItem("Banana");
	fruitbox.addItem("Berries");
	
	
	mypane.add(fruitbox );
	mypane.add(selectEvent);
	mypane.add(fruitprice);
	
	
    mypane.setLayout(layout);
	mypane.add(herolist);
	herobox.addItemListener(this);
	herobox.addItem("Superman");
	herobox.addItem("My Lecturer");
	herobox.addItem("My Tutor");
	herobox.addItem("Myself ");
                       
        
    mypane.add(herobox );
	mypane.add(heroEvent);
	mypane.add(heroscore);
    JFrame frame = new JFrame("Practical1");
	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	frame.setSize(700, 500);
	frame.add(mypane);
	frame.setVisible(true);
                  
        
  }

public static void main(String[] args)
{

	new Practical1();
	
	

}
  
  public void itemStateChanged(ItemEvent e)
  {
    Object source = e.getSource();
    int choice=0;
	if (source == fruitbox)
	{
	 
		choice=fruitbox.getSelectedIndex();
		
		totalprice = listprice[choice];
		output = "The fruit price  is " + totalprice;
		
                 
	    
        fruitprice.setText(String.valueOf(output));
		
                                   
	}
	if(source == herobox){
		choice= herobox.getSelectedIndex();
        score = listscore[choice];
		output2= "The score of this hero is"+score;
		heroscore.setText(String.valueOf(output2)); 
	}
  
  }
      
    
  }
