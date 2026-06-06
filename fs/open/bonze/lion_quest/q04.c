inherit ROOM;
#include "bonze.c" //使用共用檔案的話 則函數不能重複 且因為不是系統檔案 所以不需要<>的括號
//例如：重新編譯 /u/b/blazakira/bonzee/room/q01.c﹕編譯時段錯誤﹕/u/b/blazakira/bonzee/room/q01.c line 57: Redeclaration of function init. <===
//　　　編譯時段錯誤﹕/u/b/blazakira/bonzee/room/q01.c line 102: Redeclaration of function do_check. <===
//兩個檔案不能重複相同的函數名稱 如：init & do_check

void create ()
{
  set ("short", "林間小徑");
  set ("long", @LONG
這是一條通往後山的林間小徑。濃密的樹蔭，與自然發散濃郁
的芬多精，讓你覺得身心愉快。

　　你遠遠看到一座兵營與巡邏的人員，你猜測裡面似乎有某派的
重要人物在營地裡。

LONG);

//  set("light_up", 1);
  set("outdoors", "/u/b");
  set("no_transmit",1);
  set("exits", ([ /* sizeof() == 2 */
    "east" : __DIR__"q03.c",
    "south" : __DIR__"q05.c",
	]));

  setup();
}
