// Room: /u/r/ranko/garden2.c
inherit ROOM;

void create ()
{
  set ("short", "毒園外圍");
  set ("long", @LONG
這裡是毒園外圍部份,此處所種的都是尋常可見的毒花,毒草和
剛才見到的並沒甚麼差別.值得一提的是,由於那些毒花毒草的影響
,吸引了不少毒物在此聚集。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"garden7.c",
  "west" : __DIR__"garden6.c",
  "east" : __DIR__"garden2-1.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/snake.c" : 1,
]));
  set("light_up", 1);

  setup();
}
