#include "CM.h"

//录入学生人数
extern int NumofStudents = 0;
//学生头结点和指针
extern Student *pofstu{};
extern Student *rearofstu = new Student;
extern const Student *headofstu = rearofstu;

//录入宿舍楼数
extern int NumofDorms = 0;
//宿舍头结点和指针
extern Dorm *pofdorm{};
extern Dorm *rearofdorm = new Dorm;
extern const Dorm *headofdorm = rearofdorm;

//录入学生信息
void inputinformation()
{
    string s;
    getline(cin, s);
    vector<string> splitSemicolon = Util::split(s, "；"); // 以中文分号为分隔符进行对字符串进行分割
    NumofStudents += splitSemicolon.size();               //增加录入学生人数
    for (int i = 0; i < splitSemicolon.size(); ++i)
    {
        pofstu = new Student;
        rearofstu->next = pofstu;
        rearofstu = pofstu;
        // 以中文逗号为分隔符对字符串进行分割
        vector<string> splitComma = Util::split(splitSemicolon[i], "，");
        for (int j = 0; j < splitComma.size(); ++j)
        {
            // 以中文冒号为分隔符对字符串进行分割
            vector<string> splitColon = Util::split(splitComma[j], "：");
            if (splitColon[0] == "姓名")
            {
                pofstu->information.name = splitColon[1];
            }
            else if (splitColon[0] == "学号")
            {
                pofstu->information.id = splitColon[1];
            }
            else if (splitColon[0] == "电话")
            {
                pofstu->information.telephone = splitColon[1];
            }
            else if (splitColon[0] == "学院")
            {
                pofstu->information.school = splitColon[1];
            }
            else if (splitColon[0] == "寝室楼栋")
            {
                pofstu->information.address = splitColon[1];
            }
            else if (splitColon[0] == "班级")
            {
                pofstu->information.classnum = splitColon[1];
            }
            else if (splitColon[0] == "体温")
            {
                pofstu->information.temperature = splitColon[1];
            }
        }
    }
    cout << "num:" << NumofStudents;
}
//录入核酸信息
void inputPCR()
{
    string s;
    getline(cin, s);
    vector<string> splitSemicolon = Util::split(s, "；"); // 以中文分号为分隔符进行对字符串进行分割
    for (int i = 0; i < splitSemicolon.size(); ++i)
    {
        // 以中文逗号为分隔符对字符串进行分割
        vector<string> splitComma = Util::split(splitSemicolon[i], "，");
        //找到学生学号并存储
        string idforpcr;
        for (int j = 0; j < splitComma.size(); ++j)
        {
            bool flag1 = false;
            // 以中文冒号为分隔符对字符串进行分割
            vector<string> splitColon = Util::split(splitComma[j], "：");
            if (splitColon[0] == "学号")
            {
                idforpcr = splitColon[1];
                flag1 = true;
            }
            if (flag1)
                break;
        }
        //将该学号与数据库中信息进行比对
        bool flag2 = false;
        Student *p1 = (Student *)headofstu;
        for (int i = 0; i < NumofStudents; ++i)
        {
            if (p1->information.id != idforpcr)
            {
                p1 = p1->next;
            }
            else
            {
                flag2 = true;
                break;
            }
        }
        if (flag2) //如果找到该学号学生
        {
            for (int j = 0; j < splitComma.size(); ++j)
            {
                // 以中文冒号为分隔符对字符串进行分割
                vector<string> splitColon = Util::split(splitComma[j], "：");
                if (splitColon[0] == "日期")
                {
                    p1->information.PCR.date = splitColon[1];
                    p1->information.PCR.timeStamp = setTimePCR(p1->information.PCR.date);
                }
                else if (splitColon[0] == "结果")
                {
                    p1->information.PCR.consequence = splitColon[1];
                }
            }
        }
        else //如果未找到该学号学生
        {
            cout << "没有在数据库中找到学号为：" << idforpcr << "的学生" << endl;
        }
    }
}
//录入楼栋信息
void inputinformationofdorm()
{
    string s;
    getline(cin, s);
    vector<string> splitSemicolon = Util::split(s, "；"); // 以中文分号为分隔符进行对字符串进行分割
    NumofDorms += splitSemicolon.size();                  //增加录入宿舍楼数
    for (int i = 0; i < splitSemicolon.size(); ++i)
    {
        pofdorm = new Dorm;
        rearofdorm->next = pofdorm;
        rearofdorm = pofdorm;
        // 以中文逗号为分隔符对字符串进行分割
        vector<string> splitComma = Util::split(splitSemicolon[i], "，");
        for (int j = 0; j < splitComma.size(); ++j)
        {
            // 以中文冒号为分隔符对字符串进行分割
            vector<string> splitColon = Util::split(splitComma[j], "：");
            if (splitColon[0] == "楼名")
            {
                pofdorm->information.name = splitColon[1];
            }
            else if (splitColon[0] == "区名")
            {
                pofdorm->information.district = splitColon[1];
            }
            else if (splitColon[0] == "容量")
            {
                pofdorm->information.capacity = splitColon[1];
            }
            else if (splitColon[0] == "楼长")
            {
                pofdorm->information.chief = splitColon[1];
            }
        }
    }
}

void clean()
{
    char c;
    while ((c = getchar()) != '\n')
        ;
}
