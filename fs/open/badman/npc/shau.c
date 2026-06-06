// shau.c by oda

#include "/open/open.h"

inherit NPC;

void create()
{
	set_name("蕭咪咪", ({ "shau mi mi", "shau", "mi" }) );
	set("nickname", "迷死人不賠命");
	set("gender", "女性");
	set("age", 37);
	set("long", "你看到一個體態輕盈，身著輕衫綠裙，鬢邊斜插著朵山茶花的少婦。\n");
	set("attitude", "friendly");

	set("str", 23);
	set("cor", 23);
	set("int", 26);
	set("spi", 32);
	set("cps", 33);
	set("con", 21);
	set("per", 35);
	set("combat_exp", 500000);

	setup();
}
