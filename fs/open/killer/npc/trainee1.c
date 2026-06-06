#include "/open/open.h"
inherit NPC;
void create()
{
	set_name("初級練習生", ({ "trainee" }) );
	set("title", "黑牙聯");
	set("gender", "男性");
	set("long", "這是殺手最下級的練習生。\n");
	set("age",12);
	set("attitude", "heroism");
	set("kee",400);
	set("max_kee",400);
	set("combat_exp",1000);
	setup();
}
