// common_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("風流才子留言板", ({ "board" }) );
	set("location", "/u/l/lys/workroom");
	set("board_id", "lysboards");
	set("long",	"這是一個供人留言記事的留言板。\n" );
	setup();
	set("capacity", 30);
	set("master",({ "lys" }) );
}
