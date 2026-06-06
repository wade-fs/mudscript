// Room: /u/w/wade/room/test.c
// 相對應的鑰匙放在 /u/w/wade/obj/key.c
// 房間需 #include <room.h>
// 房間需設定 set("need_key/方向", 1)
// create_door() 須放在 set("exits"....) 之後
// 鎖的相關命令是 lock/unlock, 請用 help lock/unlock 去得到相關訊息
inherit ROOM;
#include <room.h>
#include <ansi.h>
#include "bonze.c" //使用共用檔案的話 則函數不能重複 且因為不是系統檔案 所以不需要<>的括號
//例如：重新編譯 /u/b/blazakira/bonzee/room/q01.c﹕編譯時段錯誤﹕/u/b/blazakira/bonzee/room/q01.c line 57: Redeclaration of function init. <===
//　　　編譯時段錯誤﹕/u/b/blazakira/bonzee/room/q01.c line 102: Redeclaration of function do_check. <===
//兩個檔案不能重複相同的函數名稱 如：init & do_check

void create ()
{
  set ("short", "營地北門");
  set ("long", @LONG
眼前緊閉的大門似乎不希望閒雜人等都來湊熱鬧，影響到各門派的
利益，是以出了這門口後，似乎隨時都有被人偷襲的可能性。

LONG);

  set("light_up", 1);
//  set("outdoors", "/u/b");
  set("no_transmit",1);
  set("exits", ([ /* sizeof() == 2 */
    "north" : __DIR__"q06.c",
    "east" : __DIR__"i02.c",
    "south" : __DIR__"i06.c",
	]));
//需注意就是門一定要在兩邊同時定義
//  set("need_key/east",1);       //設定door的房向及key哦 不設定此行就無須鑰匙
  create_door("north",YEL + "駐地柵門" + NOR,"south",DOOR_CLOSED);
  set("item_desc", ([ /* sizeof() == 1 */
  "north" : (: look_door,     "north" :),
]));

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/b9_gblade_blademan.c" : 1,
  ]));

  setup();
}

//測試是否會隨物件rb而自動關上
void reset()
{
	close_door("north"); //只需要方向 close_door("方向");
	::reset();
}
