import java.io.*;

public class Main {
  static InputStreamReader r = new InputStreamReader(System.in);
  static BufferedReader br = new BufferedReader(r);

  public static void main(String[] args) {
    String word;
    boolean output[] = new boolean[100];
    int i=0;
    while(true) {
      word = readString();
      if(word.equals("X")) {
        break;
      }
      //Find if it is monkey word
      if(isMonkeyWord(word)) {
        output[i]=true;
      }
      i++;
    }
    for(int j=0; j<i; j++) {
      if(output[j]) {
        System.out.println("YES");
      } else {
        System.out.println("NO");
      }
    }
  }

  /*
  An a-word is either:
  1. The letter A.
  2. The letter B + Monkey Language Word + S.
  */
  public static boolean isAword(String w) {
    if(w.equals("A")) { //A-Word
      return true;
    } 
    else if(w.length()>=3 && w.charAt(0)=='B' && isMonkeyWord(w.substring(1, w.length()-1)) && w.charAt(w.length()-1)=='S') {
      return true;
    }
    return false;
  }

  /*
  A monkey language Word is either
  1. An a-word
  2. An a-word + n + monkey language word
  */
  public static boolean isMonkeyWord(String w) { 
    if(isAword(w)) {
      return true;
    } 
    else {
      for(int i=1; i<=w.length()-2; i++) {
        // Need to put i<=w.length()-2 because for ANA, the index for n (the focus point) is 1, which is 3-2. 
        if(isAword((w.substring(0, i))) && w.charAt(i)=='N' && isMonkeyWord((w.substring(i+1)))) {
          return true;
        }
      }
    }
    return false;
  }

  public static String readString() {
    try { 
      return br.readLine();
    } catch (Exception e) {
      return "";
    }
  }
}
