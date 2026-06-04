//master of cure
//增加進入廚房的線索 by blazakira 2011/3/7
//增加年齡 by blazakira 2012/8/19

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string mission1();
string mission2();

void create()
{
  set_name("慈恩聖僧",({"master of bonze","master","bonze"}) );
  set("long",@LONG
        少林寺現任方丈，為一位慈藹的僧人，度化無數誤入
        歧途的邊緣人，故得此聖僧的稱號。
LONG );
  set("gender", "男性" );

  set("class","bonze");
  set("guild_master",1);

  set("age",70);
  set("combat_exp",5000000);
  set("force",40000);
  set("max_force",15000);
  set("force_factor",20);
  set("max_gin",15000);
  set("max_sen",15000);
  set("mana",200);
  set("max_mana",200);
  set("max_atman",200);
  set("atman",200);
  set("quests/saulin-kee",1) ;
  set("quests/yu-steps",1);
  set_skill("array",80);
  set_skill("blade",80);
  set_skill("sword",80);
  set_skill("cure",60);
  set_skill("force",80);
  set_skill("spells",20);
  set_skill("magic",20);
  set_skill("move",60);
  set_skill("parry",80);
  set_skill("staff",120);
  set_skill("stick",120);
  set_skill("literate",40);
  set_skill("unarmed",80);
  set_skill("dodge",60);
  set("max_kee",25000);
  set_skill("buddhism",100);
  set_skill("rulai",100);
  set_skill("saulin-kee",100);
  set_skill("fumostaff",100);
  set_skill("yu-steps",100);
  set_skill("ejinforce",100);
  map_skill("force","ejinforce");
  map_skill("unarmed","rulai");
  map_skill("dodge","yu-steps");
  map_skill("move","yu-steps");
  map_skill("staff","fumostaff");
  map_skill("parry","saulin-kee");

  create_family("少林派", 42, "方丈");

  set("inquiry", ([
      "拜託"            : "嗯，原來大俠也聽說敝寺要開一個【少林廚藝學院】。",
      "少林廚藝學院"    : "為了廣大的民眾需求，因此長老有交待將敝寺相傳已久的【佳餚】分享給各位。",
      "佳餚"            : "詳情請到敝寺的伙房找大廚詢問相關事項。", //相關事項不就是【少林廚藝學院】這還要給線索嗎XD
      "許\可"           : (: mission1 :),
      "水荒"            : (: mission2 :),
      "少林寺水荒"      : (: mission2 :),
  ]) );

  setup();
  carry_object(__DIR__"buddha_staff")->wield();
  carry_object(__DIR__"puty_pullium")->wear();
  all_inventory(this_object())->set("no_get",1);
}

/*
void init()
{
	add_action("do_join","join");
}

int do_join(string str)
{
	object me;
	me = this_player();
	if(str!=0)
	  return notify_fail("請打\"join\"即可。\n");
	if(me->query("class") == "bonze" )
	return notify_fail("你不要開玩笑了，你不是早就加入了嗎？\n");
	if(me->query("gender") == "女性")
	  return notify_fail("這位女施主請回吧,少林寺是不收女性的。\n");
	if( me->query("class") )
	  return notify_fail("你已經加入了別的工會了\n");
	command("say 阿彌陀佛！歡迎施主加入和尚的行列。\n");
	me->set("class","bonze");
	return 1;
}
void attempt_apprentice(object ob)
{
	if(this_player()->query("class")!="bonze")
	{
		command("sigh");
		command("say 你未入空門﹐恕老衲無德,不能收你為徒。\n");
		return;
	}else{
	command(":)");
	command("recruit "+ob->query("id"));
	}
}
*/
void die()
{
  all_inventory(this_object())->delete("no_get",1);
  ::die();
}

string mission1() //少林廚藝學院
{
  object me = this_player();
  if(me->query_temp("quests/bonze/mission") == 1) {
    me->set_temp("quests/bonze/food_pass",1);
    command("say 哎呀，老衲的記性這麼差，忘了給施主你「進入伙房的許\可」了。");
    message_vision(HIY + "只見慈恩聖僧點頭示意一旁的小沙彌，小沙彌拱手後便向廚房奔去。\n" + NOR,me);
    command("say 我已經吩咐廚房允許\讓施主進入了，還請施主見諒。");
	return "";
  }
  return "咦，你在問什麼，怎老衲不清楚。";
}

string mission2() //少林寺水荒
{
  object me = this_player();
  if(me->query_temp("quests/bonze/mission") == 1) {
    me->set_temp("quests/bonze/food_pass",1);
    command("say 哎呀，老衲的記性這麼差，忘了給施主你「進入伙房的許\可」了。");
    message_vision("只見慈恩聖僧點頭示意一旁的小沙彌，小沙彌拱手後便向廚房奔去。\n",me);
    command("say 我已經吩咐廚房允許\讓施主進入了，還請施主見諒。");
	return "";
  }
  return "老衲已經拜託周芷若施主協助了，感謝大俠拜訪。";
}
