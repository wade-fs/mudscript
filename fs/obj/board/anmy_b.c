// board.c
inherit BULLETIN_BOARD;
 
void create()
{
    set_name("小嵐美眉的留言版", ({ "board" }) );
    set("location", "/u/a/anmy/workroom");
    set("board_id", "anmy_b");
    set("long", "呵,有意見請提出來吧..\n" );
    setup();
    set("capacity", 50);
    set("master",({ "anmy" }) );
}
