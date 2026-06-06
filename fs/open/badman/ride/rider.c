#include "/open/open.h"
#include <ansi.h>

inherit NPC;

string do_want();
void create()
{
  set_name("許\老",({ "elder shi","elder","shi"}) );
  set("title","牧人");
  set("gender", "男性");
  set("age",68);
  set("attitude", "peaceful");
  set("no_kill",1);
  set("no_fight",1);
  set("long","一個面貌和善的老人，是個好人。他正在準備狼群的食物。\n");
  set("chat_chance",6);
  set("chat_msg", ({
  "狼兒乖啊乖，好吃的就要來！\n",
  }) );

  set("inquiry", ([
  "騎狼" : "想騎啥就跟我要（want）就好了，問東問西的想幹嘛？\n",
  ]));

setup();
}
