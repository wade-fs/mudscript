//將戰功紀錄增加被打倒的npc名字 以便debug 與 receive_xxx增加攻擊方參數 by b;azakira 2011/10/31

#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;

void create()
{
  set_name("封圓真",({"funyun jen","funyun","jen"}));
  set("long",@LONG
聚靈八傑之一，魔刀的後起之秀，自小就潛心練武，所才已將
刀法練至絕妙之境，自小孤苦無依的他，性格較為沉靜，甚是
得到莊主的青睞。
LONG);
  set("gender","男性");
  set("class","blademan");
  set("nickname",NOR+BLU"隱"HIB"刀"NOR+BLU"魂"HIB"絕"NOR);
  set("title",HIB"魂靈八傑"NOR);
  set("family/family_name","魔刀門");
  set("combat_exp",10000000);
  set("attitude","friendly");
  set("score",1000000);
  set("bellicosity",20000);
  set("potential",50000);
  set("age",40);

  set("str", 35);
  set("cor", 35);
  set("cps", 35);
  set("int", 35);
  set("spi", 35);
  set("per", 35);
  set("kar", 35);
  set("con", 35);

  set("env/魔性六斬","YES");
  set("env/邪刀連擊","YES");
  set("env/get_mblade","YES");

  set("force",50000);
  set("max_force",30000);
  set("mana",20000);
  set("max_mana",20000);
  set("atman",20000);
  set("max_atman",20000);
  set("force_factor", 15);

  set("max_kee",50000);
  set("max_gin",50000);
  set("max_sen",50000);

  set_skill("blade",150);
  set_skill("dragon-blade",120);
  set_skill("move",120);
  set_skill("dodge",120);
  set_skill("parry",120);
  set_skill("force",250);
  set_skill("fireforce",250);
  map_skill("parry","dragon-blade");
  map_skill("blade","dragon-blade");
  map_skill("force","fireforce");

  set("functions/mdragon-dest/level",100);
  set("functions/power-dest/level",100);
  set("functions/mk-blade/level",100);
  set("functions/busy/level",100);
  set("functions/powerup/level",100);
  set("functions/enforceup/level",100);
  set("functions/addbasic/level",100);
  set("functions/addblade/level",100);
  set("functions/badup/level",50);
  set("functions/hurtkee/level",100);
  set("functions/losehurt/level",100);
  set("functions/healup/level",100);
  set("functions/gold-fire/level",90);

  set("chat_chance_combat",50);
  set("chat_msg_combat", ({
    (: perform_action, "power-dest" :),
  }));

  set("eight-ghost",1);
  set("quest/gold-fire",1);
  set("quest/new_gold_fire",1);
  set("mk-blade",1);
  set("m_blade",1);
  set("clan_kill",1);
  set("no_hole",1);
  set("no_plan_follow",1);
  set("no_mount",1);
  set_temp("armor_vs_force",300);
  set_temp("no_die_soon",1);
  set_temp("rob",1); 
  set_temp("no-plan",1);
  set_temp("mount",1);
  set_temp("follow",1);
  set_temp("speed",1);
  set_temp("empty",1);
  set_temp("false",1);
  set_temp("lock-link",1);
  set_temp("roared",1);
  set_temp("six-hurt",1);

  set_temp("apply/armor",150);
  set_temp("apply/attack",50);
  set_temp("apply/damage",50);
  set_temp("apply/defense",150);

  set("ann_die",1);
  setup();

  add_money("cash",3);
  carry_object("/autoload/sky/peace_neck")->wear();
  carry_object("/open/magic-manor/obj/evil-gwe-blade")->wield();
}

int accept_kill(object ob)
{
  object me=this_player();
  kill_ob(ob);
  command("wield all");
  command("wear all");
  command("perform blade.mdragon-dest");
  return 1;
}

void greeting(object ob)
{
//  ob=this_player();

  if( !wizardp(ob) )
  {
    command("say 有我在此守衛，休想進入天靈地界!!");
    kill_ob(ob);
  }
  set_heart_beat(1);
  return;
}

void heart_beat()
{
  object me=this_object(),*enemy;
  int i,j;
  if( !me || !environment() ) return ;
  if( query("kee") < 0 || query("gin") < 0 || query("gen") < 0 ) {
    me->die();
    return ;
  }
  else if( me->query_temp("unconcious") == 1 ) return ;
  enemy=me->query_enemy();
  i=random(sizeof(enemy));

  if( me->is_fighting() )
  {
    if( !enemy[i] ) return ;
  
    if( random(100) < 10 )
    {
      if( environment(me) == environment(enemy[i]) )
      {
        message_vision(HIB"\n$N"HIB"眼神暴露出一股陰狠氣勁，祭起一式攻擊招式\n\n    "HIM"『"HIC"魂轉天地間 "HIW"≡◎≡"HIC" 陰魂不散式"HIM"』"HIB"\n\n瞬間$n"HIB"無從躲避只覺一陣陰風襲來已然中招!!\n"NOR,me,enemy[i]);
        enemy[i]->receive_wound("kee",random(300)+300,me);
        enemy[i]->receive_damage("sen",random(300)+100,me);
        enemy[i]->receive_damage("gin",random(300)+100,me);
        enemy[i]->apply_condition("ghost",enemy[i]->query_condition("ghost")+5);
        COMBAT_D->report_status(enemy[i]);
      }
    }

    if( ( me->query("kee") < 85000 ) && ( random(100) < 50 ) )
    {
      tell_room(environment(), BLU+name()+NOR+BLU"汲取散落在這空間的陰氣來為自己撫平創傷。\n"+NOR);
      me->receive_curing("kee",random(200)+500);
      me->receive_heal("kee",random(200)+500);
      me->receive_curing("gin",500);
      me->receive_heal("gin",500);
      me->receive_curing("sen",500);
      me->receive_heal("sen",500);
    }
  }

  if( !me->query_temp("secondary_weapon") )
  {
    command("wield all");
    command("wear all");
  }

  if( me->query("title") != "聚靈八傑" )
  {
    me->set("title",HIC"聚靈八傑"NOR);
  }

  if( !me->is_fighting() )
  {
    if( !me->query_temp("del") )
    {
      command("perform blade.mk-blade");
    }
    if( me->query("bellicosity") < 15000 )
    {
      me->add("bellicosity",5000);
    }
    if( !me->query_temp("addblade") )
    {
      command("addblade");
    }
//    if( !me->query_temp("powerup") )
//    {
//      command("powerup");
//    }
    if( !me->query_temp("addbasic") )
    {
      command("addbasic");
    }
    if( !me->query_temp("losehurt") )
    {
      command("losehurt");
    }
    if( !me->query_temp("addenforce") )
    {
      command("enfup");
    }
    if( !me->query_temp("focuskee") )
    {
      command("exert focuskee");
    }
  }

  if( me->is_fighting() )
  {
    if( !me->query_temp("badup") && !me->is_busy() )
    {
      command("badup");
    }
    if( !me->query_temp("hurtkee") && !me->is_busy() )
    {
      command("hurtkee");
    }
    if( !me->query_temp("addbusy") && !me->is_busy() )
    {
      command("busy");
    }
    if( !me->is_busy() )
    {
      command("perform blade.mdragon-dest");
    }
  }

  if( !is_fighting() ) 
  {
    if( query("force") < 39000 )
      command( "ex 300" );
    if( query("eff_kee") < query("max_kee") )
    { 
      command( "10 exert heal" );
      command( "10 exert heal" );
      if( !me->query_temp("heal") )
      {
        command("healup");
      }
    }
    if( query("gin") < query("eff_gin") )
    {
      me->receive_curing("gin",350);
      me->receive_heal("gin",350);
    }
    if( query("kee") < query("eff_kee") )
      command( "5 exert recover" );
    if( query("sen") < query("eff_sen") )
    {
      me->receive_curing("sen",350);
      me->receive_heal("sen",350);
    }
  }

//  set_heart_beat(1);
  ::heart_beat();
}

void die()
{
  object me,winner,room;

  me=this_object();
  winner=query_temp("last_damage_from");
  room = environment(me);

  if(!winner)
  {
    ::die();
    destruct(me);
    return ;
  }

  tell_object(winner,"\n你打敗"+me->name()+"得到三十點戰功\!!\n"NOR,winner,me);
  write_file("/log/get_warp_e",sprintf("%s(%s) 打敗"+me->name()+"得到三十點戰功\於 %s\n",winner->name(1),winner->query("id"),ctime(time())));
  winner->add("war_score",30);
  message_vision(HIR"\n$n承受不住攻擊，消失在一陣光芒之中，魂魄化身為一顆封魂石!!\n"NOR,winner,me);
  {
    new("/open/magic-manor/ghost/obj/stone03")->move(environment(me));
  }

  room->set("no_reset",1);

  destruct(me);

  ::die();
}
