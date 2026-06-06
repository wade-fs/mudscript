// buffalo.c by oda

#include "/open/open.h"
inherit NPC;

void create()
{
	set_name("水牛", ({ "Buffalo", "buffalo" }) );
	set("race", "野獸");
	set("age", 12);
	set("long", "這隻水牛正默默的在田裡辛苦的犁田。\n");

	set("str",20);
	set("con",20);
	set("max_gin",140);
	set("max_kee",140);
	set("max_sen", 100);

	set("limbs", ({ "身體", "犄角", "前腳", "後腿", "尾巴" }) );
	set("verbs",({"hoof","bite","dunt"}) );

	set("combat_exp", 60);

	setup();
	carry_object(START_OBJ"item");
}
