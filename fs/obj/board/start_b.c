// start_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("酸甜苦辣留言板",({ "board" }) );
    set("location", "/open/trans/room/room4");
	set("board_id", "start_b");
	set("long","\t這是一個讓玩家表達意見的留言版\n");
	setup();
    set("capacity", 300);
}
