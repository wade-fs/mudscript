// chang.c

#include "/open/open.h"

inherit NPC;

void create()
{
  set_name("橙兒", ({ "Chang", "chang" }));
  set("race", "人類");
  set("gender", "女性");
  set("age", 15);
  set("long", "一個很貼心的丫頭, 總是守在樓梯口, 勸尋芳客不要打擾小姐休息.\n");
  set("attitude", "friendly");
  set("cor", 20);
  set("combat_exp",490);
  set("chat_chance", 2);

  set("chat_msg",({
    (: this_object() :),
    (: this_object() :),

    "橙兒說道︰小姐們都累了, 不要上去打擾她們好嗎 ?\n",
    "橙兒說道 : 曲廳裡有姑娘在唱小曲兒, 去看看吧 !\n",
    }));

  set_temp("apply/attack", 15);
  set_temp("apply/damage", 5);
  set_temp("apply/armor", 5);
  setup();
  carry_object(CENTER_OBJ"cloth2")->wear();
}
