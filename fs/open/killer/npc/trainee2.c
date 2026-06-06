#include "/open/open.h"
inherit NPC;
void create()
{
	set_name("練習生", ({ "trainee" }) );
	set("title", "黑牙聯");
	set("gender", "男性");
	set("long", "這是殺手的練習生。\n");
	set("age",12);
	set("attitude", "heroism");
	set("kee",450);
	set("max_kee",450);
	set("combat_exp",4000);
	setup();
}
