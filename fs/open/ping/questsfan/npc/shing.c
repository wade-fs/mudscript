inherit NPC;     //南宮勳 2000.4.2 by dhk
#include <ansi.h>
#include "/open/open.h"
inherit F_MASTER;


void create()
{
  set_name("南宮勳",({"shing nankon","shing","nankon"}));
set("long","南宮勳乃是段氏嫡族中肩負、擔任晶谷守關的四天王之一，\n"
          +"在族中其劍術無人能出其右，與百里勇在族中並稱刀、劍雙\n"
          +"王。不過經常聽他感嘆：若能得到傳說中的神劍，就是要我\n"
          +"當場舉劍自刎，我都願意，我也不枉此生了。\n");
  set("gender","男性"); 
  set("class","swordsman");
  set("title","段家第十代劍宗");
  set("nickname",""HIY"識劍"NOR"");
  set("attitude","heroism");
  set("age",39);
  set("max_kee",4000);
  set("kee",4000);
  set("str",44);
  set("con",24);
  set("cps",18);
  set("cor",42);
  set("int",42);
  set("max_force",9000);
  set("force",9000);
  set("force_factor",20);
  set("combat_exp",9000000);
  set_skill("dodge",100);
  set_skill("move",100);
  set_skill("force",140);
  set_skill("parry",90);
  set_skill("literate",100);
  set_skill("sword",120);
  set_skill("linpo-steps",100);
  set_skill("shasword",100);
  set_skill("shaforce",140);
  map_skill("sword","shasword");
  map_skill("parry","shasword");
  map_skill("move","linpo-steps");
  map_skill("dodge","linpo-steps");
  map_skill("force","shaforce");
  set("get_sha_sp",1);
  set("bounds",4000000);
  set("chat_chance_combat",90);
  set("chat_msg_combat",({
     (:perform_action,"sword.sha_kee":),
     }));
  set("chat_chance",10);
  set("chat_msg", ({
            ""+HIY+"南宮勳自言自語的道: 『劍』乃王道的表現。"+NOR+"\n",
            ""+HIY+"南宮勳對著手上的劍說: 我手上這把"+HIR+"連陽"+HIY+"堪稱上上之選，但世上還有一把比之更尊之劍。"+NOR+"\n",
            ""+HIC+"南宮勳嘆道: 真想見識一下傳聞中的皇者之劍"+HIR+"～"HIW"黑暗的禁忌"+HIC+"呀！"+NOR+"\n",
               }));
setup();
  add_money("gold",10);
  carry_object("/open/gsword/obj/dragon-sword.c")->wield();
//  carry_object("/open/gsword/obj/dragon-cloth.c")->wear();
  carry_object("/open/ping/questsfan/obj/diamond_belt")->wear();
  carry_object("/open/ping/questsfan/obj/diamond_boots")->wear();
   create_family("仙劍派",10,"劍宗");
}
int accept_kill(object who)
{
  command("perform sword.sha_kee");
  return 1;
}
int accept_fight(object who)
{
  command("perform sword.sha_kee");
  fight_ob(who);
  return 1;
}
void init()
{
        add_action("do_answer","answer");
        set_heart_beat(1);
}
void heart_beat()
{
        if( random(4) < 1 ){
        if( is_fighting() ){
                if( query("kee") < query("eff_kee") )
                        command("exert recover");
        }
        else{
                if( query("eff_kee") < query("max_kee") )
                        command("exert heal");
        }
        }
        :: heart_beat();
}

int accept_object(object me, object obj)
{
    if( obj->query("id") == "cloud rosyclon box" )
      {
        command("bow "+getuid(me));
        command("say 這..這..這..是送我的嗎﹖太感謝了。");
         if( me->query("family/family_name") == "段家" && me->query("questsfan/quest_step") == 3 )
          {
            command("say 南宮勳神情激動的對你說道:閣下竟送我如此貴重之物，那在下也不便阻擋了，請吧!!!\n");
            me->set("questsfan/quest_step", 4);
          }
        destruct(obj);
      }
    else
      command("? "+getuid(me));
    return 1;
}
