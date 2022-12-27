//CCC 2005 J1
//Refer to https://www.cemc.uwaterloo.ca/contests/computing/2005/stage1/juniorEn.pdf Problem J1 for the instructions
//William 11/14/2020

import java.io.*;

public class Main {
  static InputStreamReader r = new InputStreamReader(System.in);
  static BufferedReader br = new BufferedReader(r);
  
  public static void main(String[] args) {
    int dayMin, eveningMin, weekendMin;
    double costA=0.0, costB=0.0;
    //System.out.println("Number of daytime minutes?");
    dayMin = getInt();
    //System.out.println("Number of evening minutes?");
    eveningMin = getInt();
    //System.out.println("Number of weekend minutes?");
    weekendMin = getInt();
    
    if(dayMin>250) {
      costA = (dayMin-100)*0.25+eveningMin*0.15+weekendMin*0.2;
      costB = (dayMin-250)*0.45+eveningMin*0.35+weekendMin*0.25;
    }
    else if(dayMin>100) {
      costA = (dayMin-100)*0.25+eveningMin*0.15+weekendMin*0.2;
      costB = eveningMin*0.35+weekendMin*0.25;
    }
    else {
      costA = eveningMin*0.15+weekendMin*0.2;
      costB = eveningMin*0.35+weekendMin*0.25;
    }
    System.out.printf("Plan A costs %.2f\n", costA);
    System.out.printf("Plan B costs %.2f\n", costB);
  
    if(costA>costB) {
      System.out.printf("Plan B is cheapest.%n");
    }
    else if(costA<costB) {
      System.out.printf("Plan A is cheapest.%n");
    }
    else {
      System.out.printf("Plan A and B are the same price.%n");
    }
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
