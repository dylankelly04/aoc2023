import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.*;

public class day2part1 {

    public static void main(String[] args)
            throws IOException {
        Scanner s = new Scanner(System.in);
        int sum = 0;
        int bluenum = 0;
        int rednum = 0;
        int greennum = 0;
        int power = 0;
        boolean conf;
        for (int y = 0; y < 100; y++) {
            String input = s.nextLine();
            String[] str = input.split(":");
            String temp = str[0];
            String temp2 = temp.split(" ")[1];
            int gamenum = Integer.parseInt(temp2);
            String[] games = str[1].split(";");
            conf = true;
            power = 0;
            int tempval = 1;
            greennum = 1;
            bluenum = 1;
            rednum = 1;
            for (int i = 0; i < games.length; i++) {
                tempval = 1;
                String[] game = games[i].split(",");
                for (int j = 0; j < game.length; j++) {
                    if (game[j].contains("blue")) {
                        bluenum = Math.max(Integer.parseInt(game[j].strip().split(" ")[0]), bluenum);
                    } else if (game[j].contains("green")) {
                        greennum = Math.max(Integer.parseInt(game[j].strip().split(" ")[0]), greennum);
                    } else if (game[j].contains("red")) {
                        rednum = Math.max(Integer.parseInt(game[j].strip().split(" ")[0]), rednum);
                    }
                }
            }
            tempval = greennum * bluenum * rednum;
            sum += tempval;
        }
        System.out.println(sum);
    }
}
