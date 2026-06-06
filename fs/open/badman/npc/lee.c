// lee.c by oda

#include "/open/open.h"

inherit NPC;

void create()
{
	set_name("李大嘴", ({ "lee da tswei", "lee", "da", "tswei" }) );
	set("nickname", "不吃人頭");
	set("class", "bandit");
	set("attitude", "badman");
	set("gender", "男性");
	set("age", 40);
	set("combat_exp", 800000);
	set("long", "你看到一個相貌不凡的男子，但是他竟是江湖上人人聞之色變的恐怖魔頭\n，傳說他當年曾親手殺了自己全家妻小並吃了他們。人們稱他為『不吃人\n頭』正是戲稱他除了人頭以外什麼都吃，但是事實上他狠起來可是連人頭\n都不放過的。\n");

	set("str", 32);
	set("cor", 29);
	set("int", 22);
	set("spi", 20);
	set("cps", 22);
	set("con", 30);
	set("per", 32);
	set("max_force", 1200);
	set("force", 1200);
	set("force_factor", 10);
	set("max_gin", 1000);
	set("max_kee", 2300);
	set("max_sen", 1000);

	set_skill("badforce", 65);
	set_skill("badstrike", 85);
	set_skill("dodge", 40);
	set_skill("force", 55);
	set_skill("ghost-steps", 60);
	set_skill("move", 50);
	set_skill("parry", 60);
	set_skill("unarmed", 75);
	map_skill("force", "badforce");
	map_skill("dodge", "ghost-steps");
	map_skill("move", "ghost-steps");
	map_skill("unarmed", "badstrike");
	map_skill("parry", "badstrike");
	set("functions/evil-blade/level", 25);

	set("chat_chance_combat", 25);
	set("chat_msg_combat", ({
	(: perform_action, "unarmed.evil-blade" :),
	}));

	setup();
	add_money("gold", 10);
}

int accept_object(object who, object ob)
{
  string name, str;

  if (ob->query("name") == "腐爛的屍體") {
  command("say 小呆子 ,屍體都爛掉了 ,要怎麼吃 ?");
  return 1;
  }


  else if (ob->query("name") == "楊心婷的屍體") {
  if (who->query_temp("evilup")!=1) {
     command("say 我有叫你拿來嗎 ?不過拿也拿了 ,嘿嘿 ,謝啦");
     destruct(ob);
     return 1;
     }
  else if (who->query_temp("yang")!=1) {
     command("say 你這小子倒真會討我歡心 ,謝啦");
     destruct(ob);
     return 1;
     }
  else if (who->query("quests/evilup")) {
     command("say 教都教了還想幹嘛 ?");
     destruct(ob);
     return 1;
     }
  else {
  who->set("quests/evilup",1);
  command("say 不錯不錯 ,倒挺香的 !好啦 ,就教你一招內功\吧!!!");
  tell_object (who, "你心一震 ,全身殺氣忽然向外一散 ,你的殺意提高了!!!(evilup)\n");
  destruct(ob);
   return 1;
  }
 }
  else if (ob->query("name") == "郭嘯風的屍體") {
  if (who->query_temp("evilup")!=1) {
     command("say 我有叫你拿來嗎 ?不過拿也拿了 ,嘿嘿 ,謝啦");
     destruct(ob);
     return 1;
     }
  else if (who->query_temp("kou")!=1) {
     command("say 你這小子倒真會討我歡心 ,謝啦");
     destruct(ob);
     return 1;
     }
  else if (who->query("quests/evilup")) {
     command("say 教都教了還想幹嘛 ?");
     destruct(ob);
     return 1;
     }
  else {
  who->set("quests/evilup",1);
  command("say 很好很好 ,嗯 ,倒挺順口的!!!好傢伙 ,就傳你一招吧 !");
  tell_object (who, "你心一震 ,全身殺氣忽然向外一散 ,你的殺意提高了!!!(evilup)\n");
  destruct(ob);
  return 1;
  }
 }
  else if (ob->query("name") == "陳玄龍的屍體") {
  if (who->query_temp("evilup")!=1) {
     command("say 我有叫你拿來嗎 ?不過拿也拿了 ,嘿嘿 ,謝啦");
     destruct(ob);
     return 1;
     }
  else if (who->query_temp("chen")!=1) {
     command("say 你這小子倒真會討我歡心 ,謝啦");
     destruct(ob);
     return 1;
     }
  else if (who->query("quests/evilup")) {
     command("say 教都教了還想幹嘛 ?");
destruct(ob);
     return 1;
     }
  else {
  who->set("quests/evilup",1);
  command("say 嗯 ,味道好吃極了 !不料你這次做的挺不錯的 ,好!!就教你這麼一招!!!");
    tell_object (who, "你心一震 ,全身殺氣忽然向外一散 ,你的殺意提高了!!!(evilup)\n");
    destruct(ob);
    return 1;
  }
 }
  else {
  command("say 笨蛋 !叫你拿的又不是這些傢伙的 ,當我沒吃過嗎 ?");
  return 1;
  }
  return 1;
}
 
