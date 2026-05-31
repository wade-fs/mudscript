inherit BULLETIN_BOARD;

void create()
{
        set_name("仙劍派密言版",({"swordsecret board", "board"}));
        set("location","/open/gsword/room/eqroom");
        set("board_id","swordsecret");
        set("long",     "仙劍派留言版。\n");
        setup();
        set("capacity", 80);
    set("master",({"roger"}));
}
