inherit BULLETIN_BOARD;

void create()
{
	set_name("CHAD's Board", ({ "board" }) );
	set("location", "/u/c/chad/workroom");
	set("board_id", "chad_b");
	set("long",	"為son所設置\n");
	setup();
        set("capacity", 300);
	// 設這樣就能讓那些人 discard post 囉
	set("master", ({"chad", "ice"}) );
}
