// bad_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("惡人谷告狀版",({ "board" }) );
	set("location", "/open/badman/room/g1");
	set("board_id", "bad_b");
	set("long","\t這是一個只讓壞蛋們吐槽的留言版\n");
	setup();
	set("capacity", 50);
}
