inherit BULLETIN_BOARD;

void create()
{
	set_name("諸神傳說", ({ "board" }) );
	set("location", "/open/wiz/gs");
	set("board_id", "gods_b");
	set("long",	"諸神傳說\n");
	setup();
	set("capacity", 300);
	// 設這樣就能讓那些人 discard post 囉
	set("master", ({"wade"}) );
}
