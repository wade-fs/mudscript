// badhelmet.c by Oda
#include <ansi.h>
#include <armor.h>
inherit HEAD;
object me=this_player();
void create()
{
        set_name("邪惡頭盔", ({"bad helmet", "helmet"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long", "這是一頂集惡念所作成的頭盔，強大的邪惡力量連雷公都不敢來找碴。\n");
        set("unit", "頂");
        set("value", 100000);
        set("material", "steel");
        set("armor_prop/armor", 10);
        set("thunder", 100);
        set("wear_msg", "$N慢慢的將$n戴上，臉上的表情突然變得猙獰了起來。\n");
        set("unequip_msg", "$N將$n脫掉，神情逐漸恢復自然。\n");
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
     if( str=="all" || str=="bad helmet" || str == "helmet" )
     {
        ::wear();
        if( query("equipped") )
        {
           if(!me) me=environment();
           if(!living(me)) me=this_player();
           if(!me) me=previous_object();
           if(me)
           me->set_temp("thunder",30);
           message_vision(HIW"$N慢慢的將邪惡頭盔戴上，臉上的表情突然變得猙獰了起來。\n"NOR,me);        }
     }
}


int do_remove(string str)
{
     if( str=="bad helmet" || str=="all" || str=="helmet" ) 
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

