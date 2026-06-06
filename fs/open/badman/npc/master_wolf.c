#include <ansi.h>
inherit NPC;
void create()
{
  set_name("筤騂",({"wolf master","wolf","master"}));
set("long","這個人看來兇狠殘暴 ,但眼中卻透露出些許\和藹的眼神。
從他注視身旁那隻白狼的眼光來看，他似乎非常喜愛這
匹舉世無雙的白狼。\n");
  set("nickname","絕霸狼王");
  set("str",40);
  seteuid(getuid());
  set("age",47);
set("bellicosity",1000);
  set("combat_exp",430000);
  set("max_force",1000);
  set("force",1000);
  set("force_factor",10);
  set("max_gin",500);
  set("max_kee",600);
  set("max_sen",250);

  set_skill("badforce",50);
  set_skill("badstrike",75);
  set_skill("ghost-steps",38);
  set_skill("dodge",55);
  set_skill("unarmed",85);
  set_skill("parry",70);
  set_skill("move",30);
  set_skill("force",60);
  map_skill("force","badforce");
  map_skill("unarmed","badstrike");
  map_skill("parry","badstrike");
  map_skill("dodge","ghost-steps");
  map_skill("move","ghost-steps");
  set("functions/evil-blade/level",20);

  set("chat_chance_combat", 35);
  set("chat_msg_combat", ({
  (: perform_action, "unarmed.evil-blade" :),
  }));
  set("inquiry",([
    "杜殺的左手" : "左手...?這我可不曉得 ,但不知道我那匹愛狼前幾天從森林中帶回來的手是不是 ?啥...?你想要 ?那可不行 ,這隻手可是我這匹舉世無雙的白狼的食物!!想要 ,就自己來搶 !\n",
  ]));

  setup();
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

void greeting(object ob)
{
  if( ob->query("class")=="bandit")
  {
  if( ob->query("marks/ride_wolf",1))
  {
  }
else if( ob->query("quests/badroar",1) && ob->query("combat_exp") > 600000)
   {
    message_vision("你不就是那個打敗我的小夥子嗎？\n
怎樣，最近混得不錯吧？果真英雄\n
出少年啊！來吧，去跟管狼的許\老\n
講一聲，要隻狼騎騎吧！\n",ob);
    ob->set("marks/ride_wolf",1);
   }
  }
}
int accept_kill(object me)
{
  object ob,wolf;
  ob=this_object();
  wolf=present( "wolf",environment(ob) );
  if( !present( "wolf",environment(ob))||!living(wolf)) return 1;
  else {
  tell_room(environment(me),"居然敢動我!?你死定了 !\n"),
  message_vision(RED"\n白狼看到主人被襲 ,馬上向$N撲了過去 !\n"NOR,me
  );
  wolf->kill_ob(me);
  return 1;
  }
}
int accept_fight(object me)
{
  object ob,wolf;
  ob=this_object();
  wolf=present( "wolf",environment(ob) );
  if( !present( "wolf",environment(ob))||!living(wolf)) return 1;
  else {
  tell_room(environment(me),"居然敢動我!?你死定了 !\n"),
  message_vision(RED"\n白狼看到主人被襲 ,馬上向$N撲了過去 !\n"NOR,me
  );
  wolf->kill_ob(me);
  return 1;
  }
}
