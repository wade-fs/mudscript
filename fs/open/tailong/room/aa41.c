inherit ROOM;

void create ()
{
  set ("short", "大雄寶殿");
  set ("long", @LONG
這裡是大雄寶殿中的偏殿,往東走就是天龍寺大佛的所在地,天龍
寺的大佛高八米,以阿里山神木雕成,聽說向大佛祈禱還能有平息心中
殺意的功效,西邊好像還有一間小房間,不知道裡面有什麼東東。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"aaa.c",
  "south" : __DIR__"aa38",
  "east" : __DIR__"aa42",
]));

  setup();
  replace_program(ROOM);
}
