// gfs_b.c 圖形化fs討論區

inherit BULLETIN_BOARD;

void create()
{
         set_name("圖形化fs討論版",({ "gfs board ","board"}));
        set("location","/u/w/wade/gfs");
        set("board_id","gfs_b");
	set("long", @LONG
這是一個專門討論圖形化fs的布告欄
LONG);
	setup();
    set("capacity", 300);
}
