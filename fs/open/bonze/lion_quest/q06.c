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
從此門出去就是通往少林後山深處的小徑，平常鮮少有人進出，不
過自從少林叛徒將後山的秘密洩漏之後，就變得熱鬧不少。

LONG);

//  set("light_up", 1);
  set("outdoors", "/u/b");
  set("no_transmit",1);
  set("exits", ([ /* sizeof() == 2 */
    "north" : __DIR__"q07.c",
    "east" : __DIR__"q28.c",
    "west" : __DIR__"q29.c",
    "south" : __DIR__"i03.c",
	]));
//需注意就是門一定要在兩邊同時定義
//  set("need_key/east",1);       //設定door的房向及key哦 不設定此行就無須鑰匙
  create_door("south",YEL + "駐地柵門" + NOR,"north",DOOR_CLOSED);
  set("item_desc", ([ /* sizeof() == 1 */
  "south" : (: look_door,     "south" :),
]));
  setup();
}
//測試是否可以阻擋移動之npc
int valid_leave(object me, string dir)
{
	if (dir=="east" && me->query_temp("quests/bonze/mob") == 1) //如果要往east離開 且 有mark ("quests/bonze/mob") 時 阻擋之!
//	if(!wizardp(me)) //本次設定只針對npc 所以不影響巫師行動
		return notify_fail("STOP!\n");
	return ::valid_leave(me,dir); //為valid_leave(me,dir)函數的結尾
}

void reset()
{
	close_door("south"); //只需要方向 close_door("方向");
	::reset();
}
