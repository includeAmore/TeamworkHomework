#include "CM.h"

void help() //主菜单
{
    cout << "按下 1:导入信息" << endl;
    cout << "按下 2:学生信息上报管理" << endl;
    cout << "按下 3:学生进出校管理" << endl;
    cout << "按下 4:学校宿舍楼管理" << endl;
    cout << "请输入:";
}

void helpforstu() //学生主菜单
{
    cout << "按下 1:查询个人信息" << endl;
    cout << "按下 2:申请进出校园" << endl;
    cout << "请输入:";
}

void helpofinput() //信息导入模块主菜单
{
    cout << "按下 1:导入学生基本信息" << endl;
    cout << "按下 2:导入学生核酸情况" << endl;
    cout << "按下 3:导入宿舍楼信息" << endl;
    cout << "按下 4:返回上一级" << endl;
    cout << "请输入:";
}

void helpofstudentinput() //导入学生基本信息模块指南
{
    cout << "输入时，请使用‘：’作为信息类与信息间分隔符，请使用‘，’作为信息类间分隔符，请使用‘；’作为信息归属者间分隔符" << endl;
    cout << "例如：姓名：杨子超，学号：XXX，电话：xxx，学院：XXX，寝室楼栋：X区XX，班级号：XX；姓名：段家昂，学号：XXX，学院：XXX" << endl;
    cout << "请输入：";
}

void helpofpcrinput() //导入某一天的核酸情况模块指南
{
    cout << "输入时，请使用‘：’作为信息类与信息间分隔符，请使用‘，’作为信息类间分隔符，请使用‘；’作为信息归属者间分隔符" << endl;
    cout << "例如：姓名：张三，学号：XXX，日期：XXX，结果：阴性； 姓名：李四，学号：XXX，日期：XXX，结果：阳性" << endl;
    cout << "请输入：";
}

void helpofdorminput()
{
    cout << "输入时，请使用‘：’作为信息类与信息间分隔符，请使用‘，’作为信息类间分隔符，请使用‘；’作为信息归属者间分隔符" << endl;
    cout << "例如：楼名：27，区号：东区，容量：100人，楼长：XXX，楼名：26，区号：西区，容量：50人，楼长：XXX；" << endl;
    cout << "请输入：";
}

void helpofsubmit()
{
    cout << "按下 1:查询学生个人信息" << endl;
    cout << "按下 2:查询整个班级今日核酸检测情况" << endl;
    cout << "按下 3:查询学生核酸检测情况" << endl;
    cout << "按下 4:查询学生核酸检测报告到期时间" << endl;
    cout << "按下 5:返回上一级" << endl;
    cout << "请输入:";
}
