//copy from cage,re-edit from ccat
// 增加少林廚藝學院的quest相關 2010/09/08 by blazakira
//排版與增加死亡訊息 by blazakira 2011/10/12

inherit NPC;

void create()
{
  set("title","金毛獅王");
  set_name("謝遜", ({"shie-chiun","chiun"}));
  set("family/family_name","金刀門");
  set("age",45);
  set("long","明教四大護法之一，橫掃江湖，手中殺人無數之「金毛獅王」謝遜。\n");
  set("gender","男性");
  set("str",30);
  set("con",30);
  set("cor",30);
  set("cps",30);
  set("env/連擊",1);
  set("max_kee",50000);
  set("kee",50000);
  set("max_gin",50000);
  set("gin",50000);
  set("max_sen",50000);
  set("sen",50000);
  set("combat_exp",1500000);
  set("max_force",50000);
  set("force",50000);
  set("force_factor",15);
  set_skill("dodge",200);
  set_skill("parry",200);
  set_skill("move",200);
  set_skill("force",200);
  set_skill("black-steps",150);
  set_skill("unarmed",200);
  set_skill("blade",200);
  set_skill("fast-blade",150);
  set_skill("gold-blade",150);
  map_skill("blade","fast-blade");
  map_skill("parry","gold-blade");
  map_skill("move","black-steps");
  map_skill("dodge","black-steps");
  set("chat_chance_combat",25);
  set("chat_msg_combat",({
    "謝遜說：小輩無禮，受死吧!!\n",
    (: perform_action("blade.fast-dest") :),
  }));
  set_temp("apply/armor",150);
  set_temp("apply/damage",150);
  set("ann_die",1);
  setup();
  carry_object("/open/main/obj/kd_blade")->wield();
  carry_object("/open/gsword/obj/sick_item");
  add_money("gold",25);
}

int accept_kill(object me)
{
  object room,ob;
  ob = this_object();
  room = environment(me);
  if( !room->query("no_really") )
  {
    room->set("no_really",1);
  } else {
    ob->set("no_really",1);
  }
//  call_out("change",1,me);
  return 1;
}

int accept_fight(object me)
{
  object room,ob;
  ob = this_object();
  room = environment(me);
  if( !room->query("no_really") )
  {
    room->set("no_really",1);
  } else {
    ob->set("no_really",1);
  }
//  call_out("change",1,me);
  return 1;
}

void heart_beat()
{
  object env,mob,*enemy,target;
  int i,kee;
  mapping exit;
  string *exit_name;

  mob = this_object();
  env = environment(mob);
  if(!mob || !env ) return ;
  if( query("kee") < 0 || query("gin") < 0 || query("gen") < 0 ) {
    mob->die();
    return ;
  }
  else if( mob->query_temp("unconcious") == 1 ) return ;

  if( !query("wield") )
  {
    set("wield",1);
    command("wield all");
  }

  if( random(100) < 30 )
  {
    enemy=mob->query_enemy();
    if( i = sizeof(enemy) ) {
      target=enemy[random(i)];
      kee = target->query("max_kee") * 0.3;
      if( env == environment(target) )
      {
        message_vision("謝遜突然打出七傷拳之摧心斷脈，擊中了$N！\n",target);
        target->receive_damage("kee",(int)kee,mob);
        COMBAT_D->report_status(target);
      }
    }
  }

  if((mob->query("kee")<mob->query("max_kee")*0.3) && (random(100) < 30) )
  {
    tell_room(environment(), name()+"吞下一粒大還丹。\n");
    mob->receive_curing("kee",5000);
    mob->receive_heal("kee",5000);
    mob->receive_curing("sen",2000);
    mob->receive_heal("sen",2000);
    mob->receive_curing("gin",2000);
    mob->receive_heal("gin",2000);
  }

  if((mob->query("kee")<mob->query("max_kee")*0.3) && (random(100) < 30) )
  {
    exit = env->query("exits");
    exit_name = keys(exit);
    i = random(sizeof(exit_name));
    command(exit_name[i]);
    i = random(sizeof(exit_name));
    command(exit_name[i]);
  }

  set_heart_beat(1);
  ::heart_beat();
}

void die()
{
  object ob,wp1,wp2,wp3,room,winner = query_temp("last_damage_from");
  int j;

  if(!winner)
  {
    ::die();
    return ;
  }
  room = environment(winner);
  ob = this_object();
  winner->set_temp("kill_shion",1);
  if( !ob->query("no_really") )
  {
    wp1 = present("dragon blade",ob);
    wp1->set_temp("quests/bonze/online","ok"); //避免玩家不斷庫存本道具致他人無法解謎的情況 by blazakira
    if( wp1 ) wp1->set_name("屠龍刀",({"dragon blade","blade"}) );
  } else {
    wp1 = present("dragon blade",ob);
    if( wp1 ) destruct(wp1);
    wp3=new("/open/main/obj/kd_blade_f");
    wp3->set_temp("quests/bonze/online","ok"); //避免玩家不斷庫存本道具致他人無法解謎的情況 by blazakira
    wp3->move(ob);
  }
  ::die();
}
