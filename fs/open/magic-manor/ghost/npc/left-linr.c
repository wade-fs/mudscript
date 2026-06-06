//將戰功紀錄增加被打倒的npc名字 以便debug 與 receive_xxx增加攻擊方參數 by b;azakira 2011/10/31

#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;

void create()
{
  set_name("左靈兒",({"left linr","left","linr"}));
  set("long",@LONG
聚靈山莊之二聖，修為算的上是高手級的，要處理許多莊內的
事務，所以平日較疏於外功的修練，內功卻是比八傑還要高深
莫測。功力和右靈晉不相伯仲。
LONG);
  set("gender","女性");
  set("class","fighter");
  set("nickname",NOR+RED"昊" + HIY + "日"NOR+RED"烈" + HIY + "焰" + NOR);
  set("title",HIB + "魂靈火聖" + NOR);
  set("family/family_name","瀧山派");
  set("combat_exp",12000000);
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

  set("env/瀧山連擊","YES");

  set("force",200000);
  set("max_force",20000);
  set("mana",20000);
  set("max_mana",20000);
  set("atman",20000);
  set("max_atman",20000);
  set("force_factor", 15);

  set("s_kee",1000);
  set("max_s_kee",1000);
  set("sec_kee","tiger");

  set("max_kee",120000);
  set("max_gin",120000);
  set("max_sen",120000);

  set_skill("haoforce", 350);
  set_skill("dodge", 120);
  set_skill("force",450);
  set_skill("move", 120);
  set_skill("parry", 120);
  set_skill("unarmed",200);
  set_skill("lungshan-mob",100);
  set_skill("henma-steps",120);
  set_skill("fire-kee",120);

  map_skill("dodge","henma-steps");
  map_skill("move","henma-steps");
  map_skill("parry","fire-kee");
  map_skill("unarmed","lungshan-mob");
  map_skill("force","haoforce");

  set("functions/kang_kee/level",100);
  set("functions/kang_power/level",100);

  set("eight-ghost",1);
  set("is_mob",1);
  set("kang-power",1);
  set("super_fire",1);
  set("fire_strike",1);
  set("quests/sunfire",1);
  set("quest/gold-fire",1);
  set("quest/new_gold_fire",1);
  set("clan_kill",1);
  set("no_hole",1);
  set("no_plan_follow",1);
  set("no_mount",1);
  set("can_use_cloud",1);
  set_temp("fan-finger",5000);
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

  add_money("cash",2);
  carry_object("/autoload/sky/peace_neck")->wear();
  carry_object("/daemon/class/fighter/figring")->wield();
  carry_object("/open/magic-manor/ghost/obj/trigram-pill")->set_amount(1);
}

int accept_kill(object ob)
{
  object me,right;
  me=this_object();
  right=present( "right lingin",environment(me) );

  if( !present( "right lingin",environment(me)) || !living(right) ) return 1;
  else {
    message_vision(HIY + "\n左靈兒說：$N想死就來嚐嚐我和右靈晉的極招吧！\n" + NOR,me);
    right->kill_ob(ob);
    me->delete_temp("is_busy");
    me->delete_busy();
    command("wield all");
    command("wear all");
    command("perform force.kang_kee");
    return 1;
  }
}

void greeting(object ob)
{
  ob=this_player();
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
  int i;
  if( !me || !environment() ) return ;
  if( query("kee") < 0 || query("gin") < 0 || query("gen") < 0 ) {
    me->die();
    return ;
  }
  else if( me->query_temp("unconcious") == 1 ) return ;
  enemy = me->query_enemy();
  i = random( sizeof(enemy) );

  if( me->is_fighting() )
  {
    if( !enemy[i] ) return ;
  
    if( random(100) < 10 )
    {
      if( environment(me) == environment(enemy[i]) )
      {
        message_vision(HIB + "\n$N" + HIB + "眼神暴露出一股陰狠氣勁，祭起一式攻擊招式\n\n    " + HIM + "『" + HIC + "魂轉天地間 " + HIW + "≡◎≡" + HIC + " 陰魂不散式" + HIM + "』" + HIB + "\n\n瞬間$n" + HIB + "無從躲避只覺一陣陰風襲來已然中招!!\n" + NOR,me,enemy[i]);
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
      me->receive_curing("kee",random(500)+500);
      me->receive_heal("kee",random(500)+500);
      me->receive_curing("gin",500);
      me->receive_heal("gin",500);
      me->receive_curing("sen",500);
      me->receive_heal("sen",500);
    }
  }
/*
  if( !me->query_temp("weapon") )
  {
    command("wield all");
    command("wear all");
  }
*/
  if( me->is_fighting() && me->query("s_kee") > 0 )
  {
    if( !enemy[i]->query_temp("tiger") && !enemy[i]->query_temp("dragon") )
    {
      if( random(2) == 1 )
      {
        me->set("sec_kee","tiger");
        command("cmd usekee "+enemy[i]->query("id"));
      } else {
        me->set("sec_kee","dragon");
        command("cmd usekee "+enemy[i]->query("id"));
      }
    } else {
      if( !enemy[i]->query_temp("dragon") )
      {
        me->set("sec_kee","dragon");
        command("cmd usekee "+enemy[i]->query("id"));
      }
      if( !enemy[i]->query_temp("tiger") )
      {
        me->set("sec_kee","tiger");
        command("cmd usekee "+enemy[i]->query("id"));
      }
    }
  }

  if( me->query("force_factor") < 90 )
  {
    me->set("force_factor",90);
  }

  if( !me->is_fighting() && !me->query_temp("kang-power") )
  {
    command("perform haoforce.kang_power");
  }

  if( me->query("force") < 100000 )
  {
    me->set("force",100000);
  }

  if( me->is_fighting() && !me->is_busy() )
  {
    if( random(5) == 2 )
    {
      command("perform force.kang_kee");
    }
  }

  if( me->is_busy() && me->is_fighting() )
  {
    if( 35 > random(100) )
    {
      message_vision(HIW + "\n只見$N暴起所有" + HIY + "真氣內勁" + HIW + "，$N全身籠罩在一股" + HIC + "綻藍氣勁" + HIW + "中，赫然已解開身上被封的穴道。\n" + NOR,this_object());
      delete_busy();
    }
  }

  if( !is_fighting() ) 
  {
    if( query("eff_kee") < query("max_kee") )
    { 
      command( "10 exert heal" );
      command( "10 exert heal" );
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
  object me,winner,room,ob;

  me = this_object();
  winner = query_temp("last_damage_from");
  room = environment(me);
  
  if(!winner)
  {
    ::die();
    return ;
  }

  tell_object(winner,"\n你打敗"+me->name()+"得到五十點戰功\!!\n" + NOR,winner,me);
  write_file("/log/get_warp_e",sprintf("%s(%s) 打敗"+me->name()+"得到五十點戰功\於 %s\n",winner->name(1),winner->query("id"),ctime(time())));
  winner->add("war_score",50);

  if( !room->query("mob-die") )
  {
    message_vision(HIR + "\n$n承受不住攻擊，消失在一陣光芒之中，魂魄化身為一顆封魂石!!\n" + NOR,winner,me);
    ob=new("/open/magic-manor/ghost/obj/stone09");
    ob->move(environment(me));
    room->set("mob-die",1);
  } else {
    message_vision(HIR + "\n$n被右靈晉所化的封魂石吸入，化為封魂石的一部份了!!\n" + NOR,winner,me);
    present("fon stone",environment(me))->check();
  }

  room->set("no_reset",1);

  destruct(me);

  ::die();
}
