// Room: /open/badman/room/r7
inherit ROOM;

void create ()
{
  set ("short", "警備室");
  set ("long", @LONG
你來到一個寬敞的大房間，這裡聚集了許多的盜賊嘍嘍，有的
人在休息，有的則在喝茶聊天，他們都在這裡負責機動待命的工作
，隨時準備出動。
    如果你的職位夠大的話，隨時可以在這裡找到手下供你指揮，
不然的話，乖乖當個小嘍嘍吧。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r14",
  "south" : __DIR__"b5",
]));
  set("light_up", 1);

  setup();
}
