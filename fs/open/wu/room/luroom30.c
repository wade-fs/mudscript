// Room: /open/wu/room/luroom30
// 瀧山任曉吟雅築
inherit ROOM;
void create ()
{
  set ("short", "曉吟雅築");
  set ("long", @LONG
才剛剛進屋，你就聞到一股淡雅的清香。
這裡是館主獨生女任曉吟的閨房，你可以看到這兒有一套紅杉雕成的
桌椅，以及一張鑲有翠玉的梳妝台，台上擺著各式各樣的髮飾，梳妝
台邊是一張素淨的單人床。看到床上摺疊整齊的被褥，你不禁想到自
己今早忘了摺棉被啦！
LONG);
  set("exits", ([ /* sizeof() == 1 */
  "south" : "/open/wu/room/luroom29",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/wu/npc/sheau-yin" : 1,
]));
  set("light_up", 1);
  setup();
}
