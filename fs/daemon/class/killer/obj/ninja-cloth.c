//npc專用隱藏身份的裝備
//並改變wear形式為int wear() (參考殺意魔戒) by blazakira 2011/7/20

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
  set_name(MAG"伊賀忍者服" NOR ,({"ninja-cloth","cloth"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "件");
    set("value",10000);
    set("material","gem");
    set("no_sell",1);
    set("no_auc",1);
    set("no_give",1);
    set("no_put",1);
//    set("no_drop",1);
    set("no_get",1);
    set("no_steal",1);
    set("no_save",1);
    set("need_class","killer");
    set("armor_prop/armor", 10);
    set("wear_msg",MAG"$N"MAG"穿起$n"MAG"，將自己容貌隱藏起來。\n"NOR);
    set("unequip_msg",MAG"$N"MAG"脫下$n"MAG"，露出原來面貌。\n"NOR);
  }
  setup();
}

int wear()
{
  object user;
  int k,result = ::wear();
  if( query("equipped"))
  {
    user=environment();
    if (user->query("ninja/change") != 1)
    {
      user->set("ninja/old_id",user->query("id"));
      user->set("ninja/old_name",user->query("name"));
      user->set("ninja/old_nickname",user->query("nickname"));
      user->set("ninja/old_title",user->query("title"));
      user->set("id","japan ninja");
//      user->set("name","忍者");
      user->set_temp("apply/name",({"忍者"}));
      user->delete("nickname");
      user->set("title",GRN"伊賀流忍者"NOR);
      user->set("ninja/change",1);
    }
    set_heart_beat(1);
  }
  return result;
}

int unequip()
{
  object user=environment();
  int result = ::unequip();
  if( !query("equipped") )
  {
    user->set("id",user->query("ninja/old_id"));
//    user->set("name",user->query("ninja/old_name"));
    user->delete_temp("apply/name");
    user->set("nickname",user->query("ninja/old_nickname"));
    user->set("title",user->query("ninja/old_title"));
    user->delete("ninja/change");
    set_heart_beat(0);
  }
  return result;
}

/*
int init()
{
  add_action("do_wear","wear");
  add_action("do_remove","remove");
}

int do_wear(string str,object user)
{
  ::wear();
  if( query("equipped") )
  {
    user = environment();
    message_vision(MAG"$N穿起伊賀忍者服, 將自己容貌隱藏起來。\n"NOR,user);
    if (user->query("ninja/change") != 1)
    {
      user->set("ninja/old_id",user->query("id"));
      user->set("ninja/old_name",user->query("name"));
      user->set("ninja/old_nickname",user->query("nickname"));
      user->set("ninja/old_title",user->query("title"));
      user->set("id","japan ninja");
      user->set("name","忍者");
      user->delete("nickname");
      user->set("title",GRN"伊賀流忍者"NOR);
      user->set("ninja/change",1);
    }
    set_heart_beat(1);
  }
}

int do_remove(string str)
{
  object user = environment();
  if(str=="ninja-cloth" || str=="all" || str=="cloth")
    if( query("equipped") )
    {
      message_vision(MAG"$N脫下伊賀忍者服, 露出原來面貌。\n"NOR,user);
      user->set("id",user->query("ninja/old_id"));
      user->set("name",user->query("ninja/old_name"));
      user->set("nickname",user->query("ninja/old_nickname"));
      user->set("title",user->query("ninja/old_title"));
      user->delete("ninja/change");
      set_heart_beat(0);
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
      message_vision(MAG"\n$N雙眼泛紅，全身散發出死亡般的氣息。\n"NOR,user);
      message_vision(MAG"\n～ ～  "HIW"天  魔  解  體  大  法  "MAG"～ ～\n"NOR,user);
      message_vision(HIW"\n$N生命力瞬間爆增數萬，功\力徒增數倍!!\n"NOR,user);
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
