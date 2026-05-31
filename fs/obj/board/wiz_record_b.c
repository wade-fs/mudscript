inherit BULLETIN_BOARD;

void create()
{
	set_name("錄音室", ({ "board" }) );
	set("location", "/open/wiz/meeting");
	set("board_id", "wiz_record_b");
	set("long",	"\n");
	setup();
	set("capacity", 100);
	// 設這樣就能讓那些人 discard post 囉
	set("master", ({"wade", "chan"}) );
}
