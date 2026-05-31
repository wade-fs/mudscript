// tendo_b.c by borstquc

inherit BULLETIN_BOARD;

void create()
{
        set_name("天道派留言板",({"board"}));
	set("location","/open/tendo/room/start");
        set("board_id","tendo_b");
	set("long", @LONG
這裡是專門用來記錄有關天道的種種，新玩家可以在這請求幫忙(以天道派的優先)
老玩家可以在這發表玩的感想。讓後來的玩家容易上手...
LONG);
	setup();
	set("capacity", 100);
set("master",({"airke"}));
}
