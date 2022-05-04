import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.List;

public class Fileter {
    public static void main(String[] args) {

    }
    public void writeInFile(String filePath, List<String> stringList) throws IOException {
        File file =new File(filePath);
        if(!file.exists())
        {
            file.createNewFile();
        }
        FileWriter fw=new FileWriter(file.getAbsoluteFile());
        BufferedWriter bw=new BufferedWriter(fw);
        for(String string:stringList)
        {
            bw.write(string);
            bw.write("\n");
        }
        bw.close();
        System.out.println("Done");
    }
}
