// common_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("天界工作群留言版", ({ "board" }) );
	set("location", "/open/su/room/temp1");
set("board_id", "godplace_b");
	set("long",	"這是一個供天界工作人員留言的地方。\n" );
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}
