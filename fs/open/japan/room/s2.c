inherit ROOM;

void create ()
{
  set ("short", "不知名的空間");
  set ("long", @LONG
這是一個神祕的地方，四周不斷的有人影在閃動
你能感覺到你來到一個未知的空間，並且被監視中，
或許迅速離開這個地方是你最好的選擇。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"s1",
  "north" : __DIR__"s2",
  "west" : __DIR__"s1",
  "east" : __DIR__"s3.c",
]));

  setup();
}
