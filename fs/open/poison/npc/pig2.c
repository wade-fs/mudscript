
# include <ansi.h>
inherit NPC; 

void create()
{
	set_name("母豬",({"pig"}));
	set("long","一隻體型龐大的母豬，懶洋洋的躺在地上睡覺。");
	set("age",3);
	set("str",7);
	set("con",8);
	set("race","野獸");
	set("max_kee",70);
	set("max_gin",70);
	set("max_sen",70);
	set("limbs",({
	"頭部","身體","尾部","腹部"}) );
	set("verbs",({"bite"}) );
	set("chat_chance", 4);
	set("chat_msg",({
}) );
	set("combat_exp",100);
	setup();
}
void greeting(object me)
{
	if (!me || environment(me) !=environment()) return;
{
	command("fool "+me->query("id"));
}
}
