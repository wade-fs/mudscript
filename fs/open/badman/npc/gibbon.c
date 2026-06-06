#include <ansi.h>

inherit NPC;

void create()
{
      set_name("長臂猿",({"gibbon"}));
      set("long",@LONG
一隻在樹上的長臂猿，正以它長長的手臂在樹與樹之間盪來盪去；見你來了也不
以為意，只是齜牙裂嘴的扮個鬼臉罷了。
LONG
      );

      set("race","野獸");
      set("gender","雄性");
      set("age", 5);
      set("attitude","peaceful");

      set("limbs",({"頭部","腹部","前腿","尾巴","後腿"}));
      set("verbs",({"bite","claw"}));

      set_skill("dodge",30);
      set_temp("apply/armor",20);
      set_temp("apply/attack",30);
      set("combat_exp",3850);


      set("chat_chance",1);
      set("chat_msg",({
          (:random_move:),
          "長臂猿從身上抓了個東東(小百科:應是鹽份之類)，便放進了嘴裡。\n",
          "長臂猿抓了抓頭，瞧了你幾眼。\n",
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
