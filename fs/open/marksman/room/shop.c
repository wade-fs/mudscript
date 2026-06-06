// Room: /crystal/fantasy/Lbird_shop.c
inherit ROOM;

#include <ansi.h>
#include <room.h>
void create ()
{
  set ("short", "長沙鎮─鳳凰買賣店");
  set ("long", @LONG
這裡是長沙鎮著名的鳳凰棲息地，它們是為了伴隨李廣而飛來這裡，
由一位小女還照顧它門，也答應當李廣門下的座騎，你若是本派門生，
即可買一隻來騎，詳情請看(sign)。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/marksman/npc/shopgirl" : 1,
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "    如果你想購買一隻鳳凰的話﹐在長沙鎮中你必須拿到鳳凰
認養執照ㄛ﹐如果你已經符合規定了﹐請遵照已下程序購買。

          1.選擇鳳凰--list.
          2.拿出錢來購買鳳凰--shop.
          3.購買鳳凰專用哨子--shop come-sum.

",
]));
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"room1-11",
]));
  set("light_up", 1);

  setup();
}
