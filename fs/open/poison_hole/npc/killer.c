//old man
#include "/open/open.h"
#include <ansi.h>
inherit NPC;
string poison();
void create()
{
	set_name("暗影殺手",({"killer"}));
	set("gender", "男性" );
	set("age", 37);
set("long", @LONG
    這是一位殺手！！
LONG
	);
  set("combat_exp",3000000);
  set("chat_chance",5);
  set("chat_msg", ({
        CYN"殺手說道：殺！殺！殺！\n"NOR,
        }) );
  set("chat_chance_combat",20);
  set("can_use_mobkee",1);
  set("chat_msg_combat",({
        (:perform_action,"throwing.mobkee":)
        }));
  set("attitude", "friendly");
  set("class","killer");
  set("quest/worldpill",1);
  set("force_factor",20);
  set_skill("dodge", 150);
  set_skill("parry", 150);
  
  set_skill("rain-throwing",100);
  set_skill("throwing",100);
  map_skill("throwing","rain-throwing");

  set_skill("shadow-kill",100);
  set_skill("dagger",100);
  map_skill("dagger","shadow-kill");
  map_skill("parry","shadow-kill");

  set_skill("dark-steps",100);
  map_skill("dodge","dark-steps");

  set_skill("force",300);
  set_skill("blackforce",300);
  map_skill("force","blackforce");

  set("family/family_name","黑牙聯");
  set("functions/manakee/level",100);
  set("ninja" , ([ /* sizeof() == 3 */
  "apart" : 1,
  "firstpart" : 1,
  "bpart" : 1,]));

  set("quests/acupuncture",1);
  set("no_attack",1);
  setup();
  carry_object("/open/killer/headkill/obj/world_dag")->wield();
  carry_object("/open/killer/headkill/obj/world_dag")->wield();
  all_inventory(this_object())->set("no_get",1);
}
void init()
{
  object ob = previous_object();
  if(!userp(ob) && ob->query("id") == "killer") return ;
  if(ob->query("id") != "killer" && ob->query("id") != "old man" && !userp(ob))
  {
    message_vision("一陣煙霧繞在$N身上，突然就不見了！\n",ob);
    call_out((:destruct:),0,ob);
    return ;
  }
  this_object()->kill_ob(ob);
  ob->kill_ob(this_object());
  ::init();
}

