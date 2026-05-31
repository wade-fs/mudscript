// bad_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("壞蛋巫師放話板",({ "board" }));
	set("location", "/open/badman/room/wizroom");
	set("board_id", "badwiz_b");
	set("long","\t看啥?!沒被壞人打過是不是? :b\n");
	setup();
	set("capacity", 50);
}
