// Room: /open/poison/room/road15
inherit ROOM;

void create ()
{
  set ("short", "前院");
  set ("long", @LONG
你來到了冥蠱魔教的前院，院內兩旁種了幾棵蒼鬱的老
松樹，松葉隨風飄落刺痛你的雙頰，中間則是由漢白玉所鋪
成的玉道，道路兩旁為碧綠柔軟的草皮，院子的北面有一雄
偉的殿堂。
LONG);

  set("outdoors", "/open/poison");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road14",
  "north" : __DIR__"room6",
]));

  setup();
}
