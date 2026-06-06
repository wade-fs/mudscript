#include <ansi.h>
#include <armor.h>
inherit HANDS;
object me=this_player();
void create()
{
        set_name(MAG"噬魂手套"NOR,({"soul hands","hands"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "雙");
        set("value",10000);
        set("long","傳說中會隨時吸取殺氣的手套，有著強大的反噬能力。\n");
        set("material","steel");
        set("no_sell",1);
        }
        setup();
        this_object()->set("armor_prop/armor", 15);
        this_object()->set("armor_prop/attack", 15);
        this_object()->set("armor_prop/dodge",5);
        this_object()->set("armor_prop/parry",5);
        this_object()->set("armor_prop/dagger",10);
        this_object()->set("armor_prop/throwing",10);
        set_heart_beat(1);
}
void heart_beat()
{
if(!environment(this_object())) return ;
me = environment(this_object());
 if( me->is_fighting() && query("equipped"))
 {
 if(random(100) > 80 && me->query("bellicosity") > 100)
   {
message_vision(RED"\n$N的手掌突然發出紅光, $N瞬時精神一振, 但臉上殺氣卻漸漸退去。\n"NOR,me);
me->receive_curing("kee",100);
me->receive_heal("kee",100);
me->add("atman",300);
me->add("bellicosity",-30);
if (me->query("atman") > 500000) me->set("atman",500000);
   }
 }
 
  if( !me->is_fighting() && query("equipped"))
 {
 if(random(100) > 50 && me->query("bellicosity") > 100 && me->query("atman") < 300000)
   {
me->add("atman",30);
me->add("bellicosity",-10);
   }
 }
}
