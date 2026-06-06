#include <ansi.h>

inherit NPC;

void create()
{
      set("title","溜狗男孩");
      set_name("大寶",({"dabau"}));
      set("long",@LONG
三姑---胖婦人的寶貝兒子，瞧今個兒天氣不錯，這男孩便帶他的愛犬---大呆出來
一同蹓躂蹓躂、活動一下筋骨。
LONG
      );
      set("age",10);
      set("gender","男性");
      set("attitude","friendly");

      set_skill("parry",10);
      set_skill("dodge",10);
      set_skill("unarmed",5);
      set("combat_bat",1000);

      set("chat_chance_combat",2);
      set("chat_msg_combat",({
          "大寶大叫：哇！媽媽、媽媽，救命啊，有人要打我啊！\n",
      }) );

      setup();

      carry_object("/obj/cloth")->wear();
      add_money("coin",5);
}

int accept_kill(object me)
{
      object ob,dog;
      ob=this_object();
      dog=present( "dog",environment(ob) );
      if( !present( "dog",environment(ob)) || !living(dog))  return 1;
      else {
          tell_room(environment(me),"大寶呼救道：哇！大呆、大呆快來救我啊！\n"),
          message_vision(HIB"\n原在一旁的大呆護主心切，向$N疾撲了過去。\n"NOR,me);
          dog->kill_ob(me);
          return 1;
      }
      return 1;
}
