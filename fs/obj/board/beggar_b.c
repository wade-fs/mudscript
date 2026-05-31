inherit BULLETIN_BOARD;

void create()
{
        set_name("丐幫乞示板", ({ "board" }) );
        set("location","/open/beggar/room/beg2/main");
        set("board_id", "beggar_b");
        set("long",     "若有什麼武林大事，請將之佈告在此。\n" );
        setup();
        set("capacity",100);
        set("master",({"pana"}));
}
