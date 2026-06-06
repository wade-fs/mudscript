// Room: /open/badman/room/b14
inherit ROOM;

void create ()
{
  set ("short", "惡人谷南街");
  set ("long", @LONG
當你自北向南轉進此處，正如普通小城鎮一般，映入你眼簾的
是一幢幢普通的民宅。而大概是眾人只想有個能遮風避雨之處吧，
這裡多數的房子皆顯得有些簡陋，不過卻是居民們在惡人谷的安身
立業之所。
    西邊傳來陣陣的么喝聲，好像是惡人谷的練武場.

LONG);

  set("objects", ([ /* sizeof() == 2 */
  "/open/badman/npc/three.c" : 1,
  "/open/badman/npc/six.c" : 1,
]));
  set("outdoors", "/open/badman");
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"r6",
  "north" : __DIR__"b4",
  "south" : __DIR__"b15",
]));

  setup();
}
