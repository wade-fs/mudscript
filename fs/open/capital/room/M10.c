// Room: /open/capital/room/M10.c

inherit ROOM;

void create ()
{
  set ("short", "達布政司");
  set ("long", @LONG
達布政司, 專門管理城內柴米油鹽醬醋茶以及房屋租售的問題，若
你想買個家，這裡將會提供你完整的資訊。
    牆上掛著一幅布告(note)。

LONG);

set("item_desc", ([
"note" : "ㄜ...還沒有巫師開始寫耶, 不好意思。  :P\n",
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"r58",
]));
  set("light_up", 1);

  setup();
}
