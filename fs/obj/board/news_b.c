inherit BULLETIN_BOARD;

void create()
{
        set_name("新聞公告區",({"news board", "board"}));
        set("location","/open/common/room/inn");
        set("board_id","news_b");
        set("long","此處為新聞公告區\n");
        set("wiz_post",1);
        setup();
set("capacity", 50);
set("master",({"adam","xboy"}));
}

