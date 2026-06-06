#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("獨角虎的頭", ({ "tiger-head","head"}) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                set("long","這是兇殘的獨角虎的頭,可以用<cut>切下它的角(cornu)...\n");
                set("value", 0);
        }
}
void init()
{
    add_action("do_cut","cut");
}
int do_cut(string arg)
{
    object me, ob;

    me=this_player();

    if(!arg || arg != "cornu")
        return notify_fail("你要切什麼東西？\n");
    if(!me->query_temp("find_cornu")==1 && ob->query_temp("for_cut")==1)
        return notify_fail("你還要切什麼？這是[獨角虎]的頭ㄟ...\n");
        write("你隨手撿了把刀，「唰」的一聲，把獨角虎頭的角給切了下來...\n" + NOR);
        ob=new("/open/doctor/obj/cornu");
        ob->move(me);
        ob->set_temp("for_cut",1);
        me->delete_temp("find_cornu");
        me->set_temp("get_cornu",1);
        return 1;
}

