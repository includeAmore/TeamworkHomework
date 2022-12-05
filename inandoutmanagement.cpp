#include "CM.h"

void inandout(Student *head)
{
    int r;
    Student *cnt = head->next;
    while (cnt != NULL)
    {
        if (cnt->information.Apply.state == true)
        {
            cout << "学院：" << cnt->information.school << "  姓名：" << cnt->information.name << "  学号：" << cnt->information.id
                 << "  申请校区：" << cnt->information.Apply.campus << "  申请原因：" << cnt->information.Apply.reason << "  申请类型：" << cnt->information.Apply.type;
            if (cnt->information.Apply.type == "applyforin")
                cout << "申请入校时间：" << cnt->information.Apply.Indate << endl;
            else if (cnt->information.Apply.type == "applyforout")
                cout << "申请出校时间：" << cnt->information.Apply.Outdate << endl;
            else if (cnt->information.Apply.type == "applyforinandout")
                cout << "申请入校时间：" << cnt->information.Apply.Indate << " "
                     << "申请出校时间：" << cnt->information.Apply.Outdate << endl;
            cout << "请您审批（通过请按 1；不通过请按 2）：";
            int n;
            bool flag = false;
            while (true)
            {
                cin >> n;
                switch (n)
                {
                case 1:
                    flag = true;
                    cnt->information.Apply.check = true;
                    break;
                case 2:
                    flag = true;
                    cnt->information.Apply.check = false;
                    break;
                default:
                    cout << "非法输入!请重新输入:";
                    break;
                }
                if (flag)
                    break;
            }
        }
        cnt = cnt->next;
        cout << "继续审批请按 1，退出请按 0：";
        while (true)
        {
            cin >> r;
            bool flag1 = false;
            switch (r)
            {
            case 1:
                flag1 = true;
                break;
            case 0:
                return;
            default:
                cout << "非法输入!请重新输入:";
                break;
            }
            if (flag1)
                break;
        }
    }
    cout << "所有待审批项已全部审阅" << endl;
}

void searchforper(Student *cnt)
{
    cout << "学院：" << cnt->information.school << endl;
    cout << "姓名：" << cnt->information.name << endlv;
    cout << "学号：" << cnt->information.id << endl;
    cout << "电话：" << cnt->information.telephone << endl;
    cout << "寝室楼栋：" << cnt->information.address << endl;
    cout << "班级号：" << cnt->information.classnum << endl;
    cout << "体温：" << cnt->information.temperature << endl;
    cout << "疫苗注射情况：" << cnt->information.vaccine << endl;
    cout << "最近一次核酸检测日期：" << cnt->information.PCR.date << endl;
    cout << "最近一次核酸检测结果：" << cnt->information.PCR.consequence << endl;
}

void applyforinandout(Student *head)
{
    int n;
    bool flag = false;
    while (true)
    {
        cout << "提交申请请按 1" << endl;
        cout << "删除申请请按 2" << endl;
        cout << "修改申请请按 3" << endl;
        cout << "查询申请请按 4" << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            app(head);
            flag = true;
            break;
        case 2:
            del(head);
            flag = true;
            break;
        case 3:
            change(head);
            flag = true;
            break;
        case 4:
            check(head);
            flag = true;
            break;
        default:
            break;
        }
        if (flag)
            break;
    }
}

void app(Student *head)
{
    int r;
    head->information.Apply.state = true;
    cout << "请输入申请校区：";
    cin >> head->information.Apply.campus;
    cout << "申请入校请按 1；" << endl;
    cout << "申请出校请按 2；" << endl;
    cout << "申请进出校请按 3；" << endl;
    cout << "请输入：";
    cin >> r;
    switch (r)
    {
    case 1:
        head->information.Apply.type == "applyforin";
        cout << "请输入申请入校时间（xxxx.xx.xx）：";
        cin >> head->information.Apply.Indate;
        break;
    case 2:
        head->information.Apply.type == "applyforout";
        cout << "请输入申请出校时间（xxxx.xx.xx）：";
        cin >> head->information.Apply.Outdate;
        break;
    case 3:
        head->information.Apply.type == "applyforinandout";
        cout << "请输入申请入校时间（xxxx.xx.xx）：";
        cin >> head->information.Apply.Indate;
        cout << "请输入申请出校时间（xxxx.xx.xx）：";
        cin >> head->information.Apply.Outdate;
        break;
    }
    cout << "请输入申请原因：";
    cin >> head->information.Apply.reason;
}

void del(Student *head)
{
    head->information.Apply.state = false;
}

void change(Student *head)
{
    int r;
    bool flag2 = false;
    cout << "修改校区请按 1" << endl;
    cout << "修改进出校类型/时间请按 2" << endl;
    cout << "修改原因请按 3" << endl;
    cout << "请输入：";
    while (true)
    {
        cin >> r;
        switch (r)
        {
        case 1:
            cout << "请输入申请校区：";
            cin >> head->information.Apply.campus;
            flag2 = true;
            break;
        case 2:
            cout << "申请入校请按 1；" << endl;
            cout << "申请出校请按 2；" << endl;
            cout << "申请进出校请按 3；" << endl;
            cout << "请输入：";
            cin >> r;
            switch (r)
            {
            case 1:
                head->information.Apply.type == "applyforin";
                cout << "请输入申请入校时间（xxxx.xx.xx）：";
                cin >> head->information.Apply.Indate;
                break;
            case 2:
                head->information.Apply.type == "applyforout";
                cout << "请输入申请出校时间（xxxx.xx.xx）：";
                cin >> head->information.Apply.Outdate;
                break;
            case 3:
                head->information.Apply.type == "applyforinandout";
                cout << "请输入申请入校时间（xxxx.xx.xx）：";
                cin >> head->information.Apply.Indate;
                cout << "请输入申请出校时间（xxxx.xx.xx）：";
                cin >> head->information.Apply.Outdate;
                break;
            }
            flag2 = true;
            break;
        case 3:
            cout << "请输入申请原因：";
            cin >> head->information.Apply.reason;
            flag2 = true;
            break;
        default:
            cout << "非法输入！";
            break;
        }
        if (flag2)
            break;
    }
}

void check(Student *cnt)
{
    cout << "学院：" << cnt->information.school << "  姓名：" << cnt->information.name << "  学号：" << cnt->information.id
         << "  申请校区：" << cnt->information.Apply.campus << "  申请原因：" << cnt->information.Apply.reason << "  申请类型：" << cnt->information.Apply.type;
    if (cnt->information.Apply.type == "applyforin")
        cout << "申请入校时间：" << cnt->information.Apply.Indate << endl;
    else if (cnt->information.Apply.type == "applyforout")
        cout << "申请出校时间：" << cnt->information.Apply.Outdate << endl;
    else if (cnt->information.Apply.type == "applyforinandout")
        cout << "申请入校时间：" << cnt->information.Apply.Indate << " "
             << "申请出校时间：" << cnt->information.Apply.Outdate << endl;
    cout << "审批状态：";
    if (cnt->information.Apply.check)
        cout << "已通过";
    else
        cout << "未通过";
}