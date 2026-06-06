// fung.c

#include "/open/open.h"

inherit NPC;

void create()
{
  set_name("芳兒", ({ "Fung", "fung" }));
  set("race", "人類");
  set("gender", "女性");
  set("age", 17);
  set("long","她衣衫不整, 驚訝的望著你.\n");
  set("attitude", "peace");
  set("cor", 15);
  set("combat_exp",238);
  set("chat_chance", 2);

  set("chat_msg",({
    (: this_object() :),
    "芳兒尖叫︰ 啊 ~~~~~\n",
    }));

  set_temp("apply/attack", 15);
  set_temp("apply/damage", 3);
  set_temp("apply/armor", 3);
  setup();
}
