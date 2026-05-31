// common_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("功\德簿", ({ "board" }) );
	set("location", "/open/su/room/temple/temple");
	set("board_id", "temple_b");
	set("long",	"這是一個供人簽名留念的功\德簿。\n" );
	setup();
	set("capacity", 30);
}
