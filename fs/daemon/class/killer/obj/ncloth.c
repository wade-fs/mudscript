//作為開放給玩家使用的裝備 但是取消隱藏身份的功能 by blazakira 2011/7/28
// 原則上可以偷竊 作為降低npc防禦的手段 但是不能存(int query_autoload(){return 0;}) by blazakira 2011/7/28

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
  set_name(MAG + "忍者夜行衣" + NOR ,({"ninja cloth","cloth"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "件");
    set("value",10000);
    set("material","gem");
//    set("long","高級忍者所穿的夜行衣，可以將自己身分隱藏(hide)起來，具有提昇戰鬥力的功\能與激發天魔解體的能力。\n");
    set("long","高級忍者所穿的夜行衣，具有提昇戰鬥力的功\能與激發天魔解體的能力。\n");
    set("no_sell",1);
    set("no_auc",1);
    set("no_give",1);
    set("no_put",1);
//    set("no_drop",1);
    set("no_get",1);
    set("no_steal",1);
    set("no_save",1);
    set("need_class","killer");
    set("armor_prop/armor", 30);
    set("armor_prop/attack",40);
    set("armor_prop/defense",40);
    set("armor_prop/move",10);
    set("armor_prop/dodge",10);
    set("armor_prop/dagger",10);
    set("armor_prop/throwing",10);
//    set_heart_beat(1);
  }
  setup();
}

int wear()
{
  int ret = ::wear();
  if( query("equipped"))
  {
    set_heart_beat(1);
  }
  return ret;
}

int unequip()
{
  int ret = ::unequip();
  if( !query("equipped") )
  {
    set_heart_beat(0);
  }
  return ret;
}
/*
int init()
{
  add_action("do_wear","hide");
  add_action("do_remove","remove");
}

int do_wear(string str,object user)
{
  if( query("equipped") && !str)
  {
    user = environment();
    set_heart_beat(1);
    if (user->query("ninja/change") != 1)
    {
      message_vision(MAG + "$N穿起忍者夜行衣將自己容貌隱藏起來。\n" + NOR,user);
      user->set("ninja/old_id",user->query("id"));
      user->set("ninja/old_name",user->query("name"));
      user->set("ninja/old_nickname",user->query("nickname"));
      user->set("ninja/old_title",user->query("title"));
      user->set("id","dark ninja");
      user->set("name","黑影");
      user->delete("nickname");
      user->set("title",MAG + "暗黑忍者" + NOR);
      user->set("ninja/change",1);
      return 1;
    }
  }
}

int do_remove(string str)
{
  object user = environment();
  if(str=="ninja-cloth" || str=="all" || str=="cloth")
    if( query("equipped") )
    {
      message_vision(MAG + "$N脫下忍者夜行衣, 露出原來面貌。\n" + NOR,user);
      user->set("id",user->query("ninja/old_id"));
      user->set("name",user->query("ninja/old_name"));
      user->set("nickname",user->query("ninja/old_nickname"));
      user->set("title",user->query("ninja/old_title"));
      user->delete("ninja/change");
    }
}
*/
void heart_beat()
{
  object user = environment();
  if( !objectp(user) || !query("equipped") )
  {
    set_heart_beat(0);
    return;
  }
  if( user->is_fighting() && query("equipped"))
  {
    object room;
    room=environment(user);
    if( random(100) > 95 && user->query_temp("evil-body")==1 )
    {
      message_vision(MAG + "\n$N雙眼泛紅, 全身散發出死亡般的氣息。\n" + NOR,user);
      message_vision(MAG + "\n～ ～  " + HIW + "天  魔  解  體  大  法  " + MAG + "～ ～\n" + NOR,user);
      message_vision(HIW + "\n$N生命力瞬間爆增數萬, 功\力徒增數倍!!\n" + NOR,user);
      user->add("max_kee",50000);
      user->add("max_gin",50000);
      user->add("max_sen",50000);
      user->add("force",20000);
      user->set("eff_kee",user->query("max_kee"));
      user->set("eff_gin",user->query("max_gin"));
      user->set("eff_sen",user->query("max_sen"));
      user->set("kee",user->query("max_kee"));
      user->set("gin",user->query("max_gin"));
      user->set("sen",user->query("max_sen"));
      user->add_temp("apply/attack",2000);
      user->add_temp("apply/defense",2000);
      user->add_temp("apply/force",500);
      user->add_temp("apply/dagger",500);
      user->add_temp("apply/throwing",500);
      user->set("force_factor",50);
      user->delete_temp("evil-body");
      user->set_temp("body_change",1);
    }
  }
}

int query_autoload()
{
  return 0;
}
