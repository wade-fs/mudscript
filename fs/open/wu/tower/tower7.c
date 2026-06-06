// Room: /u/p/pokai/room/wu/tower7
inherit ROOM;

void create()
{
  set ("short", "武威七殺塔七樓--");
  set ("long", @LONG
這裏是武威七殺塔的最頂層，站在這裡，你有一種說不出的成就感，一旁的小窗
子(window)還不斷吹進微風；你忽然發現牆角陰暗處站著一個身形瘦小的人，你猜想
他大概就是這間房間的主人，或者是這個塔的主人！？
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "window" : "    一個木框小窗，你由窗口往外看去，發現外下頭正對一個水池，你不
禁突發奇想，想由這兒跳下去（jump）是不是比較快下到一樓！？
",
]));
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"tower6",
]));
  setup();
}
