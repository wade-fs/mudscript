#include <ansi.h>

inherit NPC;

void create()
{
      set_name("穿山甲",({"pangolin"}));
      set("long","一隻具有堅硬外殼的穿山甲，正努力扒著地上的泥土。\n");

      set("race","野獸");
      set("gender","雄性");
      set("age", 4);
      set("attitude","peaceful");

      set("limbs",({"頭部","腹部","腿部","尾巴"}));
      set("verbs",({"bite","claw"}));

      set_skill("dodge",10);
      set_temp("apply/armor",70);
      set_temp("apply/attack",10);
      set("combat_exp",520);

      set("chat_chance",1);
      set("chat_msg",({
          "穿山甲嗅了嗅四周的味道。\n",
          "穿山甲用後腿把一顆石子從洞裡踢了出來。\n",
      }));

      setup();
}

void die()
{
      object killer;
      killer=query_temp("last_damage_from");
      killer->set_temp("blood",1);
      message_vision("幾滴鮮血濺到了$N的衣服上。\n",killer);
      ::die();
}
