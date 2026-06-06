// Room: /u/l/lum/workroom.c
inherit ROOM;
 
void create ()
{
  set ("short", "東方祠堂");
  set ("long", @LONG
  一走進來，一股特殊的氣氛籠罩在整個廟宇中，在祠堂的正中央，擺設著東方女神
拉姆的神像(Idol)，讓你有一種不可侵犯的感覺，另外四面還擺設了拉姆的四大護衛像
分別是獸魔師八雲、幻術師琉璃子、劍神面堂三四郎還有忍者邪鬼半藏。
LONG);
  set("objects", ([ /* sizeof() == 1 */
  "/u/l/lum/npc/boy" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "north" : "/open/ping/room/road1",
]));
  set("light_up", 1);
  set("valid_startroom", 1);
 
  setup();
}
