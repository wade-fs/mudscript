//將戰功紀錄增加被打倒的npc名字 以便debug 與 receive_xxx增加攻擊方參數 by b;azakira 2011/10/31

#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;

string magic1();
string magic2();
string magic3();
string magic4();

void create()
{
  set_name("嫵情生",({"funchin sen","funchin","sen"}));
  set("long",@LONG
聚靈八傑之一，舞步堪稱是獨步天下，舞姿更是美倫美喚，絕
妙無比，看似弱不禁風的模樣，功夫可是到達了精妙無比的地
步。
LONG);
  set("gender","女性");
  set("class","dancer");
  set("nickname",NOR+MAG"夢"HIM"舞"NOR+MAG"玄"HIM"翔"NOR);
  set("title",HIB"魂靈八傑"NOR);
  set("family/family_name","夜夢小築");
  set("combat_exp",10000000);
  set("attitude","friendly");
  set("score",1000000);
  set("bellicosity",3000);
  set("age",40);

  set("str", 35);
  set("cor", 35);
  set("cps", 35);
  set("int", 35);
  set("spi", 35);
  set("per", 35);
  set("kar", 35);
  set("con", 35);

  set("force",100000);
  set("max_force",20000);
  set("mana",20000);
  set("max_mana",20000);
  set("atman",100000);
  set("max_atman",50000);
  set("force_factor", 15);

  set("max_kee",100000);
  set("max_gin",100000);
  set("max_sen",100000);

  set_skill("unarmed",150);
  set_skill("dreamforce",250);
  set_skill("dreamdance",120);
  set_skill("paull-steps",120);
  set_skill("dremagic",100);
  set_skill("move",120);
  set_skill("dodge",120);
  set_skill("magic",120);
  set_skill("parry",120);
  set_skill("force",250);
  map_skill("magic","dremagic");
  map_skill("dodge","paull-steps");
  map_skill("force","dreamforce");
  map_skill("move","paull-steps");
  map_skill("unarmed","dreamdance");

  set("spells/reflection/level",100);
  set("spells/confuse/level",100);
  set("spells/fireball/level",100);
  set("spells/thunder/level",100);
  set("spells/fdragon/level",100);
  set("spells/firedance/level",100);
  set("spells/dreamwings/level",100);
  set("spells/absorb/level",100);
  set("spells/hellfire/level",100);
  set("spells/dreamcure/level",100);
  set("functions/rainbow-steps/level",100);

  set("chat_chance_combat",50);
  set("chat_msg_combat", ({
    (: magic1 :),
    (: magic2 :),
    (: magic3 :),
    (: magic4 :),
  }));

  set("eight-ghost",1);
  set("allow_hellfire",1);
  set("allow_fdragon",1);
  set("get_dan_sp",1);
  set("adv_dancer",1);
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

  set_temp("apply/armor",150);
  set_temp("apply/attack",50);
  set_temp("apply/damage",50);
  set_temp("apply/defense",150);

  set("ann_die",1);
  setup();

  add_money("cash",3);
  carry_object("/autoload/sky/peace_neck")->wear();
  carry_object("/open/magic-manor/obj/fire-color-ribbon");
}

int accept_kill(object ob)
{
  kill_ob(ob);
  command("wield all");
  command("conjure fdragon");
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

  if( !me->query_temp("weapon") )
  {
    command("wield all");
    command("wear all");
  }

  if( me->is_fighting() )
  {
    if( !enemy[i] ) return ;

    if( !me->is_busy() && enemy[i]->is_busy() )
    {
      command("conjure thunder");
      command("conjure fireball");
    }
    if( !me->is_busy() && !enemy[i]->is_busy() )
    {
      command("conjure thunder");
      command("conjure fireball");
      command("conjure confuse");
    }
    if( !me->query_temp("ref_shield") )
    {
      me->delete_busy();
      me->delete_temp("is_busy");
      command("conjure reflection");
    }
    if( !me->query_temp("ranbow-steps") && !me->is_busy() )
    {
      me->delete_busy();
      me->delete_temp("is_busy");
      command("perform dodge.ranbow-steps");
    }
    if( !me->query_temp("mana_shield") && me->query("atman") > 5000 && me->query("kee") < 50000  )
    {
      me->delete_busy();
      me->delete_temp("is_busy");
      command("conjure dreamwings");
    }
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

  if( !me->is_fighting() )
  {
    if( !me->query_temp("ref_shield") )
    {
      command("conjure reflection");
    }
    if( !me->query_temp("mana_shield") && me->query("kee") < 50000 )
    {
      me->delete_busy();
      me->delete_temp("is_busy");
      command("conjure dreamwings");
    }
    if( !me->query_temp("ranbow-steps") )
    {
      me->delete_busy();
      me->delete_temp("is_busy");
      command("perform dodge.rainbow-steps");
    }
  }

  if( !is_fighting() ) 
  {
    if( query("force") < 39000 )
      command("ex 270");
    if( query("atman") < 39000 )
      command("res 300");
    if( query("eff_kee") < query("max_kee") )
      command("conjure dreamcure");
    me->receive_curing("kee",250);
    me->receive_heal("kee",250);
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
  if( !present("fon stone",me) )
  {
    new("/open/magic-manor/ghost/obj/stone06")->move(environment(me));
  }

  room->set("no_reset",1);

  destruct(me);

  ::die();
}

string magic1()
{
  command("conjure confuse");
  return "\n";
}

string magic2()
{
  command("conjure confuse");
  return "\n";
}

string magic3()
{
  command("conjure hellfire");
  return "\n";
}
string magic4()
{
  command("conjure fdragon");
  return "\n";
}
