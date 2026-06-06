#include <ansi.h>

inherit NPC;

void create()
{
      set_name("食蟻獸",({"anteater"}));
      set("long","一隻在樹幹下找螞蟻吃的食蟻獸，正伸出舌頭舔食地上的螞蟻。\n");

      set("race","野獸");
      set("gender","雄性");
      set("age", 5);
      set("attitude","peaceful");

      set("limbs",({"頭部","腹部","腿部","尾巴"}));
      set("verbs",({"bite","claw"}));

      set_skill("dodge",10);
      set_temp("apply/armor",5);
      set_temp("apply/attack",10);
      set("combat_exp",410);

      set("chat_chance",1);
      set("chat_msg",({
          "食蟻獸吐著舌頭舔了舔地上的螞蟻。\n",
          "食蟻獸將長舌伸了伸。\n",
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
