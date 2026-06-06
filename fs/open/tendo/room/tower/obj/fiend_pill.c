// made by neverend
//非賣品, 只供鎖妖塔之殿主級npc攜帶
inherit COMBINED_ITEM;
#include <ansi.h>
void create()
{
        set_name(HIM"修羅鎮精丹"NOR, ({"fiend pill","pill"}) );
        set("long",
        "鎖妖塔之冥殿修羅用其妖力聚合而成，能療復所有的精力。\n");
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
        int maxgin;
        object ob,me=this_player();
        maxgin=me->query("max_gin",1);
        if( !arg )                      return 0;
        arg=lower_case(arg);
        if( !ob = present(arg,me) )     return 0;
        if( ob != this_object() )       return 0;
        message_vision(
                "$N吃下一粒"HIM"修羅鎮精丹"NOR"，精力變的旺盛了。\n", me);
        me->set("gin",maxgin);
        me->set("eff_gin",maxgin);
        add_amount(-1);
        return 1;
        
}


