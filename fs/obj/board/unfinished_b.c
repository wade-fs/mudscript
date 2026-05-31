inherit BULLETIN_BOARD;

void create()
{
         set_name("黑板",({ "black board ","board"}));
        set("location","/u/u/unfinished/workroom.c");
        set("board_id","black_board");
        set("long", @LONG
塗鴉用黑板!!
LONG);
        setup();
    set("capacity", 100);
}
