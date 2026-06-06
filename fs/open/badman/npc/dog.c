#include <ansi.h>

inherit NPC;

void create()
{
      set("title","靈犬");
      set_name("大呆",({"dog"}));
      set("long","一隻全身黝黑的大狼狗，今天和其主人一同出遊，顯得格外的興奮。\n");
      set("race","野獸");
      set("attitude","peaceful");
      set("gender","雄性");
      set("age",5);
      set("limbs",({"頭部","尾巴","前腳","後腿","身體"}));
      set("verbs",({"bite","claw"}));

      set_skill("unarmed",30);
      set_skill("dodge",25);
      set("combat_exp",5000);

      set("chat_chance",2);
      set("chat_msg",({
          "大呆用後腿抓了抓自己的耳朵。\n",
          "大呆在你的腿邊嗅了嗅。\n",
          "大呆舉起了後腿跨在你小腿上，撒了一泡尿。\n",
      }));

      setup();
}
