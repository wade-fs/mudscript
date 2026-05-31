inherit BULLETIN_BOARD;

void create()
{
	set_name("天聽版", ({ "board" }) );
	set("location", "/u/w/wade/workroom");
	set("board_id", "wade_b");
	set("long",	"天聽自我民聽，眾巫師有話就留，沒話快滾\n");
	setup();
	set("capacity", 30);
	// 設這樣就能讓那些人 discard post 囉
	set("master", ({"wade", "ice"}) );
}
