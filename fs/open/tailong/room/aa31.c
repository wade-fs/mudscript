inherit ROOM;

void create ()
{
  set ("short", "左側走廊");
  set ("long", @LONG
這裡是連接中庭和大雄寶殿的左側走廊,向北直走就是往大雄寶殿
的方向,往南則是中庭,往西的一條小徑則是通往一個花園。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"aa7",
  "west" : __DIR__"aa45",
  "north" : __DIR__"aa33",
]));

  setup();
  replace_program(ROOM);
}
