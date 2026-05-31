inherit BULLETIN_BOARD;
								
void create()
{
	set_name("瀧山派留言版",({"lungshan board","board"}));
    set("location","/open/wu/room/luroom18.c");
	set("board_id","lungshan");
          set("long","瀧山派留言版\n");
	setup();
	set("capacity", 30);
            set("master",({"hitler","bigcat","ccat","wade"}));
}
							
