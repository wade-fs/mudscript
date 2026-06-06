// Room: /u/p/pokai/room/wu/tower3-1.c
inherit ROOM;

void create()
{
  set ("short","武威七殺塔三樓--");
  set ("long", @LONG
剛踏上這一層樓，你的視線就被一股深藍色所佔滿。這一層的四周牆壁，已經
不再是剛剛的那種暗紅，而是漆上了一種令人不寒而慄的深藍；加上斑駁的血印，
使剛剛那股肅殺的氣氛又籠罩在你身上。你注意到南邊的牆上有一些小小的刮痕，
似乎是一些小字(words)。
LONG);

  set("light_up", 1);
  set("item_desc", ([ /* sizeof() == 1 */
  "words" : @LONG

    我 血風戰狂 競破峰 乙丑年登塔於此，勢如破竹，嘆無敵於天下　！！
        
LONG,
]));
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"tower3-2",
  "down" : __DIR__"tower2-3",
]));
  setup();
}
