// For the new hand of dancer ...//purple
#include "/open/open.h"
inherit NPC;
void create()
{
  set_name("妙齡少女",({"cutegirl"}) );
  set("title", "夜夢小築見習生");
  set("gender", "女性");
  set("age",13);
  set("attitude", "heroism");
  set("long", "在夜夢小築修業滿一年，將成為月牙兒徒弟的見習生\n");
  set("kee",2000);
  set("max_kee",2000);
  set("max_force",600);
  set("force",600);
  set("combat_exp",5500);
  setup();
}
