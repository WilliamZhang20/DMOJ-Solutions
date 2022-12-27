// CCC 2004 J4
// 2D Array is arr[down][across]
import java.io.*;
import java.lang.*;

public class Main {

  static InputStreamReader r = new InputStreamReader(System.in);
  static BufferedReader br = new BufferedReader(r);

  public static void main(String[] args) {
    String input;
    String key;
    int a, b, c, d;
    key = getString();
    input = getString();
    input = input.replaceAll("[^a-zA-Z]+",""); //removes all special characters and spaces
    b = key.length();  // entire block needs to have the same length as the keyword
    a = 1 + (int) Math.ceil((double) input.length() / key.length()); // vertical

    char block[][] = new char[a][b]; // block for shifting letters
    // row 1 is the keyword
    for(int i=0; i<b; i++) {
      block[0][i]=key.charAt(i);
    }
    // row n will have all chars from input[n][last index filled] to input[n][last index + num of colums]
    c=0; // tracking index of input string that has been entered into the word block
    for(int i=1; i<a; i++) { // rows
      for(int j=0; j<b; j++) {  // indices of columns
        if(c+j<input.length()) {
          block[i][j]=input.charAt(c+j);
        } else {
          block[i][j]=' ';
        }
      }
      c+=b; // move onto next row for entering
    }
    // printBlock(block, a, b);
    
    // To shift letters, add ASCII values. A is 65 ASCII
    for(int k=0; k<b; k++) { // columns first
      d = ((int) block[0][k]) - 65; // amount to shift each letter in each column for A (ASCII 65), shift 0

      for(int n=1; n<a; n++) { // for each char in the column
        if(block[n][k] != ' ') {
          int asciiVal = (int) block[n][k];
          asciiVal+=d;  // shift by d
          if(asciiVal>90) { // if shifted past Z
            asciiVal=64 + (asciiVal-90); // go back to front of alphabet
          }
          block[n][k]=(char) asciiVal;
        }
      }
    }

    // Print Encrypted Word
    for(int i=1; i<a; i++) {
      for(int j=0; j<b; j++) {
        if(block[i][j] != ' ') {
          System.out.print(block[i][j]);
        }
      }
    }
    System.out.println();
  }

  public static String getString() {
    try {
      return br.readLine();
    } catch(Exception e) {
      return "";
    }
  }

  public static void printBlock(char arr[][], int a, int b) {
    // Test: print word block
    for(int i=0; i<a; i++) {
      for(int j=0; j<b; j++) {
        System.out.print(arr[i][j]+" ");
      }
      System.out.println();
    } 
  }
}
