// design_final_skill.c
//
//                                              Created by Chan
#include <ansi.h>
int done_setskill(string str, string text);

int main(object me, string arg)
{
        int limit,number,value;
        if( !me->query("final/ko_king"))
                return notify_fail("你並沒有資格使用終極拳勢!!!!\n");
        if( me->query("combat_exp") < 5000000)
                return notify_fail("你的武學修為未達到能使用終極拳勢的境界!!\n");
        if( !arg )
                return notify_fail("指令格式﹕design_final_skill <數字(1~4)>\n");
        value = me->query("functions/final-unarmed/level");
        value=(value / 20)+1;
        if(value > 4)
         value =4;
        number=atoi(arg);
        limit=me->query("final/limit");
        if(value > limit)
         me->add("final/limit",1);
        limit=me->query("final/limit");
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

        this_player()->set("final/action"+str,text);
        write("ok!!!設計完成!!!請用show_skill的指令看是否有問題!!!\n");
        write("注意!!!在設計自己的招式時不能有\" 符號!!!\n");
          return 1;
}

int help( object me )
{
        write(@HELP

格式說明:design_final_skill <數字(1~4)>

此指令用來讓武者設計終極拳勢的招式
例如:
     desgin_final_skill 1
     此時就會要你輸入招式的長敘述!!!!
     注意：長敘述的內容不能有 " 也不能太長(超過十五行!!!),否則會造成錯誤!!!

HELP    );
        return 1;
}
