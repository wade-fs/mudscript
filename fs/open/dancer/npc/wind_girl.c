//排版 by blazakira 2011/10/12

#include <ansi.h>
inherit NPC;

string magic();

void create()
{
  set_name("風靈兒",({"wind girl","girl"}));
  set("long","她是鏡月島四天女之一個風靈使，其美貌自然不是一般凡間
所能相比較，傳聞中其特技『風嚎』威力十分強大!!\n");
  set("gender","女性");
  set("class","dancer");
  set("family/family_name","夜夢小築");
  set("nickname","四天女");
  set("title",HIY + "風靈使" + NOR);
  set("combat_exp",5000000);
  set("attitude","heroism");
  set("age",20);
  set("str", 34);
  set("cor", 30);
  set("cps", 50);
  set("per", 24);
  set("int", 40);
//  set("kee",100000);
  set("max_kee",100000);
//  set("gin",100000);
  set("max_gin",100000);
//  set("sen",100000);
  set("max_sen",100000);
  set("atman",30000);
  set("max_atman",30000);
  set("mana",30000);
  set("max_mana",30000);
  set("force",30000);
  set("max_force",30000);
  set_skill("array",60);
  set_skill("parry",60);
  set_skill("spells",50);
  set_skill("magic",120);
  set_skill("cure",60);
  set_skill("force",60);
  set_skill("literate",70);
  set_skill("move",90);
  set_skill("dodge",100);
  set_skill("sword",50);
  set_skill("unarmed",70);
  set_skill("paull-steps",130);
  set_skill("dremagic",100);
  set_skill("dreamforce",90);
  set_skill("dreamdance",100);
  map_skill("magic","dremagic");
  map_skill("dodge","paull-steps");
  map_skill("force","dreamforce");
  map_skill("move","paull-steps");
  map_skill("unarmed","dreamdance");
  set_temp("apply/armor",70);
  set("get_dan_sp",1);
  set("functions/rainbow-steps/level",100);
  set("spells/reflection/level",100);
  set("spells/confuse/level",100);
  set("spells/fireball/level",100);
  set("spells/thunder/level",100);
  set("spells/firedance/level",100);
  set("spells/dreamwings/level",100);
  set("force_factor",30);
//  set("ann_die",1);
  setup();
  carry_object("/open/dancer/obj/yuaboots.c")->wear();
  carry_object("/open/dancer/obj/maple_ribbon.c")->wield();
  carry_object("/open/dancer/obj/yuawaist.c")->wear();
  set("chat_chance_combat",70);
  set("chat_msg_combat",({
    (: magic :),
  }));
}

void heart_beat()
{
  object ob=this_object();
  mixed enemy;
  int i,j;
  if(!ob || !environment(ob) ) return ;
  if( query("kee") < 0 || query("gin") < 0 || query("gen") < 0 ) {
    ob->die();
    return ;
  }
  else if( ob->query_temp("unconcious") == 1 ) return ;
  enemy=all_inventory(environment(ob));
  i=sizeof(enemy);
  if( is_fighting() ) {
    if(random(100)>70) {
      message_vision(HIY + "風靈兒使出了本身絕學『風嚎』，現場的風靈們受到了風靈兒的感招颳起了一陣大風!!\n" + NOR,ob);
      if(random(5)>2)
      {
        message_vision(HIY + "你一個閃躲不及，整個人受到了風靈們的重擊!!\n" + NOR,this_object());
        for(j=0;j<i;j++)
        {
          if (!enemy[j]->is_fighting() && enemy[j]->is_character() && !enemy[j]->is_corpse()
              && living(enemy[j]) && enemy[j]!=ob)
          {
            message_vision(HIY + "風靈們把你給吹走了!!\n" + NOR,ob);
            enemy[j]->move("/open/common/room/inn");
            enemy[j]->receive_damage("kee",1000,ob);
            COMBAT_D->report_status(enemy[j]);
//            enemy[j]->add("kee",1000);
          }
        }
      }
      else
        message_vision("風靈們過於活潑以至於無法配合風靈兒。\n" + NOR,ob);
    }
    if(query_temp("ref_shield")!=1)
    {
      if(ob->is_busy() && random(5)==2) ob->delete_busy();
      command("conjure reflection");
    }
    if(!ob->query_temp ("rainbow-steps", 1))
      command("perform dodge.rainbow-steps");
  }
  else
  {
    if(query_temp("ref_shield")!=1 && ((query_temp("final-attack") && !query_temp("roared")) || ob->query("kee") < ob->query("max_kee")))
    {
      command("conjure reflection");
      if(!ob->query_temp ("rainbow-steps", 1))
        command("perform dodge.rainbow-steps");
    }
  }
  :: heart_beat();
}

string magic()
{
  command("conjure confuse");
  command("conjure fireball");
  command("conjure reflection");
//  command("conjure firedance");
  command("conjure thunder");
//  command("conjure dreamwings");
  return "\n";
}

int accept_fight(object ob)
{
//  object me=this_player();
  command("say 小女子怎是您的對手呢??\n");
  command("conjure reflection");
//  command("conjure dreamwings");
  command("conjure confuse");
  message_vision( this_object()->name()+"一付弱不禁風的樣子。\n",ob);
  call_out("combat_exp",1,ob);
  return 1;
}

int accept_kill(object ob)
{
//  object me=this_player();
  command("say 沒想到你忍心欺負弱小女子，那我就不客氣了!!!\n");
  command("conjure reflection");
//  command("conjure dreamwings");
  command("conjure confuse");
  call_out("combat_exp",1,ob);
  return 1;
}

void greeting(object me)
{
//  object me=this_player();
  object ob=this_object();
  if( me->query("combat_exp") >= ob->query("combat_exp") )
  {
    command("conjure reflection");
  }
}

int combat_exp(object me)
{
//  object me=this_player();
  object ob=this_object();
  int exp;
  exp=me->query("combat_exp");
  if(ob->query_temp("change"))
    return 1;
  ob->set_temp("change",1);
  if(exp < 5000000)
    return 1;
  ob->set("combat_exp",exp);
  return 1;
}
