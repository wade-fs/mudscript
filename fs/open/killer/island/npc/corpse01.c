#include <ansi.h>
inherit NPC;
void create ()
{
  set_name("殘缺不全的屍體",({"incomplete-corpse","corpse"}));
  set("long","屍骨殘缺不全，看來生前受到極大的傷害。\n");
  set("no_fight",1);
  set("no_kill",1);
  set("no_magic",1);    
  set("no_spell",1);
  set("no_sac",1);
  setup();
}
int accept_object(object me,object ob)
{

me=this_player();
if(ob->query("id")!="incomplete_corpse's head")
tell_object(me,"結果什麼事也沒發生。\n");

if(me->query_temp("quest_corpse")==1)
{
message_vision("$N把$n給裝上去了。\n",me,ob);
tell_object(me,HIB + "\n\n你彷彿聽到了一些聲音：遇到打不開的門，就祈禱(pray)吧...。\n" + NOR);
me->set_temp("quest_corpse",2);
}

else
tell_object(me,"因為你根本不知道要把"+ob->name()+"裝在哪？\n");
}
