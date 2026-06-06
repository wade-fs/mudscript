#include <ansi.h>

inherit NPC;

void create()
{
      set_name("醉漢",({"drinker"}));
      set("long","一個滿身酒氣的醉漢，正醉倒在這個巷道中。\n");
      set("age",40);
      set("attitude","friendly");
      set("gender","男性");

      set_skill("unarmed",80);
      set_skill("dodge",80);
      set("combat_exp",300000);

      set("chat_chance",2);
      set("chat_msg",({
          "醉漢嘆道：啊~~世事如棋啊...\n",
          "醉漢嘆道：人生事，難盡如意啊~~\n",
      }));

      setup();
      carry_object("/obj/cloth")->wear();
}

int accept_fight(object me)
{
      write("醉漢搖了搖頭說道：嘿!命只有一條，何必呢??\n");
      return 0;
}
