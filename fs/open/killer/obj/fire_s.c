#include <weapon.h>
#include <ansi.h>

inherit SWORD;
object user;
int be,bb,inn,sp,qq;
void create()
{
        seteuid(getuid());
        set_name(HIR"火魔劍"NOR,({"iceger"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
        set("long","此乃至熱之物,能給予敵人致命傷害．\n");

                set("value",10000);
                set("material", "steel");
                set("no_sell",1);
        }
        init_sword(255);
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
        message_vision(HIR"$N將火魔劍握在手上，全身已被炎氣籠罩。\n"NOR,user);
        set_heart_beat(1);
     }
}
int do_drop(string str)
{
   if(str=="iceger" || str=="all")
     if( query("equipped") )
     {
        message_vision("$N你居然拋棄火魔神-伊佛力特？",user);
        set_heart_beat(0);
     }
}
 int do_give(string str)
{
  if(str=="iceger" || str=="all")
     if( query("equipped") )
     {
        message_vision("$N運起體內熊熊真氣,手中破冰以消失無蹤。\n",user);
        set_heart_beat(0);
     }
}
int do_unwield(string str)
{
   if(str=="iceger" || str=="all")
     if( query("equipped") )
     {
        message_vision(HIY"$N畫出一道劍花，劍歸劍盒。"NOR,user);
        set_heart_beat(0);
     }
}
int do_auc(string str)
{
  if(str=="iceger" || str=="all")
     if( query("equipped") )
     {
        message_vision(HIY"$N畫出一道劍花,手中火魔劍消失無蹤。"NOR,user);
        set_heart_beat(0);
     }
}

void heart_beat()
{
  object *enemy,who;
  int i;
//  be = user->query("bellicosity",1);
  be = 1000;
  bb = (be/20);
  inn= user->query_int(1);
  sp = user->query_spi(1);
qq=(inn +sp) *2 /30;
 if ( !objectp(user) )
        {
        set_heart_beat(0);
        return;
        }
 if( user->is_fighting() && query("equipped") )
  {
    if( be > random(300) )
    {
     enemy=user->query_enemy();
     i=random(sizeof(enemy));
     if( environment(user) == environment(enemy[i]) )
      if( random(-1) > enemy[i]->query_skill("dodge") )
     {
      message_vision(HBRED"火魔神--*伊佛力特*，回復原形,直接衝向$N，瞬間陷入一片火海!!!"NOR,enemy[i]);
      enemy[i]->receive_damage("kee",qq+bb,user);
      COMBAT_D->report_status(enemy[i], 0);
     }else
      message_vision("一道火焰由火魔劍激發而出,可惜被$N體內真氣所阻擋..\n",enemy[i]);
     }
  }
  return;
}
