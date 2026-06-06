// Room: /u/d/dhk/questsfan/rm10
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "日日甘霖");
  set ("long", @LONG
這兒是一座樹種繁雜，高大的樹林。但是這座樹林最大的特色
確是沒有一刻停止的小雨，所以這座樹林的別稱就叫〝日日甘霖〞
。傳說這兒日日不停的雨是因為雨神有一次在此地休息，因為太熱
所以讓此地下一場小雨，但是他休息完卻匆匆離去，竟沒有讓這場
雨停止。所以從此這裡的雨便沒停過。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/man" : 2,
]));
  set("outdoors", "/u/d");
  set("exits", ([ /* sizeof() == 4 */
  "westdown" : __DIR__"rm9",
  "westup" : __DIR__"rm17",
  "eastup" : __DIR__"rm11",
  "northup" : __DIR__"rm18",
]));

  setup();
}
