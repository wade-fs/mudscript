#include "/open/open.h"
#include <ansi.h>

inherit NPC;
void create()
{
  set_name("駱駝", ({ "desert camel","desert","camel"}));
  set("title", "塵沙");
  set("gender", "野獸");
  set("long","一隻單峰駱駝，土黃色的皮膚，呆滯的眼神，乍看之下並不像
什麼了不起的珍獸。但仔細一看，眼神中微微透出耀眼光彩，黃沙
緩緩地從正在咀嚼草料的嘴巴中流出。看樣子這傢伙並不好惹！
");
  set("combat_exp",1000000);
  set("max_kee",3000);
  set("max_gin",1870);
  set("max_sen",2150);
  set("max_force",3500);
  set("force",3500);
  set("force_factor",60);
  
setup();
}

void die()
{
  object killer;
  killer=query_temp("last_damage_from");
  killer->set_temp("marks/k_camel",1);
  message_vision("$N打得興起，塵沙駱忽然口吐鮮血，四腳朝天，死了！\n",killer);
  ::die();
}

void unconcious()
{
  object killer;
  killer=query_temp("last_damage_from");
  killer->set_temp("marks/f_camel",1);
  message_vision("$N成功\地馴服了駱駝！\n",killer);
  ::unconcious();
}
