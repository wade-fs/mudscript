inherit ROOM;

void create ()
{
  set ("short", "大雄寶殿");
  set ("long", @LONG
這裡是大雄寶殿中的偏殿,往西走就是天龍寺大佛的所在地,天龍
寺的大佛高八米,以阿里山神木雕成,聽說向大佛祈禱還能有平息心中
殺意的功效。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"aa40",
  "west" : __DIR__"aa42",
]));
}
