inherit BULLETIN_BOARD;

void create()
{
set_name("笨蛋專用版", ({ "board" }) );
set("location", "/u/n/naleca/workroom");
set("board_id", "naleca_b");
set("long",     "笨蛋記錄工作專用\n");
	setup();
	set("capacity", 30);
	// 設這樣就能讓那些人 discard post 囉
set("master", ({"naleca"}));
}
