// neverend_b.c
inherit BULLETIN_BOARD;

void create()
{
	set_name("[1;36m自由[1;32m隨風[0m", ({"dream board","dream","board"}));
	set("location","/u/n/neverend/workroom");
	set("board_id","neverend_b");
	set("long","[1;33m自由的心  任由飄盪 ～\n\t[1;36m自在的心  任由流轉 ～\n\t\t[1;33m迎著風  自由自在 ～\n\t\t\t[1;36m隨著綠  飄盪流轉 ～ \n[0m\n");
	setup();
	set("capacity", 500);
	set("master",({"neverend"}));
}
