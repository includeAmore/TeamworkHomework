#include "CM.h"
extern string timeNow = "000"; //目前时间
extern int timeStampNow = 0;   //当前的时间戳
extern int NumofStudents;
int CheckLeapYear(int beginYear, int internal)
{

    int Count = 0;
    int endYear = beginYear + internal;
    for (size_t i = beginYear; i <= endYear; ++i)
    {
        if ((i % 400 == 0) || ((i % 4 == 0) && (i % 100 != 0)))
        {
            ++Count;
        }
    }

    return Count;
}
string TimeStamp_Convert(uint64_t time)
{
    //时间戳转换当前年月日    格林威治时间：1970-1-1 8:00
    stringstream stream;
    string _year;
    string _month;
    string _day;
    string _hour;
    string res;

    int yearCount = 0;
    int monthCount = 0;
    int dayCount = 0;
    int hourCount = 0;

    int gap = 8;
    int DayInternal = 24;                       //一天
    int CommonYearInternal = DayInternal * 365; //平年
    int LeapYearInternal = DayInternal * 366;   //闰年

    vector<int> VecMonth =
            {0,
             DayInternal * 31,
             DayInternal * (31 + 28),
             DayInternal * (31 + 28 + 31),
             DayInternal * (31 + 28 + 31 + 30),
             DayInternal * (31 + 28 + 31 + 30 + 31),
             DayInternal * (31 + 28 + 31 + 30 + 31 + 30),
             DayInternal * (31 + 28 + 31 + 30 + 31 + 30 + 31),
             DayInternal * (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31),
             DayInternal * (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30),
             DayInternal * (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31),
             DayInternal * (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30),
             DayInternal * (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31)};

    if (time < CommonYearInternal)
    {
        // 1970年之内
        yearCount = 0;
        for (size_t i = 1; i < VecMonth.size(); ++i)
        {
            if (time <= VecMonth[i])
            {
                monthCount = i;
                break;
            }
            continue;
        }
        // time = VecMonth[monthCount] - time;
        int tmp = monthCount - 1;
        time = time - VecMonth[tmp];
        // day
        time = (time + gap) / DayInternal;
        dayCount = time + 1;
    }
    else
    {
        yearCount = time / CommonYearInternal;
        time = time - yearCount * CommonYearInternal;
        for (size_t i = 1; i < VecMonth.size(); ++i)
        {
            if (time <= VecMonth[i])
            {
                monthCount = i;
                break;
            }
            continue;
        }
        int tmp = monthCount - 1;
        time = time - VecMonth[tmp];

        // day
        dayCount = (time + gap) / DayInternal + 1;
        time = time - (dayCount - 1) * DayInternal + 8;

        int leapyearCount = 0;
        if (leapyearCount = CheckLeapYear(1970, yearCount)) //检测年份区间内有无闰年
        {
            dayCount -= leapyearCount;
        }
        yearCount += 1970;
        int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (yearCount % 4 == 0 && yearCount % 100 != 0 || yearCount % 400 == 0)
            months[2] = 29;
        if (dayCount < 1)
        {
            dayCount += months[--monthCount];
        }
        // hour
        hourCount = time;
    }

    stream << yearCount;
    stream >> _year;
    stream.clear();
    stream << monthCount;
    stream >> _month;
    stream.clear();
    stream << dayCount;
    stream >> _day;
    stream.clear();
    stream << hourCount;
    stream >> _hour;
    if (monthCount < 10)
        _month = "0" + _month;
    if (dayCount < 10)
        _day = "0" + _day;
    if (hourCount < 10)
        _hour = "0" + _hour;
    res = _year + ":" + _month + ":" + _day + ":" + _hour;
    return res;
}
void setTimeNow()
{
    cout << "输入时间戳请按1，输入时间请按2:";
    cin.clear();
    uint64_t timeStampNow;
    bool flag = false;
    int n;
    while (true)
    {
        cin >> n;
        cin.clear();
        switch (n)
        {
            case 1:
                cout << "请输入当前时间戳：";
                cin >> timeStampNow;
                setTimeNow(::timeNow, timeStampNow);
                flag = true;
                break;
            case 2:
                cout << "请输入当前时间（输入样例：1970.1.1.8）：";
                getline(cin, ::timeNow);
                setTimeNow(::timeNow, timeStampNow);
                flag = true;
                break;
            default:
                cout << "\n输入错误！请重新输入：";
                cin.clear();
                break;
        }
        if (flag)
            break;
    }
}
uint64_t setTimePCR(string &timeNow)
{
    int year, month, day, hour;
    string time;
    stringstream stream;
    vector<string> splitSemicolon = Util::split(timeNow, "."); // 以英文分号为分隔符进行对字符串进行分割
    stream << splitSemicolon[0];
    stream >> year;
    stream.clear();
    stream << splitSemicolon[1];
    stream >> month;
    stream.clear();
    stream << splitSemicolon[2];
    stream >> day;
    stream.clear();
    stream << splitSemicolon[3];
    stream >> hour;
    stream.clear();
    int yearInternal = year - 1970;
    int plus = CheckLeapYear(1970, yearInternal - 1);
    uint64_t timeStampN = (yearInternal * 365 + plus) * 24;
    int dayInternal = 0;
    int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        months[2] = 29;
    for (int i = 1; i < month; ++i)
    {
        dayInternal += months[i];
    }
    dayInternal += day - 1;
    hour = hour - 8;
    timeStampN += dayInternal * 24 + hour;
    return timeStampN;
}
void setTimeNow(string &timeNow, uint64_t timeStampN) //设置当前时间函数
{
    int year, month, day, hour;
    string time;
    //    if (timeStampN != 0) //如果调用的时候传入了时间戳，就直接用时间戳转换
    //    {
    //        timeNow = TimeStamp_Convert(timeStampN);
    //        timeStampNow = timeStampN;
    //        return;
    //    }

    stringstream stream;
    vector<string> splitSemicolon = Util::split(timeNow, "."); // 以英文分号为分隔符进行对字符串进行分割
    stream << splitSemicolon[0];
    stream >> year;
    stream.clear();
    stream << splitSemicolon[1];
    stream >> month;
    stream.clear();
    stream << splitSemicolon[2];
    stream >> day;
    stream.clear();
    stream << splitSemicolon[3];
    stream >> hour;
    stream.clear();
    int yearInternal = year - 1970;
    int plus = CheckLeapYear(1970, yearInternal - 1);
    timeStampN = (yearInternal * 365 + plus) * 24;
    int dayInternal = 0;
    int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        months[2] = 29;
    for (int i = 1; i < month; ++i)
    {
        dayInternal += months[i];
    }
    dayInternal += day - 1;
    hour = hour - 8;
    timeStampN += dayInternal * 24 + hour;
    timeStampNow = timeStampN;
    cout << "\n设置成功！当前时间为：" << timeNow << "，当前时间戳为（单位：小时）：" << timeStampN<<endl;
}

void classSearchPCR(Student *head)
{
    cout << "请输入班级号（如需返回上一级请输入‘-1’）：";
    string classNum;
    cin >> classNum;
    if (classNum == "-1")
        ;
    else
    {
        Student *cnt = head->next;
        int numOfClass = 0, numOfDone = 0;
        while (cnt != NULL)
        {
            if (cnt->information.classnum == classNum)
            {
                ++numOfClass;
                if (timeNow.substr(0, 10) == cnt->information.PCR.date.substr(0, 10)) //这个判断条件根据日期输入格式而定
                {
                    ++numOfDone;
                }
            }
            cnt = cnt->next;
        }
        cout << classNum << "班" << timeNow.substr(0, 10) << "应做" << numOfClass << "人，实做" << numOfDone << "人。" << endl;
    }
}

void dormSearchPCR(Student *head)
{
    cout << "请输入宿舍楼栋号（格式：X区XX）（如需返回上一级请输入‘-1’）：";
    string dormitory;
    cin >> dormitory;
    if (dormitory == "-1")
        ;
    else
    {
        Student *cnt = head->next;
        int numOfDorm = 0, numOfDone = 0;
        while (cnt != NULL)
        {
            if (cnt->information.address == dormitory)
            {
                ++numOfDorm;
                if (timeNow.substr(0, 10) == cnt->information.PCR.date.substr(0, 10)) //这个判断条件根据日期输入格式而定
                {
                    ++numOfDone;
                }
            }
            cnt = cnt->next;
        }
        cout << dormitory << "宿舍楼" << timeNow.substr(0, 10) << "应做" << numOfDorm << "人，实做" << numOfDone << "人。" << endl;
    }
}

void SearchExpire(Student *head)
{
    Student *cnt = head->next;
    string id;
    while (true)
    {
        cin.clear();
        cnt = head->next;
        cout << "请输入学号（如需返回上一级请输入‘-1’）：";
        cin >> id;
        if (id == "-1")
            break;
        else
        {
            while (cnt != NULL)
            {
                if (cnt->information.id == id)
                    break;
                cnt = cnt->next;
            }
            if (cnt == NULL)
                cout << "\n学号不存在！请重新输入" << endl;
            else
            {
                int duration = timeStampNow - cnt->information.PCR.timeStamp;
                cout << "\n您上次核酸时间为" << cnt->information.PCR.date << "，";
                if (duration > 72)
                    cout << "您的核酸已经过期！请尽快进行核酸检验！";
                else
                    cout << "距您核酸检测报告到期还有" << 72 - duration << "小时！";
            }
        }
    }
}

void searchforstu(Student *head)
{
    string s;
    while (true)
    {
        cout << "请输入学号：";
        cin >> s;
        bool flag = false; //匹配学号
        Student *pp = head;
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
            cout << "学院：" << pp->information.school << endl;
            cout << "姓名：" << pp->information.name << endl;
            cout << "学号：" << pp->information.id << endl;
            cout << "电话：" << pp->information.telephone << endl;
            cout << "寝室楼栋：" << pp->information.address << endl;
            cout << "班级号：" << pp->information.classnum << endl;
            cout << "体温：" << pp->information.temperature << endl;
            cout << "疫苗注射情况：" << pp->information.vaccine << endl;
            cout << "最近一次核酸检测日期：" << pp->information.PCR.date << endl;
            cout << "最近一次核酸检测结果：" << pp->information.PCR.consequence << endl;
        }
        else
        {
            cout << "查无此人，请重新输入！" << endl;
        }
    }
}

void getTimeNow()
{
    SYSTEMTIME sys;
    GetLocalTime(&sys);
    string time,_year,_month,_day,_hour;
    stringstream stream;
    stream.clear();
    stream<<sys.wYear;
    stream>>_year;
    stream.clear();
    stream<<sys.wMonth;
    stream>>_month;
    stream.clear();
    stream<<sys.wDay;
    stream>>_day;
    stream.clear();
    stream<<sys.wHour;
    stream>>_hour;
    time = _year+"."+_month+"."+_day+"."+_hour;
    ::timeNow = time;
    setTimeNow(timeNow,0);
}
