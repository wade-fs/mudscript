inherit BULLETIN_BOARD;

void create()
{
        set_name("市集小組專用留言板", ({ "board" }) );
        set("location", "/u/n/nucu/market/markroom");
        set("board_id", "market_b");
        set("long",     "這是一個專供人市集小組言記事的留言板。\n" );
        setup();
        set("capacity", 30);
        replace_program(BULLETIN_BOARD);
}
