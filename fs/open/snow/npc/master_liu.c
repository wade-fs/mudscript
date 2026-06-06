#include <ansi.h>
#include "/open/open.h"
inherit NPC;
  inherit F_MASTER;
string book();
string ask_sec()
{
	if( !this_player()->query("quests/to-kill-1") )
		return "你在說些什麼 ?\n";
	this_player()->set("quests/to-kill-2",1);
	return "好吧 ! 我就告訴你好了 ! 黑仙羅漢就是李靈 !\n";
}
int do_check( object me )
{
	command("say "+(me->query("gender")=="男性" ? "壯士" : "姑娘")+" ! 你看了似乎受到了極重的內傷﹐讓我替你看看吧 ?");
}
int do_nod()
{
	object me = this_player() , ob = this_object();
	if( !me->query("quests/kill-dugur") || me->query("quests/cure-star") ) return 0;
	message_vision("$N看了看$n身上的傷痕。\n",this_object(),this_player());
	command("sign");
	command("say 老夫無能為力﹐傷你之人的根基遠在老夫之上﹐當今世上﹐恐怕只有鄭士欣有這種實力。");
	command("say 快去找他來幫你看「你的傷」並請他幫你「療傷」。");
	return 1;
}
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
          set("max_kee",1500);
          set("kee",1500);
          set("inquiry",([
                 "天邪石":   "師父臨終前曾交給我這樣寶物﹐他說此物當贈與有緣人。",
        "有緣人":   "能說出十年前武林三大高手者﹐即為有緣人。\n",
      "藏經閣":  (: book :),
	"玉門關" : (: ask_sec :),
	"去老還童術" : "這個是一個古老的傳說﹐但是我從來就沒有看過。\n",
	"神算先生" : "此人身負奇才﹐有預知「未來」之能。\n",
          ]));
            set_skill("literate",40);
          set("max_force",2200);
	set_skill("array",40);
	set_skill("blade",60);
	set_skill("cure",40);
	set_skill("dagger",20);
	set_skill("move",70);
	set_skill("force",120);
	set_skill("magic",20);
	set_skill("dodge",80);
	set_skill("parry",60);
	set_skill("poison",20);
	set_skill("staff",50);
	set_skill("stick",50);
	set_skill("sword",60);
	set("functions/enforceup/level",30);
	set("functions/kee-wind/level",30);
	set_skill("throwing",60);
	set_skill("spells",20);
	set_skill("unarmed",100);
	set_skill("whip",40);
	set("force_factor",10);
	set_skill("parry",60);
	set_skill("snowforce",100);
	map_skill("force","snowforce");
	set_skill("black-steps",80);
	set_skill("snow-martial",100);
	map_skill("unarmed","snow-martial");
	map_skill("dodge","black-steps");
	set("chat_chance_combat",60);
	set("chat_msg_combat",({
	(: exert_function, "enforceup" :),

	(: perform_action, "unarmed.kee-wind" :)
	}));
	setup();
          create_family("雪蒼派",4,"掌門人");
	carry_object(SNOW_OBJ"stone");
        carry_object(SNOW_OBJ"figring")->wield();
	carry_object(SNOW_OBJ"liucloth")->wear();
}

void init()
{
	object me = this_player();
	if( me->query("quests/kill-dugur") && !me->query("quests/cure-star") )
		call_out("do_check",1,me);
      add_action("do_say","say");
	add_action("do_nod","nod");
	add_action("do_join","join");
}

void attempt_apprentice(object ob)
{
	if(this_player()->query("class")!="fighter")
	{
		command("say 你不是武者﹐我不能收你。\n");
		return;
	}
      if((int)ob->query_str()<20) {
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
    if (str=="黃雲")  this_player()->set_temp("say_1",1);
    if (str=="陳蝶衣")    this_player()->set_temp("say_2",1);
    if (str=="復活邪神")  this_player()->set_temp("say_3",1);
    if(this_player()->query_temp("say_1")==1&&this_player()->query_temp("say_2")==1&&this_player()->query_temp("say_3")==1)
     {
      command("smile");
        command("say 你果然是有緣人。\n");
      command("drop stone");
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
	HIC "天生英才.....\n\n一代武者"+this_player()->name()+"誕生了 !!!\n" NOR,users());
	return 1;
}
