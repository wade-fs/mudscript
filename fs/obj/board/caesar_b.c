
inherit BULLETIN_BOARD;

void create()
{
        set_name("西薩留言版", ({ "board" }) );
        set("location", "/u/c/caesar/workroom");
        set("board_id", "caesar_b");
        set("long", "西薩的留言版，紀錄重要留言用。\n");
        setup();
        set("capacity", 100);
}
