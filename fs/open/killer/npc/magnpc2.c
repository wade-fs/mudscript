#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
  object ob;
  set_name("紫霞組上級殺手",({"mag killer","killer","mag"}) );
  set("long","他是紫霞組專門用於守護通吃小築的殺手，一身功\夫自不在話下。 \n");
  set("race", "人類");
  set("gender","男性");
  set("combat_exp",500000);
  set("age",60);
  set("title","黑牙聯的成員");
  set("class","killer");
  set("cor",30);
  set("cps",30);
  set("str",50);
  set("kee",2500);
  set("max_kee",2500);
  set("force",2000);
  set("max_force",2000);
  set("force_factor",10);
  set("bellicosity",800);
  set_skill("rain-throwing",73);
  set_skill("throwing",72);
  set_skill("blackforce",60);
  set_skill("force",60);
  set_skill("dodge",85);
  set_skill("shade-steps",70);
  set_skill("parry",75);
  set_skill("move",85);
  map_skill("force","blackforce");
  map_skill("throwing","rain-throwing");
  map_skill("dodge","shade-steps");
 setup();
    add_money("gold",6);
    ob=carry_object("/open/killer/obj/lustar");
    ob->add_amount(500);
    ob->wield();
    ob=carry_object("/open/killer/weapon/k_head2.c")->wear();
    ob=carry_object("/open/killer/weapon/k_arm1.c")->wear();
    ob=carry_object("/open/killer/weapon/k_leg1.c")->wear();
}
int accept_kill(object ob)
{
message_vision( this_object()->name()+"說:先接最利害的五招吧！\n",ob);
  add("bellicosity",1200);
  command("cmd bellup");
   return 1;

}
int accept_fight(object me)
{
    object ob,guard;
    ob=this_object();

    guard=present( "guard 2",environment(ob) );
     if( !present( "guard 2",environment(ob))||!living(guard)) return 1;
    else {
    tell_room(environment(me),"一起上！有人找碴!給我拿下 \n"),
    message_vision(HIB"\n紫霞組上級殺手看到好友有難，馬上向$N攻過來！\n"NOR,me);
     guard->fight_ob(me);
    return 1;
   }
}
