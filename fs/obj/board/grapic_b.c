inherit BULLETIN_BOARD;

void create()
{
     set_name("圖形MUD討論板", ({"board"}));
    set("location","/u/w/wade/grapic_room.c");
    set("board_id","grapic_b");
    set("long","圖形MUD討論板\n");
	setup();
	set("capacity", 300);
	// 設這樣就能讓那些人 discard post 囉
    set("master", ({"wade"}));
}
