import java.io.*;

public class Main {
  static InputStreamReader r = new InputStreamReader(System.in);
  static BufferedReader br = new BufferedReader(r);

  public static void main(String[] args) {
    boolean[][] square = new boolean[25][25];
    int ws, hs;
    int wc, hc;
    int direction;
    int x, y;
    boolean isMoving;
    int numSteps;
    ws=getInt(); // Rectangle width
    hs=getInt(); // Rectangle height
    wc=getInt(); // Cutout width
    hc=getInt(); // Cutout height
    numSteps = getInt();
    for(int i=0; i<hs; i++) {
      for(int j=0; j<ws; j++) {
        if(i<hc && j>=wc && j<ws-wc || i>=hc && i<=hs-hc-1 || i>=hs-hc && j>=wc && j<ws-wc) {
          square[i][j]=true;
        }
      }
    }
    //Walking
    x = wc;
    y = 0;
    direction=0;
    for(int i=0; i<numSteps; i++) {
      //System.out.println(x+" "+y);
      square[y][x]=false;
      isMoving=true;
      switch(direction) {
        case 0:
          if(y!=0 && square[y-1][x]) {
            y--;
            direction = 270;
          }
          else if(square[y][x+1]) {
            x++;
          }
          else if(square[y+1][x]) {
            y++;
            direction = 90;
          }
          else {
            isMoving=false;
          }
          break;
        case 90: 
          if(square[y][x+1]) {
            x++;
            direction = 0;
          }
          else if(square[y+1][x]) {
            y++;
          }  
          else if(square[y][x-1]) {
            x--;
            direction = 180;
          }
          else {
            isMoving = false;
          }
          break;
        case 180:
          if(square[y+1][x]) {
            y++;
            direction = 90;
          }
          else if(x!=0 && square[y][x-1]) {
            x--;
          }
          else if(square[y-1][x]) {
            y--;
            direction = 270;
          }
          else {
            isMoving = false;
          }
          break;
        case 270:
          if(x!=0 && square[y][x-1]) {
            x--;
            direction = 180;
          }
          else if(square[y-1][x]) {
            y--;
          }
          else if(square[y][x+1]) {
            x++;
            direction = 0;
          }
          else {
            isMoving = false;
          }
          break;
        default:
          System.out.printf("Wrong direction\n");
      }
      if(!isMoving) {
        break;
      }
    }
    System.out.println(x+1);
    System.out.println(y+1);
  }

  public static int getInt() { 
    try 
    { 
      return Integer.parseInt(br.readLine()); 
    } 
    catch (Exception e) 
    { 
      return 0; 
    }
  } 
}
