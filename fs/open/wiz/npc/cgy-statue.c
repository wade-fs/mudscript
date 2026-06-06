inherit NPC;
#include <ansi.h>
void create()
{
	set_name("傅劍寒的雕像",({"cgy statue","cgy"}));
	set("long","狂想之神。狂想的玩家為了能瞻仰他，紀念他的德行，所以特別建立了此一雕像。\n你可以試著(pray id)也許\有奇妙的效果喔!!\n");
	set("title",HIR"惡魔城主"NOR);
	set("nickname",HIW"神"HIG"劍"HIC"飛"HIY"龍"NOR);
	set("unit","尊");
	set("age",291);
	set("value",100);
	set("no_get",1);
	set("no_kill",1);
	set("no_fight",1);
	set("no_sac",1);
	set("no_auc",1);
	set("env/can_tell_wiz","YES");
	set("no_reset",1);
	set_weight(500000);
	setup();
}

init()
{
	add_action("do_pray","pray");
}

int do_pray(string arg)
{
	object me=this_player();

	call_out("greeting",2,me,arg);
	message_vision(HIW"一陣光芒籠罩$N"HIW"的全身，光芒過後，已將$N"HIW"的祈禱傳送到大神的耳邊。\n"NOR,me);

	return 1;
}

void greeting(object ob,string arg)
{
	object me;
	me=this_player();
	command("tell "+arg+" "+me->query("name")+"("+me->query("id")+")傳送一份祝福的祈禱給您!!\n ");

}
