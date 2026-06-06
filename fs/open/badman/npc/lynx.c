#include <ansi.h>

inherit NPC;

void create()
{
      set_name("小山貓",({"little lynx","lynx"}));
      set("long",@LONG
一隻正在樹幹上打瞌睡的小山貓；尚未睡醒的它，睜著惺忪的雙眼，怔怔的
望著你，模樣十分討人喜歡。
LONG
      );

      set("race","野獸");
      set("gender","雄性");
      set("age", 3);
      set("attitude","peaceful");

      set("limbs",({"頭部","腹部","前腿","尾巴","後腿"}));
      set("verbs",({"bite","claw"}));

      set_skill("dodge",25);
      set_temp("apply/armor",15);
      set_temp("apply/attack",20);
      set("combat_exp",630);

      set("chat_chance",1);
      set("chat_msg",({
          "小山貓抬起了頭打了個大哈欠。\n",
          "小山貓抬起頭瞧了你幾眼，又趴下繼續睡它的覺。\n",
      }));

      setup();
}

void die()
{
      object killer;
      killer=query_temp("last_damage_from");
      killer->set_temp("blood",1);
      message_vision("幾滴鮮血濺到了$N的衣服上。\n",killer);
}
