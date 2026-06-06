#include <ansi.h>
inherit NPC;

void create()
{
        set_name("歐陽上智",({"scholar de","de"}));
        set("title","五儒生");
        set("family/family_name","儒門");
        set("gender","女性");
        set("race", "人類");
	set("age", 45);
	set("long", "此人位居儒門中之高位,在江湖的名聲極響.\n");
	set("str", 50);
set("max_kee",1000);
set("kee",1000);
    set("max_force",2500);
set_skill("literate",100);
   set("force",2500);
        set_skill("parry",80);
        set("combat_exp",600000);
set_skill("knowpen",100);
        set_skill("stabber", 80);
        set_skill("force",80);
        set("force_factor", 10);
        map_skill("stabber","knowpen");	
        set_skill("dodge",80);
	set_skill("winter-steps", 80);
        map_skill("dodge","winter-steps");
        set("chat_chance_combat",15);
	set("chat_msg_combat",({
     	   (: perform_action, "stabber.movedown" :)
     	  }));
	setup(); 
	add_money("gold",10);
 carry_object("/open/scholar/obj/literate_pen")->wield();
carry_object("/open/scholar/obj/s_hands")->wear();
carry_object("/open/scholar/obj/s_cloth")->wear();
}
