// query_b.c

inherit BULLETIN_BOARD;

void create()
{
       set_name("記事本",({ "Alucard Note","note","board"}));
        set("location","/u/a/alucard/workroom");
        set("board_id","alucard_board");
	set("long", @LONG
記事情的記事本
LONG);
	setup();
    set("capacity", 900);
}
