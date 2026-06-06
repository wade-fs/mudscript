#include <ansi.h>

inherit NPC;

void create()
{
      set_name("江湖藝人",({"ihinerant"}));
      set("long",@LONG
一個已有一些年紀的賣藝師父，你可以從他臉上看到歲月所留下的痕跡。
今天他這好在此地擺攤賣藝，希望能賺些生活費。
LONG
      );
      set("age",56);
      set("attitude","friendly");
      set("gender","男性");

      set_skill("unarmed",35);
      set_skill("dodge",35);
      set_skill("parry",35);
      set("combat_bat",10000);

      set("chat_chance",3);
      set("chat_msg",({
          "江湖藝人喊道：來來來！有人的捧個人場，有錢的捧個錢場！\n",
          "江湖藝人叫道：小弟初來貴寶地....\n",
          "江湖藝人一發勁，打碎了地上的三塊磚。\n",
      }) );

      setup();

      add_money("coin",10);
      carry_object("/obj/cloth")->wear();
}
