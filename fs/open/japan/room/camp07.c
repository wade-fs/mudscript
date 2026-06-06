inherit ROOM;

void create()
{
  set ("short", "隊士休息室");
  set ("long", @LONG
長長的通舖上，依舊收拾著相當整齊。不過房間內還是隱隱傳來
陣陣的汗臭味。足見守備隊除了平常巡邏之外，日常的操課也是進行
的相當精實。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 1 */
    "east" : __DIR__"camp04.c",
  ]));
  setup();
}
