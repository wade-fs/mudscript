// show_skill.c
//
//                                              Created by Chan
int main(object me, string arg)
{
        int limit,number;
        string message;
        if( me->query("combat_exp") < 3000000)
                return notify_fail("你的武學修為未達到自創成招的境界!!\n");
        if( !arg )
                return notify_fail("指令格式﹕shown_skill <數字(1~8)>\n");
        number=atoi(arg);
        limit=me->query("hero/limit");
        if(number < 1)
                return notify_fail("招式名稱輸入錯誤哦!!\n");
        if(number > limit)
                return notify_fail("你輸入的數值超過你能力的範圍了!!!\n");
        if(!me->query("hero/action"+arg))
                return notify_fail("你尚未設計自己的招式,請先用design_skill!!設計!!!\n");
        message=me->query("hero/action"+arg);
        write("----------------你所設計的招式敘述如下-------------------\n");
        printf("%s\n",message);
        write("----------------      顯示完成        -------------------\n");
        return 1;
}
int help( object me )
{
        write(@HELP

格式說明:show_skill <數字(1~8)>

此指令用來讓觀看大俠所設計的招式,並且看一下是不是有訊息上的問題!!!
例如:
     show_skill 1
     此時就會顯示出你所設計的第一招skills的敘述!!!!
HELP    );
        return 1;
}
