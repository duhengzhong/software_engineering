import java.math.BigDecimal;
import java.util.Deque;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;

public class Calculator {
    public static Map<Character, Integer> icp = new HashMap<>();
    public static Map<Character, Integer> isp = new HashMap<>();

    Calculator() {
        setMap(icp, isp);
    }

    public static void main(String[] args) {
        Calculator runner = new Calculator();
        String result = runner.MidtoLast("1.32*(1.854-3.26*2)");
        double digit = runner.getResult(result);
        System.out.println(digit);
    }

    private static void setMap(Map<Character, Integer> icp, Map<Character, Integer> isp) {
        icp.put('#', 0);
        icp.put('(', 6);
        icp.put('×', 4);
        icp.put('÷', 4);
        icp.put('+', 2);
        icp.put('-', 2);
        icp.put(')', 1);
        isp.put('#', 0);
        isp.put('(', 1);
        isp.put('×', 5);
        isp.put('÷', 5);
        isp.put('+', 3);
        isp.put('-', 3);
        isp.put(')', 6);
    }

    public String MidtoLast(String inputstr) {
        StringBuilder ans = new StringBuilder();
        String newinput = inputstr + '#';
        setMap(icp, isp);
        Deque<Character> stack = new LinkedList<>();
        stack.addLast('#');
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < newinput.length(); i++) {
            if (Character.isDigit(newinput.charAt(i)) || newinput.charAt(i) == '.') {
                sb.append(newinput.charAt(i));
            } else {
                if (sb.length() != 0) {
                    ans.append(sb);
                    ans.append(" ");
                    sb.setLength(0);
                }
                while (!stack.isEmpty() && isp.get(stack.peekLast()) > icp.get(newinput.charAt(i))) {
                    char c = stack.pollLast();
                    if (c != ')' && c != '(') {
                        ans.append(c);
                        ans.append(" ");
                    }
                }
                if (!stack.isEmpty() && isp.get(stack.peekLast()).intValue() == icp.get(newinput.charAt(i))) {
                    stack.pollLast();
                }
                stack.addLast(newinput.charAt(i));
            }
            if (sb.length() != 0 && i == newinput.length() - 1) {
                ans.append(sb);
                ans.append(" ");
                sb.setLength(0);
            }
        }
        return ans.toString();
    }

    public double getResult(String inputstr) {
        String strs[] = inputstr.split(" ");
        Deque<Double> stack = new LinkedList<>();
        for (String str : strs) {
            if (icp.containsKey(str.charAt(0))) {
                double b = stack.pollLast();
                BigDecimal B = new BigDecimal(b);
                double a = stack.pollLast();
                BigDecimal A = new BigDecimal(a);
                double c = 0;
                switch (str.charAt(0)) {
                    case '×':
                        c = B.multiply(A).doubleValue();
                        stack.addLast(c);
                        break;
                    case '÷':
                        c = A.divide(B, 30, BigDecimal.ROUND_HALF_UP).doubleValue();
                        stack.addLast(c);
                        break;
                    case '+':
                        c = A.add(B).doubleValue();
                        stack.addLast(c);
                        break;
                    case '-':
                        c = A.subtract(B).doubleValue();
                        stack.addLast(c);
                        break;
                }
            } else {
                stack.addLast(Double.parseDouble(str));
            }
        }
        return stack.pollLast();
    }

    public boolean isEqual(double a, double b) {
        return Math.abs(a - b) < 0.00001;
    }

    public double getFormulaResult(String inputstr) {
        return getResult(MidtoLast(inputstr));
    }
}

