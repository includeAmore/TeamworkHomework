#include "CM.h"
#include"help.cpp"
#include"inputinformation.cpp"
#include"SubmitInformation.cpp"
#include"inandoutmanagement.cpp"
extern const Student *headofstu;
extern int NumofStudents;
extern string timeNow;   //目前时间
extern int timeStampNow; //当前的时间戳
int main()
{
    getTimeNow();
    cout << "教师登录请按 1；学生登录请按 2" << endl;
    cout << "请输入：";
    int r;
    cin >> r;
    if (r == 1)
    {
        while (true)
        {
            help();
            int n;
            cin >> n;
            switch (n)
            {
                case 1: //信息导入模块
                {
                    bool flag = false;
                    while (true)
                    {
                        helpofinput();
                        cin >> n;
                        switch (n)
                        {
                            case 1:
                                clean();
                                helpofstudentinput();
                                inputinformation();
                                clean();
                                break;
                            case 2:
                                clean();
                                helpofpcrinput();
                                inputPCR();
                                clean();
                                break;
                            case 3:
                                clean();
                                helpofdorminput();
                                inputinformationofdorm();
                                clean();
                                break;
                            case 4:
                                flag = true;
                                break;
                            default:
                                cout << "请求无效，请重新输入：";
                                break;
                        }
                        if (flag)
                            break;
                    }
                    break;
                }
                case 2: //信息上报管理模块
                {
                    bool flag = false;
                    while (true)
                    {
                        helpofsubmit();
                        cin >> n;
                        switch (n)
                        {
                            case 1:
                                clean();
                                searchforstu((Student *)headofstu);
                                clean();
                                break;
                            case 2:
                                clean();
                                classSearchPCR((Student *)headofstu);
                                clean();
                                break;
                            case 3:
                                clean();
                                dormSearchPCR((Student *)headofstu);
                                clean();
                                break;
                            case 4:
                                clean();
                                SearchExpire((Student *)headofstu);
                                clean();
                                break;
                            case 5:
                                flag = true;
                                break;
                            default:
                                cout << "请求无效，请重新输入：";
                                break;
                        }
                        if (flag)
                            break;
                    }
                }
                    break;
                case 3: //进出校门管理模块
                    cout << "即将为您显示已提交申请学生的信息：" << endl;
                    inandout((Student *)headofstu);
                    break;
                case 4: //
                    /* code */
                    break;
                default:
                    cout << "请重新输入！";
                    break;
            }
        }
    }
    else if (r == 2)
    {
        string s;
        while (true)
        {
            cout << "请输入学号：";
            cin >> s;
            bool flag = false; //匹配学号
            Student *pp = (Student *)headofstu;
            for (int i = 0; i < NumofStudents; ++i)
            {
                if (pp->information.id != s)
                {
                    pp = pp->next;
                }
                else
                {
                    flag = true;
                    break;
                }
            }
            if (flag) //如果找到该学号学生
            {
                while (true)
                {
                    bool flag1 = false;
                    helpforstu();
                    int n;
                    cin >> n;
                    switch (n)
                    {
                        case 1: //学生个人信息查询模块
                            clean();
                            searchforper(pp);
                            flag1 = true;
                            break;
                        case 2:
                            clean();
                            applyforinandout(pp); //学生进出小申请模块
                            flag1 = true;
                            break;
                        default:
                            cout << "请重新输入！";
                            break;
                    }
                    if (flag1)
                        break;
                }
            }
            else
            {
                cout << "查无此人，请重新输入！" << endl;
            }
        }
    }
    return 0;
}
