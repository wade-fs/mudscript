// 讓位指令 cinherit.c by Chan 10/31/98
// 提供給幫主讓位用!!!!
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string str)
{
        object  ob;
        if( !str )
                return notify_fail("指令格式﹕cinherit <id>\n");
//本來的程式段有bug,若你要讓位的對像不在同一間房間,會找不到ob,所以做以下的增加by bss 2000,05,06
        if(!ob=present(str,environment(me)))
                return notify_fail("這裡沒有"+str+"這個人!!!\n");
        if( !ob = present(str, environment(me)) || !userp(ob)
         || !living(ob) || ob == me )
                return notify_fail("請不要亂開玩笑。\n");
        if(ob==me) return notify_fail("讓位給自己。\n");
       	if( !me->query("clan" ) )
		return notify_fail( "您沒有加入任何幫派。\n" );
        if( me->query("clan/rank") > 1 )
	        return notify_fail("您無權使用此指令。\n");
        if( ob->query("clan/id") != me->query("clan/id"))
                return notify_fail("您所要讓位的人並非貴幫弟子。\n");
        if( ob->query("combat_exp") < 5000000)
                return notify_fail("對方的江湖歷練不足以勝任此職務。\n");

        ob->set("clan/passwd",me->query("clan/passwd"));
        ob->set("clan/title", me->query("clan/title"));
        ob->set("clan/rank",1);
        CLAN_D->change_clan_master( me->query("clan/id"), ob->query("id") );
        me->delete("clan/passwd");
        me->set("clan/rank", 5);
        me->set("clan/title", "幫派弟子");

	CHANNEL_D->do_channel(me, "ct",
		"\n\t我 -「" + HIW+me->query("clan/title")+HIY + "」鄭重的宣佈……\n\t"+
		"將幫主之位，傳給"+HIC+ob->query("name")+HIY+"。\n" + NOR);
        return 1;

}

int help(object me)
{
        write(@HELP

格式說明:cinherit <ID>

這是將幫主的位置讓給幫派裏的人,記得在讓位之後要把幫派密碼轉給新幫主!!!

HELP    );
        return 1;
}

