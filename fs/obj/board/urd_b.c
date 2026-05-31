// carol_b.c
inherit BULLETIN_BOARD;

void create()
{
    set_name("兀兒德女王留言板", ({"board"}));
    set("location","/u/u/urd/workroom");
	set("board_id","urd_b");
	set("long","敢灌水的準備挨暴雷降臨跟魔藥吧..呵呵呵...\n");
    setup();
    set("capacity", 30);
	set("master",({"urd"}));
}
