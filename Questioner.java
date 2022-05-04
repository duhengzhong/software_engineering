import java.util.Arrays;
import java.util.List;
import java.util.Random;

public class Questioner {
    public static void main(String[] args) {
        Questioner questioner = new Questioner();
        for (int i = 0; i < 100; i++)
            System.out.println(questioner.questionWithParentheses(true, 100));
    }

    public static List<Character> randomList = Arrays.asList('×', '÷', '+', '-');

    public double randomDigit(boolean hasPoint, double upper) {
        Random random = new Random();
        return hasPoint ? random.nextDouble(0.01, upper) : random.nextInt(1, (int) upper);
    }

    public char randomOperator() {
        Random random = new Random();
        return randomList.get(random.nextInt(0, randomList.size()));
    }

    public String questionWithoutParentheses(boolean hasPoint, double upper) {
        StringBuilder sb = new StringBuilder();
        Random random = new Random();
        int flag = 0;
        int len = random.nextInt(2, 10);
        int pointLen = 0;
        for (int i = 0; i < len; i++) {
            pointLen = random.nextInt(4, 8);
            flag = random.nextInt(0, 2);
            if (flag == 1 && hasPoint) {
                sb.append(Double.toString(randomDigit(true, upper)), 0, pointLen);
            } else {
                sb.append((int) randomDigit(false, upper));
            }
            if (i == len - 1) continue;
            sb.append(randomOperator());
        }
        return sb.toString();
    }

    public String questionWithParentheses(boolean hasPoint, double upper) {
        StringBuilder sb = new StringBuilder();
        Random random = new Random();
        int left = 0;
        int flag = 0;
        int len = random.nextInt(2, 10);
        int leftPareFlag = 0;
        int rightPareFlag = 0;
        int pointLen = 0;
        for (int i = 0; i < len; i++) {
            boolean nowPare = false;
            boolean isLast = i == len - 1;
            pointLen = random.nextInt(4, 8);
            flag = random.nextInt(0, 2);
            leftPareFlag = random.nextInt(0, 3);
            rightPareFlag = random.nextInt(0, 3);
            if (leftPareFlag == 0 && !isLast) {
                sb.append('(');
                left++;
                nowPare = true;
            }
            if (flag == 1 && hasPoint) {
                sb.append(Double.toString(randomDigit(true, upper)), 0, pointLen);
            } else {
                sb.append((int) randomDigit(false, upper));
            }
            if (left > 0 && rightPareFlag == 0 && !nowPare) {
                sb.append(')');
                left--;
            }
            if (i == len - 1) continue;
            sb.append(randomOperator());
        }
        for (int i = 0; i < left; i++) {
            sb.append(")");
        }
        return sb.toString();
    }
}


