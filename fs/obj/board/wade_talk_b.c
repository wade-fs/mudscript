inherit BULLETIN_BOARD;

void create()
{
	set_name("麵包版", ({ "board" }) );
	set("location", "/u/w/wade/room/talkroom");
	set("board_id", "wade_talk_b");
	set("long",	"天聽自我民聽，眾朋友有話就留，沒話快滾\n");
	setup();
	set("capacity", 30);
}
