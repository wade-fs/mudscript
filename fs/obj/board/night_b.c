// board.c
inherit BULLETIN_BOARD;

void create()
{
    set_name("戀戀情深版", ({ "night board", "board" }) );
    set("location", "/u/n/night/workroom");
    set("board_id", "night_b");
    set("long", "這個黑板是威威平常塗鴉用的,有事寫在上面他就看的到了。\n" );
    setup();
    set("capacity",100);
    set("master",({ "night" }) );
}
