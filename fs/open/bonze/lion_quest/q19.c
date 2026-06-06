inherit ROOM;
#include <room.h>
#include <ansi.h>
#include "bonze.c"

void create ()
{
  set ("short", "林間小徑");
  set ("long", @LONG
這是一條通往後山的林間小徑，茂密的矮樹叢與高大原始的山林是
這裡的主色調。風景絕佳景色優美，放眼望去鳥語花卉美不勝收，偶爾
會在這裡巧見樹蛙、蝴蝶、飛鷹…等原生生態下活躍的生物。

LONG);

  set("light_up", 1);
  set("outdoors", "/u/b");
  set("no_transmit",1);
  set("exits", ([ /* sizeof() == 2 */
    "west" : __DIR__"q18.c",
    "down" : __DIR__"underg.c",
	]));
//需注意就是門一定要在兩邊同時定義 並宣告兩個變數#include <room.h> #include <ansi.h>

  set("need_key/east",1);       //設定door的房向及key哦 不設定此行就無須鑰匙只是單純鎖上而已(DOOR_LOCKED)
//可宣告 四種 DOOR_OPENED;DOOR_CLOSED;DOOR_LOCKED;或是只有宣告門存在而已 參考// Room: /u/w/wade/workroom.c
  create_door("down",HIB"鐵門"NOR,"up",DOOR_LOCKED);
  set("item_desc", ([ /* sizeof() == 1 */
  "down" : (: look_door,     "down" :),
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/b_bonze_du_e.c" : 1,
  __DIR__"npc/b_bonze_du_jie.c" : 1,
  __DIR__"npc/b_bonze_du_nan.c" : 1,
  __DIR__"npc/junkman.c" : 1, //拾荒老頭
//  "/open/main/npc/junkman.c" : 1, //拾荒老頭
  ]));

  setup();
}

/*
void reset()
{
	::reset();
}
*/