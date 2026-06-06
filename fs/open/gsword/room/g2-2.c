// Room: /open/gsword/room/g2-2.c
inherit ROOM;

void create ()
{
  set ("short", "藥房");
  set ("long", @LONG
這是一間小小的藥房 ,一個檀香木做成的大木櫃擺在東側 ,木櫃畫分
成許多抽屜 ,分別存放著各種藥材 ,種類之齊全 ,令人咋舌 ,真是麻雀雖
小 ,五臟俱全 .

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : "/open/gsword/room/g2-4",
]));

  set("light_up", 1);

  set("objects", ([ /* sizeof() == 2 */
   "/open/gsword/npc/boy-1":1,
   "/open/gsword/npc/doctor":1,
]));

  setup();
}
