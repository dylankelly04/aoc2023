import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.*;

public class day1part2 {
    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public Reader(String file_name) throws IOException {
            din = new DataInputStream(
                    new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String readLine() throws IOException {
            byte[] buf = new byte[64]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n') {
                    if (cnt != 0) {
                        break;
                    } else {
                        continue;
                    }
                }
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ') {
                c = read();
            }
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (neg)
                return -ret;
            return ret;
        }

        public long nextLong() throws IOException {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }

        public double nextDouble() throws IOException {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();

            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }

            if (neg)
                return -ret;
            return ret;
        }

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0,
                    BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

        public void close() throws IOException {
            if (din == null)
                return;
            din.close();
        }
    }

    public static void main(String[] args)
            throws IOException {
        Reader s = new Reader();
        long sum = 0;
        for (int y = 0; y < 1000; y++) {
            String str = s.readLine();
            String temp = "";
            // for (int vv = 0; vv < str.length() - 3; vv++) {
            // if (str.substring(vv, vv + 3).contains("one")) {
            // str = str.replaceFirst("one", "1");
            // break;
            // } else if (str.substring(vv, vv + 3).contains("two")) {
            // str = str.replaceFirst("two", "2");
            // break;
            // } else if ((vv < str.length() - 5) && str.substring(vv, vv +
            // 5).contains("three")) {
            // str = str.replaceFirst("three", "3");
            // break;
            // } else if ((vv < str.length() - 4) && str.substring(vv, vv +
            // 4).contains("four")) {
            // str = str.replaceFirst("four", "4");
            // break;
            // } else if ((vv < str.length() - 4) && str.substring(vv, vv +
            // 4).contains("five")) {
            // str = str.replaceFirst("five", "5");
            // break;
            // } else if (str.substring(vv, vv + 3).contains("six")) {
            // str = str.replaceFirst("six", "6");
            // break;
            // } else if ((vv < str.length() - 5) && str.substring(vv, vv +
            // 5).contains("seven")) {
            // str = str.replaceFirst("seven", "7");
            // break;
            // } else if ((vv < str.length() - 5) && str.substring(vv, vv +
            // 5).contains("eight")) {
            // str = str.replaceFirst("eight", "8");
            // break;
            // } else if ((vv < str.length() - 5) && str.substring(vv, vv +
            // 4).contains("nine")) {
            // str = str.replaceFirst("nine", "9");
            // break;
            // }
            // }
            // for (int vv = str.length(); vv >= 3; vv--) {
            // if (str.substring(vv - 3, vv).contains("one")) {
            // str = str.replaceAll("one", "1");
            // break;
            // } else if (str.substring(vv - 3, vv).contains("two")) {
            // str = str.replaceAll("two", "2");
            // break;
            // } else if ((vv - 5 >= 0) && str.substring(vv - 5, vv).contains("three")) {
            // str = str.replaceAll("three", "3");
            // break;
            // } else if ((vv - 4 >= 0) && str.substring(vv - 4, vv).contains("four")) {
            // str = str.replaceAll("four", "4");
            // break;
            // } else if ((vv - 4 >= 0) && str.substring(vv - 4, vv).contains("five")) {
            // str = str.replaceAll("five", "5");
            // break;
            // } else if (str.substring(vv - 3, vv).contains("six")) {
            // str = str.replaceAll("six", "6");
            // break;
            // } else if ((vv - 5 >= 0) && str.substring(vv - 5, vv).contains("seven")) {
            // str = str.replaceAll("seven", "7");
            // break;
            // } else if ((vv - 5 >= 0) && str.substring(vv - 5, vv).contains("eight")) {
            // str = str.replaceAll("eight", "8");
            // break;
            // } else if ((vv - 4 >= 0) && str.substring(vv - 4, vv).contains("nine")) {
            // str = str.replaceAll("nine", "9");
            // break;
            // }
            // }

            for (int i = 0; i < str.length(); i++) {
                if (Character.isDigit(str.charAt(i))) {
                    temp = temp + str.charAt(i);
                } else if (i + 3 <= str.length() && str.substring(i, i + 3).contains("one")) {
                    temp = temp + "1";
                } else if (i + 3 <= str.length() && str.substring(i, i + 3).contains("two")) {
                    temp = temp + "2";
                } else if (i + 5 <= str.length() && str.substring(i, i + 5).contains("three")) {
                    temp = temp + "3";
                } else if (i + 4 <= str.length() && str.substring(i, i + 4).contains("four")) {
                    temp = temp + "4";
                } else if (i + 4 <= str.length() && str.substring(i, i + 4).contains("five")) {
                    temp = temp + "5";
                } else if (i + 3 <= str.length() && str.substring(i, i + 3).contains("six")) {
                    temp = temp + "6";
                } else if (i + 5 <= str.length() && str.substring(i, i + 5).contains("seven")) {
                    temp = temp + "7";
                } else if (i + 5 <= str.length() && str.substring(i, i + 5).contains("eight")) {
                    temp = temp + "8";
                } else if (i + 4 <= str.length() && str.substring(i, i + 4).contains("nine")) {
                    temp = temp + "9";
                }
            }
            String finalans = temp.charAt(0) + "" + temp.charAt(temp.length() - 1);
            int ans = Integer.parseInt(finalans);
            System.out.println(ans);
            sum += ans;
        }
        System.out.println(sum);
    }
}
