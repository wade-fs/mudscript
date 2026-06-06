// thunder_hat.c
#include <ansi.h>
inherit EQUIP;
object me=this_player();
void create()
{
        set_name("散雷帽", ({ "thunder hat", "hat" }) );
        set_weight(2200);
                if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一頂可以散掉雷擊時傷害的帽子。\n");
                set("unit", "頂");
                set("value",220);
                set("material", "cloth");
                set("armor_type", "head");
                set("armor_prop/armor", 6);
                // 要散雷就要靠這個啦, 散雷效果在 0-100, hehe
        set("thunder",100);
        }
        setup();
}

void init()
{
     add_action("do_wear","wear");
     add_action("do_remove","remove");
}

int do_wear(string str)
{
     if( str=="all" || str=="thunder hat" || str == "hat" )
     {
        ::wear();
        if( query("equipped") )
        {
           if(!me) me=environment();
           if(!living(me)) me=this_player();
           if(!me) me=previous_object();
           if(me)
           me->set_temp("thunder",20);
           message_vision(HIW + "$N戴上一頂散雷帽。\n" + NOR,me);
        }
     }
}


int do_remove(string str)
{
     if( str=="thunder hat" || str=="all" || str=="hat" ) 
     {
        if( query("equipped") )
        {
           if(!me) me=environment();
           if(!living(me)) me=this_player();
           if(!me) me=previous_object();
           if(me)
           me->delete_temp("thunder");           
        }
     }
}   
