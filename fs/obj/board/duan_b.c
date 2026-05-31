inherit BULLETIN_BOARD;

void create()
{
        set_name("段家留言版",({"duan board", "board"}));
        set("location","/open/ping/room/p1");
        set("board_id","duan_b");
        set("long","段家門人打屁專用, 若要建議有關段家門派的事, 也是在這。\n");
        setup();
set("capacity", 50);
set("master",({"adam","xboy"}));
}

