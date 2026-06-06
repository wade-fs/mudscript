#include <ansi.h>

inherit NPC;

void create()
{
      set_name("胖刺蝟",({"fat urchin","urchin"}));
      set("long",@LONG
一隻在樹幹下睡覺的胖刺蝟；胖胖的模樣十分討人喜歡，讓你忍不住想拍拍
它的頭；但又看它滿身的尖刺，想想還是算了吧。
LONG
      );

      set("race","野獸");
      set("gender","雄性");
      set("age", 4);
      set("attitude","peaceful");

      set("limbs",({"頭部","腹部","前腿","尾巴","後腿"}));
      set("verbs",({"claw","bite"}));

      set("max_kee",150);
      set("kee",150);
      set_skill("dodge",10);
      set_temp("apply/armor",90);
      set_temp("apply/attack",30);
      set("combat_exp",740);

      set("chat_chance",1);
      set("chat_msg",({
          "胖刺蝟抬起了頭打了個大哈欠。\n",
          "胖刺蝟抬起了頭怔怔的瞧了你幾眼。\n",
      }));

      setup();
}

void die()
{
      object killer;
      killer=query_temp("last_damage_from");
      killer->set_temp("blood",1);
      message_vision(HIR + "\n幾滴鮮血濺到了$N的衣服上。\n" + NOR,killer);
      ::die();
}
