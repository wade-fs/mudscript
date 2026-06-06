//改變使用者的判定為me = environment(this_object()) 與 wear形式為int wear() (參考殺意魔戒) by blazakira 2011/10/11

#include <weapon.h>
#include <ansi.h>
inherit STABBER;
inherit SSERVER;

object user;
int be,bb,k,sp,qq;

void create()
{
//  seteuid(getuid());
  set_name(HIC + "寒冰" + NOR,({"icefan"}));
  set_weight(3500);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "把");
    set("long","此乃至寒之物，能給予敵人致命傷害。\n");
    set("value",20000);
    set("material", "steel");
    set("wield_msg",HIC + "$N" + HIC + "將$n" + HIC + "戴在手上，全身已被寒氣籠罩。\n" + NOR);
    set("unwield_msg",HIC + "$N" + HIC + "運起體內真氣，身旁寒氣瞬時消失無蹤。\n" + NOR);
  }
  init_stabber(80);
  setup();
}

int wield()
{
  int result = ::wield();
  if( query("equipped"))
  {
    user=environment();
    set_heart_beat(1);
  }
  return result;
}

int unequip()
{
  int result = ::unequip();
  if( !query("equipped") )
  {
    set_heart_beat(0);
  }
  return result;
}
/*
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
    message_vision(HIC + "$N將寒冰戴在手上，全身已被寒氣籠罩。\n" + NOR,user);
    set_heart_beat(1);
  }
}
int do_drop(string str)
{
  if(str=="icefan" || str=="all")
    if( query("equipped") )
    {
      message_vision(HIC + "$N運起體內真氣，身旁寒氣瞬時消失無蹤。\n" + NOR,user);
      set_heart_beat(0);
    }
}
int do_give(string str)
{
  if(str=="icefan" || str=="all")
    if( query("equipped") )
    {
      message_vision(HIC + "$N運起體內真氣，身旁寒氣瞬時消失無蹤。\n" + NOR,user);
      set_heart_beat(0);
    }
}
int do_unwield(string str)
{
  if(!user) user=this_player();
  if(!user) set_heart_beat(0);
  if(!user) return 1;
  if(str=="icefan" || str=="all")
    if( query("equipped") )
    {
      message_vision(HIC + "$N運起體內真氣，身旁寒氣瞬時消失無蹤。\n" + NOR,user);
      set_heart_beat(0);
    }
}
int do_auc(string str)
{
  if(str=="icefan" || str=="all")
    if( query("equipped") )
    {
      message_vision(HIC + "$N運起體內真氣，身旁寒氣瞬時消失無蹤。\n" + NOR,user);
      set_heart_beat(0);
    }
}
*/
void heart_beat()
{
  object enemy;
  int i;
/*
  if(!user) user=this_player();
  if(!user) user=previous_object();
  if(!user) return ;
*/
  if( !this_object() || !user || !objectp(user) || !query("equipped") )
  {
    set_heart_beat(0);
    return;
  }
  be = user->query_skill("force",1); //假設為1000
  k = user->query_int(1); //假設為35
  sp = user->query_spi(1); //假設為35
  qq = (k+sp)*(k+sp) / 10; //(35+35)*(35+35)/10=70*70/10=490
  if ( !objectp(user) )
  {
    set_heart_beat(0);
    return;
  }
  if( user->is_fighting() )
  {
    if (be > random(1000))
    {
      enemy=offensive_target(user);
      if(!enemy) return ;
      if( environment(user) == environment(enemy) )
        if( random(300) > enemy->query_skill("dodge") )
        {
          message_vision(HIY + "萬道冰箭由寒冰激射而出，射入$N" + HIY + "各大要穴。\n" + NOR,enemy);
          enemy->receive_damage("kee",qq+be,user); //傷害值估計為1000+490 //因此傷害力主要來自於force lv
          COMBAT_D->report_status(enemy);
        } else
          message_vision(HIW + "萬道冰箭由寒冰激射而出，可惜被$N" + HIW + "內力所融。\n" + NOR,enemy);
    }
  }
  return;
}
