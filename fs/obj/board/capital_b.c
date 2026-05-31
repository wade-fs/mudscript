inherit BULLETIN_BOARD;

void create()
{
        set_name("京城事務板",({"capital board", "board"}));
        set("location","/open/wiz/caproom");
	set("board_id","capital_b");
        set("long","京城區域討論專用, 宣布事情或修改什麼, 都是在這兒。\n");
        setup();
        set("capacity", 30);
}

