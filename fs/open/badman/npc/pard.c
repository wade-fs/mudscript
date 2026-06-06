#include <ansi.h>

inherit NPC;

void create()
{
      set_name("金錢豹\",({"pard"}));
      set("long",@LONG
一隻罕見的金錢豹\，一身有著如金錢般的花紋；在樹上以兩顆銅玲般的大眼虎
視眈眈的望著你，再加上腳上那兩對銳利如刀的豹\爪，便是提醒你快些離開的
最佳証據。
LONG
      );

      set("race","野獸");
      set("gender","雄性");
      set("age", 5);
      set("attitude","peaceful");

      set("limbs",({"頭部","腹部","前腿","尾巴","後腿"}));
      set("verbs",({"bite","claw"}));

      set("max_kee",150);
      set("kee",150);
      set_skill("dodge",55);
      set_temp("apply/armor",40);
      set_temp("apply/attack",70);
      set("combat_exp",6500);

      set("chat_chance",1);
      set("chat_msg",({
          "金錢豹\起身飛縱至另一棵樹上。\n",
          "金錢豹\跳下樹來，在你的身旁繞了幾圈。\n",
          "金錢豹\打了個大哈欠，露出一口雪白尖銳的牙齒；嚇出你一身的冷汗。\n",
      }));

      setup();
}

void init()
{
      object me=this_player();
      ::init();
      if( me->query_temp("blood")==1 ) {
      message_vision(HIB + "\n金錢豹\聞到$N身上的血腥味，一聲狂嘯、便撲向$N。\n" + NOR,me);
      this_object()->kill_ob(me);
      }
}
