#include <armor.h>
#include <ansi.h>
inherit CLOTH;
object me=this_player();
int cor;
int ekee=me->query("max_kee",1);
void create()
{
        set_name( HIY "仙劍聖鎧" NOR ,({"kensai armor","armor"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value",0);
                set("long","大劍師龍鐵心的傑作，對劍士而言..是極佳的選擇。\n");
                set("material","crimsonsteel");
                set("armor_prop/armor",27);
                set("no_sell",1);
                set("no_auc",1);
                set("no_give",1);
                set("no_put",1);
                set("no_drop",1);
                set("no_get",1);
        }
        setup();
            this_object()->set("armor_prop/sword",7);
                this_object()->set("armor_prop/parry", 10);
                this_object()->set("armor_prop/move", 5);
}
void init()
{
     add_action("do_wear","wear");
     add_action("do_remove","remove");

}
int do_wear(string str)
{
     ::wear();
     if( query("equipped") )
     {
        cor = me->query_skill("sword");
      cor = cor*2;
message_vision(HIW"$N穿上了聖鎧後彷彿劍聖附體。\n"NOR,me);
        set_heart_beat(1);
     }
}
int do_remove(string str)
{
   if(str=="kensai armor" || str=="all" || str=="armor")
     if( query("equipped") )
     {
message_vision(YEL"$N脫下了聖鎧頓時..對劍的感覺似乎漸漸疏遠。\n"NOR,me);
        set_heart_beat(0);
     }

}

void heart_beat()
{
  if( !objectp(me) )
        {
        set_heart_beat(0);
        return;
        }
  if( me->is_fighting()&&query("equipped")&&me->query("eff_kee")!=ekee )
  {
    if( random(100) > 40)
    {
    me->receive_curing("kee",cor*4);
    me->receive_heal("kee",cor*4);
message_vision(HIY+"\n聖鎧發出耀眼光芒，$N頓時覺的神清氣爽，暢快無比。\n"+NOR,me);
    }
  }
  return;
}
