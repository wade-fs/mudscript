#include <ansi.h>

inherit NPC;

void create()
{
      set_name("大灰狼",({"hyena"}));
      set("long",@LONG
一隻相當少見的大灰狼，正在這翠鬱的森林中覓食；偶而兩道冷電般的目光
迅捷的在你身上轉了一轉，便足使你背後的冷汗直流。你不禁心想：此處並
不是個久留之地，還是快離開為妙。
LONG
      );

      set("race","野獸");
      set("gender","雄性");
      set("age", 6);
      set("attitude","peaceful");

      set("limbs",({"頭部","腹部","前腿","尾巴","後腿"}));
      set("verbs",({"bite","claw"}));

      set_skill("dodge",50);
      set_temp("apply/armor",30);
      set_temp("apply/attack",50);
      set("combat_exp",3500);

      set("chat_chance",1);
      set("chat_msg",({
          (:random_move:),
          "大灰狼抬起頭，嗅了嗅四周的味道。\n",
          "大灰狼往你的方向走了過來，在你的身旁繞了幾圈。\n",
          "大灰狼仰起頭來，望天空一聲的長嘯；嚇的你一身的冷汗。\n",
      }));

      setup();
}

void init()
{
      object me=this_player();
      ::init();
      if( me->query_temp("blood")==1 )  {
      message_vision("大灰狼聞到$N身上的血腥味，一聲狂嘯、便撲向$N。\n",me);
      this_object()->kill_ob(me);
      }
}
