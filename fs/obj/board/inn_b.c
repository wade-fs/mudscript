inherit BULLETIN_BOARD;

void create()
{
	set_name("道聽途說板",({"who says board","board"}) );
	set("location","/open/capital/room/inn");
	set("board_id","inn_b");
	set("long", @LONG
	這是一個讓來自各地的旅客發表見聞的
		㊣道聽途說板⊙
	
LONG);
	setup();
	set("capacity", 50);
}
