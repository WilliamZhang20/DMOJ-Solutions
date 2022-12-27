import java.io.*;
import java.util.*;

public class Main {
  static InputStreamReader r = new InputStreamReader(System.in);
  static BufferedReader br = new BufferedReader(r);

  public static void main(String[] args) {
    String[] words = new String[100];
    int[] time = new int[100];
    int i=0;
    // Make Dictionary of letters
    Map<Character, Integer> map = new HashMap<Character, Integer>();
    map.put('a', 1);
    map.put('b', 2);
    map.put('c', 3);
    map.put('d', 1);
    map.put('e', 2);
    map.put('f', 3);
    map.put('g', 1);
    map.put('h', 2);
    map.put('i', 3);
    map.put('j', 1);
    map.put('k', 2);
    map.put('l', 3);
    map.put('m', 1);
    map.put('n', 2);
    map.put('o', 3);
    map.put('p', 1);
    map.put('q', 2);
    map.put('r', 3);
    map.put('s', 4);
    map.put('t', 1);
    map.put('u', 2);
    map.put('v', 3);
    map.put('w', 1);
    map.put('x', 2);
    map.put('y', 3);
    map.put('z', 4);
    // Take input and process
    while(true) {
      words[i] = getString();
      if (words[i].equals("halt")) {
        break;
      } 
      for(int j=0; j<words[i].length(); j++) {
        time[i]+=(map.get(words[i].charAt(j)));
        if(j>0 && findButton(words[i].charAt(j))==findButton(words[i].charAt(j-1))) {
          time[i]+=2;
        }
      }
      i++;
    }
    // Print the numbers of seconds out
    for(int k=0; k<i; k++) {
      System.out.println(time[k]);
    }
  }

  public static int findButton(char ch) {
    char[][] keys = {
      {'a', 'b', 'c'},
      {'d', 'e', 'f'},
      {'g', 'h', 'i'}, 
      {'j', 'k', 'l'},
      {'m', 'n', 'o'}, 
      {'p', 'q', 'r', 's'},
      {'t', 'u', 'v'}, 
      {'w', 'x', 'y', 'z'},
    }; // 8 buttons in total
    for(int i=0; i<8; i++) {
      for(int j=0; j<keys[i].length; j++) {
        if(ch==keys[i][j]) {
          return i;
        }
      }
    }
    return 0;
  }

  public static String getString() {
    try {
      return br.readLine();
    } catch(Exception e) {
      return "";
    }
  }
}
