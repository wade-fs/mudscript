
inherit ROOM;

void create ()
{
  set ("short", "樹叢小徑");
  set ("long", @LONG
你感覺似乎走了好久，剛剛看到的那座塔就在不遠的地方啦！你發覺這四週的
花草樹木已不像剛剛那些地方那樣濃密了。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"road1",
  "east" : __DIR__"road3",
]));
set("objects", ([ /* sizeof() == 2 */
"/open/tendo/room/tower/npc/genies.c" : 2,
]));
  set("outdoors", 1);

  setup();
}


