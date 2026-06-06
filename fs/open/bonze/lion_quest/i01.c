inherit ROOM;
#include "bonze.c" //使用共用檔案的話 則函數不能重複 且因為不是系統檔案 所以不需要<>的括號
//例如：重新編譯 /u/b/blazakira/bonzee/room/q01.c﹕編譯時段錯誤﹕/u/b/blazakira/bonzee/room/q01.c line 57: Redeclaration of function init. <===
//　　　編譯時段錯誤﹕/u/b/blazakira/bonzee/room/q01.c line 102: Redeclaration of function do_check. <===
//兩個檔案不能重複相同的函數名稱 如：init & do_check

void create ()
{
  set ("short", "營地內");
  set ("long", @LONG
與其說這座營地井然有序的模樣，不如說是從該營地的門面上就可
以看出是哪個門派駐紮在此地。

LONG);

  set("light_up", 1); //營地內都有火把
//  set("outdoors", "/u/b");
  set("no_transmit",1);
  set("exits", ([ /* sizeof() == 2 */
    "west" : __DIR__"i02.c",
    "south" : __DIR__"i04.c",
	]));

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/b9_doctor_guard.c" : 1,
  ]));

  setup();
}
