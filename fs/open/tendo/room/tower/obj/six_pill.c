// made by neverend
//非賣品, 只供鎖妖塔之殿主級npc攜帶
inherit COMBINED_ITEM;
#include <ansi.h>
void create()
{
        set_name(HIG + "六合聚神丹" + NOR, ({"six pill","pill"}) );
        set("long",
        "鎖妖塔之冥殿修羅用其妖力聚合而成，能療復所有的神冥。\n");
        set("unit", "盒");
        set("base_unit", "粒");
        set("value", 30000);
        set("base_weight", 50);
        set_amount(1);
        setup();
}

void init()
{
        if( this_player()==environment() )
                add_action("eat_pill", "eat");
}

int eat_pill(string arg)
{
        int maxsen;
        object ob,me=this_player();
        maxsen=me->query("max_sen",1);
        if( !arg )                      return 0;
        arg=lower_case(arg);
        if( !ob = present(arg,me) )     return 0;
        if( ob != this_object() )       return 0;
        message_vision(
                "$N吃下一粒" + HIG + "六合聚神丹" + NOR + "，神冥變的清爽無礙了。\n", me);
        me->set("sen",maxsen);
        me->set("eff_sen",maxsen);
        add_amount(-1);
        return 1;
        
}


