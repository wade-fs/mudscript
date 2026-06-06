#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
   object ob;
   set_name("綠雲組三級殺手",({"green killer","killer","green"}) );
   set("long","綠雲組輕身功\夫極為高明, 手下功\夫可也不弱哦! \n");
   set("race", "人類");
   set("gender","男性");
   set("combat_exp",200000);
   set("age",25);
   set("title","黑牙聯的成員");
   set("class","killer");
   set("cor",30);
   set("cps",30);
   set("str",20);
   set("kee",1200);
   set("max_kee",1200);
   set("force",1000);
   set("max_force",1000);
   set("sen",1000);
   set("max_sen",1000);
   set("gin",1000);
   set("max_gin",1000);
   set("force_factor",3);
   set("bellicosity",800);
   set_skill("rain-throwing",40);
   set_skill("throwing",45);
   set_skill("blackforce",35);
   set_skill("force",45);
   set_skill("shade-steps",50);
   set_skill("dodge",50);
   set_skill("parry",45);
// map_skill("dodge","shade-steps");
   map_skill("force","blackforce");
   map_skill("throwing","rain-throwing");
   setup();
   add_money("gold",1);
   ob=carry_object("/open/killer/obj/lustar");
   ob->add_amount(100);
   ob->wield();
}
void init()
{
   object ob;
   ::init();
   if( interactive(ob = this_player())&& !is_fighting() ) {
   remove_call_out("greeting");
   call_out("greeting",1 , ob);   }
}
int accept_fight(object me)
{
   object guard;

   guard=present( "killer 2",environment(me) );
   if( !present( "killer 2",environment(me))||!living(guard))
      return 1;
   else
   {
      tell_room(environment(me),"一起上！有人找碴!給我拿下 \n"),
      message_vision(HIB + "\n綠雲組三級殺手看到好友有難，馬上向$N攻過來！\n" + NOR,me);
      guard->fight_ob(me);
      return 1;
   }
}
int accept_kill( object me)
{
   object guard;

   add("bellicosity",700);
   command("cmd bellup");

   guard=present( "killer 2",environment(me) );
   if( !present( "killer 2",environment(me))||!living(guard))
      return 1;
   else
   {
      tell_room(environment(me),"一起上！有人找碴!給我拿下 \n"),
      message_vision(HIB + "\n綠雲組三級殺手看到好友有難，馬上向$N攻過來！\n" + NOR,me);
      guard->kill_ob(me);
      return 1;
   }
}
void greeting(object ob)
{
   if( ob->query("class")=="killer")
   {
      command("smile "+ob->query("id"));
   }
   else
   {
      command("say 擅闖綠雲組禁地！找死嗎... \n");
      command("hehe "+ ob->query("id"));
   }
}
