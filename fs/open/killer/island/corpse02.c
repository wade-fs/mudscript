#include <ansi.h>
inherit NPC;
void create ()
{
  set_name("殘缺不全的屍體",({"incomplete-corpse","corpse"}));
  set("long","    屍骨殘缺不全，看來生前受到極大的傷害。\n");
  set("no_fight",1);
  set("no_kill",1);
  set("no_magic",1);    
  set("no_spell",1);
  set("no_sac",1);
  setup();
}
void init()
{
add_action("do_search","search");
}
int do_search(string arg)
{
object me;
me=this_player();
if(!arg||arg!="corpse")
return notify_fail("你在找什麼？\n");
if(me->query_temp("get_amulet")
return notify_fail("你什麼也沒有發現。\n");
else
{
tell_object(me,"你從屍骨的身上發現了一個護身符。\n");
me->set_temp("get_amulet",1);
new("/u/u/unfinished/room/obj/amulet")->move(me);
return 1;
}
}
