// assassin.c by borstquc

inherit BULLETIN_BOARD;

void create()
{
        set_name("來來專用版",({"board"}));
        set("location","/u/a/assassin/workroom");
        set("board_id","assassin");
        set("long", @LONG
這是舞者巫師來來的專用版
                                                fs borstquc
LONG);
        setup();
        set("capacity", 100);
}
