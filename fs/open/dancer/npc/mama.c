#include <ansi.h>
inherit NPC;
void create()
{
        object ob;
	set_name("劉媽", ({"mama"}));
	set("long",
"她是跟著琪琪一起嫁到獨孤家來的嬤嬤桑,她的手藝非常之好,琪琪最
喜歡吃她做的菜.瞧她的身手,可比十幾年前的千手觀音柳如虹.
");
	set("gender","女性");
	set("combat_exp",90000);
	set("age",50);
	set("title","落雁閣掌廚");
                set("str", 26);
                set("cor", 20);
                set("cps", 18);
                set("per", 26);
                set("int", 28);
        set("force",1800);
        set("max_force",1800);
        set("force_factor", 8);
	set_skill("unarmed",50);
        set_skill("dodge",80);
        set_skill("force",60);
        set_skill("move",80);
        set_skill("parry",50);
//        set_skill("throwing",95);
//        set_skill("rain-throwing",95);
//        map_skill("throwing","rain-throwing");
//        set_skill("shade-steps",70);
//        map_skill("dodge","shade-steps");
//        set_skill("blackforce",50);
//        map_skill("force","blackforce");
        set("chat_chance", 6);
        set("chat_msg", ({
           "嬤嬤桑 對著你說道:『你可以幫助(help)我嗎？』\n",
}));
	setup();
	add_money("silver",90);
        carry_object("/open/center/obj/pant2.c")->wear();
        carry_object("/open/center/obj/cloth3.c")->wear();
        carry_object("/u/p/ppopp/obj/rose.c")->wear();
        ob=carry_object("/open/snow/obj/knife.c");
        ob->set_amount(50);
}
 
void init()
{ 
 add_action("help_mob","help");
}

 int help_mob(string me)
{ 
  if(me=="mama")
 {
  command("ccc");
  command("say 你來的正好,我現在正缺人手呢!!!");
  return 1; }
  return 0; 
}

 int accept_fight(object ob)
{ 
  return notify_fail("嬤嬤桑現在正忙著烹調,根本就沒空理你。\n");;
}
 int accept_kill(object ob)
{ ob ->query("id");
  set("title", "");
  set("nickname", "千手觀音");
  set("name",  "柳如虹" );
  set("long",
"現在站在你眼前的是當年亦曾和鄭老前輩等英雄一同力戰群魔的
小姑娘, 據說她可以同時接發三十隻飛鏢, 宛如千手觀音, 因而
得名.
");
  message_vision(HIG"劉媽氣的兩眼直視,神情好似"HIR"柳如虹"HIG"再世!!!\n"NOR,this_player());
  command("stare "+ob->query("id"));
  command("say 想殺我??? 你知道我是誰嗎!!!");
  command("wield knife");
  return 1;
}
