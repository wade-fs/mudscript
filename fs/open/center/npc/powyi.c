// powyi.c

#include "/open/open.h"
inherit NPC;

void create()
{
  set_name("寶姨", ({ "Powyi", "powyi" }));
  set("race", "人類");
  set("gender", "女性");
  set("age", 40);
  set("long", "雍容華貴, 風韻猶存, 當年必定是響噹噹的絕色人物\n");
  set("attitude", "friendly");
  set("cor", 23);
        set("combat_exp",640);
  set("chat_chance", 2);
  set("chat_msg",({
    (: this_object() :),
    (: this_object() :),
    (: this_object() :),
    (: this_object() :),

    "寶姨笑著說︰裏面坐 ! 裡面坐 !\n",
    "寶姨笑著說 : 第一次來 ?\n",
    "寶姨笑著說 : 沒關係 ! 一回生, 二回熟嘛. \n"
    "寶姨笑著說 : 我們剛剛找到一個小姑娘, 長得好漂亮, 改天叫她出來見見世面.\n",
    }));

  set_temp("apply/attack", 20);
  set_temp("apply/damage", 10);
  set_temp("apply/armor", 10);
  setup();
  carry_object(CENTER_OBJ"cloth2")->wear();
}
