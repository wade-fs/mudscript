#include <ansi.h>
inherit NPC;

void create()
{
        seteuid(getuid());      // 這行一定要
        set_name("關卡守衛", ({ "door guard","guard" }) );
        set("race", "人類");
        set("gender", "男性");
        set("age", 35);
        set("long", "他手中拿把穿長劍正守著大門。\n");
        set("str", 30);
        set("cor", 30);
        set("max_kee", 1000);
        set("max_force", 500);
        set("force", 500);
        set("force_factor", 5);
        set("combat_exp", 300000);
        set_skill("sword", 60);
        set_skill("parry", 40);
        set_skill("dodge", 30);
        set_skill("force", 30);

        set_skill("shasword", 60);
        set_skill("sha-steps", 40);

        map_skill("sword","shasword");
        map_skill("dodge","sha-steps");

        set("chat_chance", 8);
        set("chat_msg",({
             "關卡守衛說道: 入關如登天，來人走這邊。\n",
             "關卡守衛瞪了你一眼說: 想入關？能殺的了我再說吧。\n",
             "關卡守衛推了你一把說: 要進關不難，但是你有這個資格嗎？\n",
        }) );
        set_temp("apply/armor", 80);

        setup();
        add_money("silver", 5);
        carry_object("/obj/longsword")->wield();
}

int accept_kill(object me)
{
  object ob,guard;
  ob=this_object();
  guard=present( "guard 2",environment(ob) );
  if( !present( "guard 2",environment(ob))||!living(guard)) return 1;
  else {
  tell_room(environment(me),"一起上！有人找碴!給我殺了 \n"),
  message_vision(HIY + "\n關卡守衛看到有人要硬闖，馬上向$N攻過來！\n" + NOR,me
  );
  guard->kill_ob(me);
  return 1;
  }
}
int accept_fight(object me)
{
  object ob,guard;
  ob=this_object();
  guard=present( "guard 2",environment(ob) );
  if( !present( "guard 2",environment(ob))||!living(guard)) return 1;
  else {
  tell_room(environment(me),"一起上！有人找碴!給我殺了 \n"),
  message_vision(HIY + "\n關卡守衛看到有人要硬闖，馬上向$N攻過來！\n" + NOR,me
  );
  guard->kill_ob(me);
  return 1;
  }
}
