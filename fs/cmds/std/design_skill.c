// design_skill.c
//
//                                              Created by Chan
#include <ansi.h>
int done_setskill(string str, string text);

int main(object me, string arg)
{
        int limit,number;
        if( me->query("combat_exp") < 3000000)
                return notify_fail("你的武學修為未達到自創成招的境界!!\n");
       if(!me->query("hero/set")) me->set("hero/set",1);
        if( !arg )
                return notify_fail("指令格式﹕design_skill <數字(1~8)>\n");
        number=atoi(arg);
        limit=me->query("hero/limit");
        if(number < 1)
                return notify_fail("招式名稱輸入錯誤哦!!\n");
        if(number > limit)
                return notify_fail("你輸入的數值超過你能力的範圍了!!!\n");
        write("符號說明：$N 代表自己 $n 代表敵方 $l 代表敵方被攻擊的部位 !!\n");
        write("例如：$N 使出絕招，一拳擊向 $n 的 $l的地方!!!!\n");
        me->edit( (: done_setskill,arg :) );
        return 1;
}

int done_setskill(string str,string text)
{

        this_player()->set("hero/action"+str,text);
        write("ok!!!設計完成!!!請用show_skill的指令看是否有問題!!!\n");
        write("注意!!!在設計自己的招式時不能有\" 符號!!!\n");
          return 1;
}

int help( object me )
{
        write(@HELP

格式說明:design_skill <數字(1~8)>

此指令用來讓大俠設計在戰鬥時可以使用出自己的招式的訊息!!!!
例如:
     desgin_skill 1
     此時就會要你輸入招式的長敘述!!!!
     完成之後,在set my_skill在戰鬥時就會自動用出自己所設計的招式!!!!
     注意：長敘述的內容不能有 " 也不能太長(超過十五行!!!),否則會造成錯誤!!!

HELP    );
        return 1;
}
