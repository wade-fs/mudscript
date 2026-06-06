//Room /u/l/lotus/dey.c

#include "/open/open.h"
inherit NPC;

void create()
{
  set_name("彩蝶", ({ "Tsai-Dey", "dey"}));
  set("race", "人類");
  set("gender", "女性");
  set("age", 20);
  set("long","彩蝶穿著蝶翼似的輕紗舞衣, 快樂的轉動身軀, 你隱約看到她的左臂上紋了一隻五彩繽紛的蝴蝶, 翩翩起舞....\n");
  set("attitude", "peaceful");
  set("str", 15);
  set("cor", 20);
  set("per", 27);
  set_skill("dodge", 80);
  set("combat_exp",2433);
  set("chat_chance", 1);

  set("chat_msg",({
    (: this_object() :),
    (: this_object() :),

    "彩蝶巧笑著說 : 我們來跳舞吧 !\n",
    "彩蝶笑著說 : 跳舞真使人陶醉 ~~~ \n",
    }));

  set_temp("apply/attack", 15);
  set_temp("apply/damage", 3);
  set_temp("apply/armor", 2);
  setup();
  add_money("silver",10);
  carry_object(CENTER_OBJ"cloth2")->wear();
  carry_object(CENTER_OBJ"pant1")->wear();
}
