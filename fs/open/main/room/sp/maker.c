  inherit NPC;
#include <ansi.h>
string refine();

void create()
{
        set_name("煉元子",({"lian yuan","yuan"}));
        set("title",YEL"人間元神"NOR);
        set("age",120);
        set("long","
由於私自精煉人世間的元神，讓本是名登仙列的他，被玉帝給打落人
間；精煉元神乃是對生靈的一種不敬，須以死去亡魂的元神為材料。

精煉的條件：銀行內黃金百兩　＋　元神(數量必須大於精煉級數)

        refine [種類]

種類 : level , force , dodge , move , parry .

\n");
        setup();
}

void init()
{
        add_action("do_refine","refine");
}

int do_refine(string arg)
{
object me,ob;
int a,b,c;
        me = this_player();
        ob = this_object();
        a = (int)me->query("refine/common/soul");
        b = (int)me->query("bank/coin");

        if( me->query_temp("refine/refine") )
                return notify_fail("你正在精煉中...\n");
        if(!arg)
                return notify_fail("你要精煉什麼?\n");
        if(arg != "level" && arg != "force" && arg != "dodge" && arg != "move" && arg != "parry")
                return notify_fail("無法精煉此項級數!\n");

        c = (int)me->query("refine/common/"+arg);

        if( a <= c || b < 1000000 )
                return notify_fail("你銀行內的錢、身上的元神不足!\n");
        
        message_vision(YEL"$N開始精煉$n的元神!\n"NOR,ob,me);
        me->set_temp("refine/refine",arg);
        call_out("refine",1,me);

return 1;
}

string refine()
{
object me;
string arg;
int a;
        me = this_player();
        arg = me->query_temp("refine/refine");
        a = me->query("refine/common/"+arg);


        if( a < 5 )
        {
                message_vision(HIY"$N的"+arg+"級數增加了!\n"NOR,me);
                me->add("refine/common/"+arg,1);
        }
        else if( a == 5 || a == 6 )
        {
                if( random(100) < 50 )
                {
                        message_vision(HIY"$N的"+arg+"精煉成功\!\n"NOR,me);
                        me->add("refine/common/"+arg,1);
                }
                else
                {
                        message_vision(HIR"$N的"+arg+"精煉失敗!\n"NOR,me);
                        me->set("refine/common/"+arg,0);
                }
        }
        else if( a == 7 || a == 8 )
        {
                if( random(100) < 25 )
                {
                        message_vision(HIY"$N的"+arg+"精煉成功\!\n"NOR,me);
                        me->add("refine/common/"+arg,1);
                }
                else
                {
                        message_vision(HIR"$N的"+arg+"精煉失敗!\n"NOR,me);
                        me->set("refine/common/"+arg,0);
                }

        }
        else if( a == 9 )
        {
                if( random(100) < 10 )
                {
                        message_vision(HIY"$N的"+arg+"精煉成功\!\n"NOR,me);
                        me->add("refine/common/"+arg,1);
                }
                else
                {
                        message_vision(HIR"$N的"+arg+"精煉失敗!\n"NOR,me);
                        me->set("refine/common/"+arg,0);
                }

        }
        else if( 10 <= a )
                message_vision(HIY"$N的"+arg+"已經精煉到最大級數!!\n"NOR,me);
        a = a + 1;
        message_vision(HIR"$N損失了100兩黃金、"+a+"個元神!\n"NOR,me);
        me->add("bank/coin",-1000000);
        me->add("refine/common/soul",-a);
        me->delete_temp("refine/refine");
return "\n";
}

