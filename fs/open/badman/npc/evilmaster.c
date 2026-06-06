// evilmaster.c by oda

#include "/open/open.h"
#include <ansi.h>

inherit NPC;

void create()
{
	seteuid(geteuid());
	set_name("原始天魔", ({ "evil master", "evil", "master" }) );
	set("title", "惡人谷開山祖師");
	set("gender", "男性");
	set("age", 25);
	set("class", "bandit");
	set("attitude", "badman");
	set("combat_exp", 2000000);
	set("long", @LONG
他就是傳說中惡人谷的大魔頭－原始天魔，藉由天魔金身的幫助，
使得已經上百歲的他看起來仍只有二三十歲的樣子。自從百年前與
天帝之戰挫敗後，便一直待在惡人谷中潛心修煉。直到二十年前十
大惡人入谷之後，與原始天魔展開激戰，整整打了三天三夜，原始
天魔以寡擊眾將十大惡人全數收服，成立了今天的惡人谷，並將惡
化魔功傳予十大惡人。
LONG );

	set("str", 40);
	set("cor", 40);
	set("int", 40);
	set("spi", 40);
	set("cps", 15);
	set("con", 40);
	set("per", 30);
	set("max_kee", 5000);
	set("max_force", 5000);
	set("force", 5000);
	set("force_factor", 20);

	set_skill("dodge", 60);
	set_skill("ghost-steps", 80);
	set_skill("force", 100);
	set_skill("badforce", 100);
	set_skill("move", 60);
	set_skill("unarmed", 100);
	set_skill("badstrike",100);
	map_skill("unarmed", "badstrike");
	map_skill("force", "badforce");
	map_skill("dodge", "ghost-steps");
	map_skill("move", "ghost-steps");

	set("inquiry", ([
	"天魔金身":	"想學天魔金身？我得先測試看看你有沒有這個資質！",
	]));

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
	}) );

	setup();
}
