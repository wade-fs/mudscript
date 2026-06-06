#include <ansi.h>
#include "/open/open.h"
inherit NPC;

void create()
{
  object ob;
  set_name("陳星輝",({"star chen","star","chen"}) );
  set("long","此人相貌堂堂，與人相當斯文的感覺，事實上是個面善心惡，狼心狗肺的東西。\n");
  set("race", "人類");
  set("gender","男性");
  set("combat_exp", 800000);
  set("age",60);
  set("title","金槍銀劍");
  set("kee",3000);
  set("max_kee",3000);
  set("force",3000);
  set("max_force",3000);
  set("force_factor",12);
  set_skill("shasword",80);
  set_skill("sword",90);
  set_skill("shaforce",75);
  set_skill("force",80);
  set_skill("sha-steps",90);
  set_skill("dodge",90);
  set_skill("parry",90);

  map_skill("dodge","sha-steps");
  map_skill("force","shaforce");
  map_skill("sword","shasword");

  set("chat_chance_combat",50);
  set("chat_msg_combat",({
    (:perform_action,"sha_kee" :),
    (:perform_action,"swordkee" :)
  }));

  setup();
  add_money("gold",5);
  carry_object("/open/gsword/obj/woodsword")->wield();
}

void init()
{
  object ob;
  ::init();
  if( interactive(ob = this_player())&& !is_fighting() )
  {
    remove_call_out("greeting");
    call_out("greeting",1 , ob);
  }
}

void greeting(object me)
{
  command("say 你...你...你要做什麼...");
}

int accept_kill( object me)
{
  int i;
  object guard;

  if( !present("killer", environment(me)) )
  {
    this_object()->command("say 救命ㄚ，救命ㄚ...快來人救我..........");
    tell_room(environment(me),HIW"\n好大的膽子，連黑風組的客人也敢動!!\n\n"NOR);
    for(i=0;i<2;i++)
    {
      guard = new("/open/killer/mon/ghost/npc/black5");
      guard->move(environment(me));
      guard->command("follow "+me->query("id"));
      guard->kill_ob(me);
    }
  }
  tell_room(environment(me),"黑風兄弟們，把刺客拿下來。\n"),
  message_vision(HIB"\n黑風組三級殺手一收到命令，馬上向$N攻過來！\n"NOR,me);
  return 1;
}

void die()
{
  object head, killer,ob=this_object();
 
  killer= query_temp("last_damage_from");
  if( killer->query_temp("ghost") == 2) // 防止 fanset 後又來砍
  {
 //   command("say 我...我...我不甘心ㄚ!!");
    message_vision("『"+HIG+"暢談"+NOR+"』"+HIY+"$n說道: 我...我...我不甘心ㄚ!!\n" NOR, killer,ob);
    message_vision("說完之後他就倒下了......\n", killer);
    head=new("/open/killer/mon/ghost/obj/shead.c");
    head->move( environment( killer));
    killer->set_temp("ghost", 3);
  }
  else
  {
//    command("say 我跟你無怨無仇，為何你要置我於死地...");
    message_vision("『"+HIG+"暢談"+NOR+"』"+HIY+"$n說道: 我跟你無怨無仇，為何你要置我於死地...\n" NOR, killer,ob);
    message_vision("說完之後他就倒下了......\n", killer);
  }
  ::die();
}
