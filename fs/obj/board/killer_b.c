// chen_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("黑名單",({"black board","board"}));
	set("location","/open/killer/room/r3");
	set("board_id","killer_b");
	set("long","這是一分殺手用來記事的黑名單。\n");
	setup();
	set("capacity", 30);
	// replace_program(BULLETIN_BOARD);
}
