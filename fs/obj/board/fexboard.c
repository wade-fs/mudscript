//Code by Fex ..

inherit BULLETIN_BOARD;

void create()
{
        set_name("武館巫師討論板", ({ "board" }) );
        set("location", "/open/wu/hall/wizroom" );
        set("board_id", "fexboard");
        set("long",
                "這是一個武館巫師專用的佈告欄, 供本Group巫師使用\n"
                ", 巫師可將問題或是特殊寫作技巧貼上來,Hitler有空會\n"
                "將討論出之精華整理成冊..供更多巫師參考..cccc...\n");
        setup();
        set("capacity", 50);
        // replace_program(BULLETIN_BOARD);
	// 設這樣就能讓那些人 discard post 囉, 
	// 這是 wade 新增功能 11/22/1995
	set("master", ({"hitler","oda"}) );
}
