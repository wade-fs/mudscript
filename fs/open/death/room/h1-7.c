// Room: /open/death/room/h1-7
inherit ROOM;

void create ()
{
  set ("short", "第一殿--通道");
  set ("long", @LONG
你走進這裡，南方不遠處所傳來的陣陣慘叫聲不斷的震撼著你，不
用懷疑，地獄近了....只見身旁的鬼卒都不懷好意的對你笑著，臉上的
表情彷彿是說:『嘿嘿 ! 你死定了！』
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"h1-2",
  "east" : __DIR__"h1-6",
]));
  set("light_up", 1);

  setup();
}
