import java.io.*;

public class Student
{
    private int ID;
    private int classID;
    private String name;
    private String sex;
    private int age;

    public static String MALE = "male";
    public static String FEMALE = "female";

    public int getID()
    {
        return ID;
    }

    public int getClassID()
    {
        return classID;
    }

    public String getSex()
    {
        return sex;
    }

    public int getAge()
    {
        return age;
    }

    public void setAge(int age)
    {
        this.age = age;
    }

    public Student(int ID, int classID, String name, String sex, int age)
    {
        this.ID = ID;
        this.classID = classID;
        this.name = name;
        setAge(age);
        this.sex = sex;
    }

    public String toString()
    {
        StringBuffer buffer = new StringBuffer();
        buffer.append("ѧ�ţ�");
        buffer.append(ID);
        buffer.append("���༶��");
        buffer.append(classID);
        buffer.append("��������");
        buffer.append(name);
        buffer.append("���Ա�");
        if (sex.equals(MALE))
        {
            buffer.append("��");
        }
        else if (sex.equals(FEMALE))
        {
            buffer.append("Ů");
        }
        else
        {
            buffer.append(sex);
        }
        buffer.append("�����䣺");
        buffer.append(age);
        buffer.append("��");
        return buffer.toString();
    }

    public static void main(String[] args) throws IOException,
        NumberFormatException
    {
        System.out.println("��ҵ2-1��Student��");
        System.out.println("by slhynju");
        System.out.println();
        System.out.println("Stuent����ѧ�š��༶�š��������Ա����乹�ɡ�");
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("������ѧ�ţ�");
        String s = r.readLine();
        int ID = Integer.parseInt(s);
        System.out.print("������༶�ţ�");
        s = r.readLine();
        int classID = Integer.parseInt(s);
        System.out.print("������������");
        String name = r.readLine();
        System.out.print("�������Ա�M��ʾ�У�F��ʾŮ���������뽫�������䣺");
        String sex = r.readLine();
        if (sex.equalsIgnoreCase("M"))
        {
            sex = MALE;
        }
        else if (sex.equalsIgnoreCase("F"))
        {
            sex = FEMALE;
        }
        System.out.print("���������䣺");
        s = r.readLine();
        int age = Integer.parseInt(s);
        Student student = new Student(ID, classID, name, sex, age);
        System.out.println();
        System.out.println("�����������Ϊ��");
        System.out.println(student.toString());
    }
}
