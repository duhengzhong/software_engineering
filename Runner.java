import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Runner {
    public static void main(String[] args) throws IOException {
        Calculator calculator = new Calculator();
        Questioner questioner = new Questioner();
        List<String>list=new ArrayList<>();
        System.out.println("请输入出题数量:");
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        System.out.println("请输入数字上限:");
        int upper=sc.nextInt();
        System.out.println("是否生成文件");
        boolean doFile=sc.nextBoolean();
        System.out.println("运算式是否包含括号");
        boolean hasPare=sc.nextBoolean();
        System.out.println("运算式是否有小数");
        boolean hasPoint=sc.nextBoolean();
        for (int i = 0; i < n; i++) {
            String str;
            if(hasPare){
                 str = questioner.questionWithParentheses(hasPoint, upper);
            }
            else{
                str = questioner.questionWithoutParentheses(hasPoint, upper);
            }
            System.out.println(str);
            double result = calculator.getFormulaResult(str);
            System.out.println(result);
            list.add(str+"————"+result);
        }
        if(doFile) {
            Fileter fileter = new Fileter();
            fileter.writeInFile("F:/BaiduNetdiskDownload/SoftwareEngineeringWork/Homework4/result.txt", list);
        }
    }
}
