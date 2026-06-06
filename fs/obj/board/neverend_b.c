// neverend_b.c
inherit BULLETIN_BOARD;

void create()
{
	set_name("自由隨風", ({"dream board","dream","board"}));
	set("location","/u/n/neverend/workroom");
	set("board_id","neverend_b");
	set("long","自由的心  任由飄盪 ～\n\t自在的心  任由流轉 ～\n\t\t迎著風  自由自在 ～\n\t\t\t隨著綠  飄盪流轉 ～ \n\n");
	setup();
	set("capacity", 500);
	set("master",({"neverend"}));
}
