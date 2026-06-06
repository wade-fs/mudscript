//御前侍衛「單玉如」by bss
//增加暗殺任務的相關判斷 by blazakira 2011/8/26

#include <ansi.h>
#include <command.h>
#include <combat.h>
#include <skill.h>
inherit NPC;

void create()
{
  set_name("單玉如",({"king guard","guard"}));
  set("title","御前侍衛");
  set("gender","女性");
  set("age",50);
  set("attitude","aggressive");
  set("str",45);
  set("cor",45);
  set("cps",45);
  set("con",45);
  set("kar",45);
  set("clan_kill",1);
  set("del_delay",1);
  set("no_hole",1);
  set("no_plan",1);
  set("long","保護天子的勇猛戰士，盡忠職守，不茍言笑。\n");
  set("class","fighter");
  set("combat_exp",12000000);
  set("force",100000);
  set("max_force",90000);
  set("max_kee",15000);
//  set("kee",15000);
  set("force_factor",40);

  set_skill("dagger",200);
  set_skill("parry",200);
  set_skill("force",200);
  set_skill("dodge",200);
  set_skill("fly-circle",200);
  set_skill("bss-steps",200);
  set_skill("fireforce",200);
  set_skill("bss-parry",200);
  map_skill("dagger","fly-circle");
  map_skill("parry","bss-parry");
  map_skill("dodge","bss-steps");
  map_skill("force","fireforce");

  setup();

  carry_object("/open/capital/room/king/obj/dagger1")->wield();
  add_money("gold",50);
}

void init()
{
  add_action("do_fight", "fight");
  add_action("do_fight", "kill");
  add_action("do_cmd","cmd");
}

int do_cmd(string str) {
  int force;
  object who=this_player();
  object me=this_object();
  if(str=="askgod king" || str=="askgod guard" || str=="askgod king guard") {
    who->start_busy(2);
    message_vision("$N忽然撮嘴尖嘯，發出天魔音，$n當場被嚇得魂飛魄散，內力也因此大打折扣!!\n",me,who);
    force=who->query("force");
    force=force*4/5;
    who->add("force",-force);
    kill_ob(who);
  } else if(str=="bak king" || str=="bak guard" || str=="askgod king guard") {
    who->start_busy(2);
    message_vision("$N忽然撮嘴尖嘯，發出天魔音，$n當場被嚇得魂飛魄散，內力也因此大打折扣!!\n",me,who);
    force=who->query("force");
    force=force*4/5;
    who->add("force",-force);
    kill_ob(who);
  } else if(str=="cmd throw king" || str=="cmd throw kguard" || str=="cmd throw guard") {
    who->start_busy(2);
    message_vision("$N忽然撮嘴尖嘯，發出天魔音，$n當場被嚇得魂飛魄散，內力也因此大打折扣!!\n",me,who);
    force=who->query("force");
    force=force*4/5;
    who->add("force",-force);
    kill_ob(who);
  }
  return 1;
}

int do_fight(string arg)
{
  object who;
  who = this_player();
  if( !arg || (arg!="guard" && arg!="king") )
    return notify_fail("你想攻擊誰﹖\n");
  else {
    kill_ob(who);
  }
  return 1;
}

void heart_beat()
{
  int force,i,j;
  object *target;
  object me=this_object();
  if(!me || !environment(me) ) return ;
  if( query("kee") < 0 || query("gin") < 0 || query("gen") < 0 ) {
    me->die();
    return ;
  }
  else if( me->query_temp("unconcious") == 1 ) return ;
  if(me->is_fighting())
  {
    target=me->query_enemy();
    if( 50 > random(100)){
      me->delete_busy();
      message_vision("$N舒展了一下筋骨，瞬間生龍活虎了起來!!\n",me);
    }
    i=sizeof(target);
    if( 2 > random (100))
    {
      message_vision("$N大喝一聲「吸星大法」，開始吸收每個人的功\力!!\n",me);
      for(j=0;j<i;j++)
      {
        force=target[j]->query("force");
        force=force*4/5;
        target[j]->add("force",-force);
        me->add("force",force);
        message_vision("$N的內力被$n的吸星大法所吸，竟被吸掉了八成之多!!\n",target[j],me);
        COMBAT_D->repore_status(target[j]);
        target[j]->start_busy(1);
      }
      message_vision("$N施展完吸星大法，內力大增!!\n",me);
    }
  }
  ::heart_beat();
}

void die()
{
  int i,j;
  mixed enemy;
  object room;

  object winner = query_temp("last_damage_from");
  room= environment(this_object());
  enemy=all_inventory(room);
  i=sizeof(enemy);
  tell_object(users(),HIR + "\n

御前侍衛單玉如用盡了最後一絲力氣說道：「皇上，微臣無能，無法再保護皇上，
                                     唯有以死謝罪!!」
\n\n" + NOR);
   message("room", HIR + "單玉如在臨死之前，竟然用了陰葵派禁斷秘技「玉石俱焚」，身體爆作滿天精血粉碎，
身體奇跡似得無影無蹤!!
\n" + NOR, enemy);
  for(j=0;j<i;j++)
  {
    if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j]) && enemy[j]->query("id")!="king guard" && enemy[j]->query("id")!="king")
    {
//      enemy[j]->add("kee",-1000);
      enemy[j]->receive_damage("kee",1000,this_object());
      enemy[j]->start_busy(1);
      message_vision("$N閃躲不急，被$n這臨死前的一擊擊中，受了重傷，搖搖欲墜!!\n",enemy[j],this_object());
      COMBAT_D->report_status(enemy[j]);
    }
  }
  :: die();
}
