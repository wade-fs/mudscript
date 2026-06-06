#include <ansi.h>
#include "/open/open.h"
inherit NPC;
  inherit F_MASTER;
string book();
void create()
{
           set_name("劉全書",({"master liu","liu"}));
          set("long","他是雪蒼三俠之首『黑影鬼腳』劉全書，一雙鐵腳，縱橫武林。\n");
		set("gender","男性");
	set("guild_master",1);
	set("class","fighter");
          set("nickname","黑影鬼腳");
          set("combat_exp",1000000);
          set("attitude","heroism");
          set("age",47);
          set("title","雪蒼派第四代掌門人");
		set("str", 44);
		set("cor", 24);
		set("cps", 18);
		set("per", 24);
		set("int", 42);
          set("force",2200);
          set("inquiry",([
                 "天邪石":   "師父臨終前曾交給我這樣寶物﹐他說此物當贈與有緣人。",
        "有緣人":   "能說出十年前武林三大高手者﹐即為有緣人。\n",
      "藏經閣":  (: book :),
          ]));
            set_skill("literate",40);
          set("max_force",2200);
	set_skill("array",40);
	set_skill("blade",40);
	set_skill("cure",40);
	set_skill("dagger",40);
	set_skill("move",70);
	set_skill("force",120);
	set_skill("magic",20);
	set_skill("dodge",70);
	set_skill("parry",60);
	set_skill("poison",20);
	set_skill("spells",20);
	set_skill("staff",50);
	set_skill("stick",50);
	set_skill("sword",50);
	set_skill("throwing",60);
	set_skill("unarmed",100);
	set_skill("whip",70);
	set("force_factor",10);
           set_skill("parry",60);
          set_skill("snowforce",100);
           map_skill("force","snowforce");
          set_skill("snow-martial",100);
               map_skill("unarmed","snow-martial");
              map_skill("dodge","snow-martial");
	set("chat_chance_combat",60);
	set("chat_msg_combat",({
	(: exert_function, "enforceup" :),

	(: perform_action, "unarmed.kee-wind" :)
	}));
	setup();
          create_family("雪蒼派",4,"掌門人");
	carry_object(SNOW_OBJ"stone");
}

void init()
{
      add_action("do_say","say");
	add_action("do_join","join");
}
  void attempt_apprentice(object ob)
{
	if(this_player()->query("class")!="fighter")
	{
		command("say 你不是武者﹐我不能收你。\n");
		return;
	}
      if((int)ob->query_str()<20)
{
          command("say 雪蒼鬼腳要力量大的人才能學，我看你請回吧!\n");
return;
      }
      command("hmm");
          command("recruit "+ob->query("id"));
}
int do_say(string str)
{
     object who;
        who=this_player();
	if(who->query("get_stone")==1)
           return 0;
    if (str=="鄭士欣")  this_player()->set_temp("say_1",1);
    if (str=="莫測")    this_player()->set_temp("say_2",1);
    if (str=="獨孤愁")  this_player()->set_temp("say_3",1);
    if(this_player()->query_temp("say_1")==1&&this_player()->query_temp("say_2")==1&&this_player()->query_temp("say_3")==1)
     {
      command("smile");
        command("say 你果然是有緣人。\n");
      command("drop all");
	this_player()->set("get_stone",1);
      }
    return 0;
}
string book()
{
   object me=this_player();
   if(me->query("allow_study")==1)
          return "嗯...不是跟你說過了嗎？\n";
   command("say 此乃本派藏書重地﹐裡面有本派重要秘笈。");
   if(me->query("family/family_name")!="雪蒼派")
              return "你不是本派的弟子﹐沒資格讀本派的書。\n";
   if(me->query("combat_exp")<25000)
         return "已你這種程度要讀藏經閣的書﹐還早的很。\n";
   me->set("allow_study",1);
   return "好吧！我准你讀藏經閣內的書﹐但是雪蒼秘錄、鬼影腳秘笈、和黑影殘風錄三本書只准讀一本﹐而且讀一次。\n";
}
int do_join()
{
	if(this_player()->query("class"))
		return notify_fail("你已經加入其他工會了。\n");
	this_player()->set("class","fighter");
	message("system",
	HIC + "天生英才.....\n\n一代武者"+this_player()->name()+"誕生了 !!!\n" + NOR,users());
	return 1;
}
