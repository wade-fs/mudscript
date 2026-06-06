// down.c by oda

#include "/open/open.h"

inherit NPC;

void create()
{
	set_name("歐陽當", ({ "oyawn down", "oyawn", "down" }) );
	set("nickname", "寧死不吃虧");
	set("gender", "男性");
	set("age", 41);
	set("long", "這個人瘦骨嶙峋，雙顴凸出，一付富商大賈的打扮，是歐陽丁的巒生兄弟。\n");

	set("str", 24);
	set("cor", 24);
	set("int", 29);
	set("spi", 25);
	set("cps", 22);
	set("con", 25);
	set("per", 27);
	set("combat_exp",112);

	setup();
}
