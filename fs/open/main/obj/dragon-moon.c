//2003/1/14增加心跳攻擊 --by kalin
#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit SSERVER;
object user=this_player();
int be,bb,k,sp,qq;
void create()
{
        seteuid(getuid());
        set_name(HIC + "青龍偃月刀" + NOR,({"dragon-moon"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
        set("long","這便是傳說中武聖關羽所用的寶刀, 據說有青龍之魂棲息在內 .\n");
                set("value",20000);
                set("material", "steel");
				set("material", "blacksteel");   
                set("weapon_prop/blade",10);
                init_blade(120);
        }
        setup();
}
void init()

{
     add_action("do_drop","drop");
     add_action("do_auc","auc");
     add_action("do_wield","wield");
     add_action("do_give","give");
     add_action("do_unwield","unwield");
}
int do_wield(string str)
{
     ::wield();
     if( query("equipped") )
     {
        user = this_player();
message_vision("$N拿著" + HIC + "青龍偃月刀" + NOR + ",$N覺得渾身充滿了神力\n" + NOR,user);
        set_heart_beat(1);
     }
}
int do_drop(string str)
{
   if(str=="dragon-moon" || str=="all")
     if( query("equipped") )
     {
message_vision("$N將手中的" + HIC + "青龍偃月刀" + NOR + "插入腰間的刀鞘。\n",user);
        set_heart_beat(0);
     }
}
 int do_give(string str)
{
  if(str=="dragon-moon" || str=="all")
     if( query("equipped") )
     {
message_vision("$N將手中的" + HIC + "青龍偃月刀" + NOR + "插入腰間的刀鞘。\n",user);
        set_heart_beat(0);
     }
}
int do_unwield(string str)
{
  if(!user) user=this_player();
   if(!user) set_heart_beat(0);
    if(!user) return 1;
   if(str=="dragon-moon" || str=="all")
     if( query("equipped") )
     {
message_vision("$N將手中的" + HIC + "青龍偃月刀" + NOR + "插入腰間的刀鞘。\n",user);
        set_heart_beat(0);
     }
}
int do_auc(string str)
{
  if(str=="dragon-moon" || str=="all")
     if( query("equipped") )
     {
message_vision("$N將手中的" + HIC + "青龍偃月刀" + NOR + "插入腰間的刀鞘。\n",user);
        set_heart_beat(0);
     }
}
void heart_beat()
{
  object enemy;
  int i;
  if(!user) user=this_player();
  if(!user) user=previous_object();
  if(!user) return ;
  if ( !objectp(user) )
        {

        set_heart_beat(0);
        return;
        }
 if( user->is_fighting() && query("equipped") )
  {
  if (random(10)==5)
    {
     enemy=offensive_target(user);
     if(!enemy) return ;
     if( environment(user) == environment(enemy) )
     message_vision(HIG + "\n青龍之魂" + HIW + "從" + HIC + "青龍偃月刀" + HIW + "裡流竄出來！\n" + NOR,enemy);  
      if( random(5)>1  )
     {
      message_vision(HIG + "只見$N面露異色，似乎受創不淺!!\n" + NOR,enemy);  
	  enemy->receive_wound("kee",random(250)+250);
      COMBAT_D->report_status(enemy, 0);
     }else
      message_vision(HIC + "只見$N身手不凡，一下躲過了青龍魂魄。\n" + NOR,enemy);
	  }
  }
  return;
}

