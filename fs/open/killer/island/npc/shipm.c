#include <ansi.h>
inherit NPC;
void create ()
{
  set_name("船員",({"ship member","member","ship"}));
  set("long","商船上的人員, 身材魁武, 看起來十分精明能幹!!\n");
  setup();
}
