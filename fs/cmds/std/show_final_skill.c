// show_final_skill.c
//
//                                              Created by Chan
int main(object me, string arg)
{
        int limit,number;
        string message;
        if( !me->query("final/ko_king"))
                return notify_fail("你並沒有資格使用終極拳勢!!!!\n");
        if( me->query("combat_exp") < 5000000)
                return notify_fail("你的武學修為未達到自創成招的境界!!\n");
        if( !arg )
                return notify_fail("指令格式﹕shown_final_skill <數字(1~4)>\n");
        number=atoi(arg);
        limit=me->query("final/limit");
        if(number < 1)
                return notify_fail("招式名稱輸入錯誤哦!!\n");
        if(number > limit)
                return notify_fail("你輸入的數值超過你能力的範圍了!!!\n");
        if(!me->query("final/action"+arg))
                return notify_fail("你尚未設計自己的招式,請先用design_skill!!設計!!!\n");
        message=me->query("final/action"+arg);
        write("----------------你所設計的招式敘述如下-------------------\n");
        printf("%s\n",message);
        write("----------------      顯示完成        -------------------\n");
        return 1;
}
int help( object me )
{
        write(@HELP

格式說明:show_final_skill <數字(1~4)>

此指令用來讓觀看武者觀看所設計的終極拳勢的招式在訊息上是不是有問題!!!!
例如:
     show_final_skill 1
     此時就會顯示出你所設計的第一招skills的敘述!!!!
HELP    );
        return 1;
}
