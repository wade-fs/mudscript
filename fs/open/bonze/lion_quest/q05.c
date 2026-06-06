inherit ROOM;
#include <room.h>
#include <ansi.h>
#include "bonze.c" //使用共用檔案的話 則函數不能重複 且因為不是系統檔案 所以不需要<>的括號
//例如：重新編譯 /u/b/blazakira/bonzee/room/q01.c﹕編譯時段錯誤﹕/u/b/blazakira/bonzee/room/q01.c line 57: Redeclaration of function init. <===
//　　　編譯時段錯誤﹕/u/b/blazakira/bonzee/room/q01.c line 102: Redeclaration of function do_check. <===
//兩個檔案不能重複相同的函數名稱 如：init & do_check

void create ()
{
  set ("short", "駐地門口");
  set ("long", @LONG
眼前有兩位雄赳赳、氣昂昂的武者英武不凡，身形筆挺，雙目有神
一臉肅容地注視前方。看著這兩位身上散發出來的殺氣，使得平淡無奇
的柵門帶上一點肅殺的色彩。

LONG);

  set("light_up", 1); //有光 因為是門口 固定有人站崗所以有光
  set("outdoors", "/u/b");
  set("no_transmit",1);
  set("exits", ([ /* sizeof() == 2 */
	"north" : __DIR__"q04.c",
	"west" : __DIR__"i04.c",
    "south" : __DIR__"q25.c",
	]));
//需注意就是門一定要在兩邊同時定義
//  set("need_key/east",1);       //設定door的房向及key哦 不設定此行就無須鑰匙
  create_door("west",YEL + "駐地柵門" + NOR,"east",DOOR_CLOSED);
  set("item_desc", ([ /* sizeof() == 1 */
  "west" : (: look_door,     "west" :),
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/b9_fighter.c" : 2,
  ]));
  setup();
}

//測試是否會隨物件rb而自動關上
void reset()
{
	close_door("west"); //只需要方向 close_door("方向");
	::reset();
}
