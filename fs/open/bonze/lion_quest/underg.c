inherit ROOM;
#include <room.h>
#include <ansi.h>
#include "bonze.c" //使用共用檔案的話 則函數不能重複 且因為不是系統檔案 所以不需要<>的括號
//例如：重新編譯 /u/b/blazakira/bonzee/room/q01.c﹕編譯時段錯誤﹕/u/b/blazakira/bonzee/room/q01.c line 57: Redeclaration of function init. <===
//　　　編譯時段錯誤﹕/u/b/blazakira/bonzee/room/q01.c line 102: Redeclaration of function do_check. <===
//兩個檔案不能重複相同的函數名稱 如：init & do_check

void create ()
{
  set ("short", "地牢");
  set ("long", @LONG
測試中

LONG);
  set("no_transmit",1);
  set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"q15.c",
]));
//需注意就是門一定要在兩邊同時定義
  set("need_key/east",1);       //設定door的房向及key哦 不設定此行就無須鑰匙
  create_door("up",HIB + "鐵門" + NOR,"up",DOOR_LOCKED);
  set("item_desc", ([ /* sizeof() == 1 */
  "up" : (: look_door,     "up" :),
]));
  set("light_up", 1);

  setup();
}
