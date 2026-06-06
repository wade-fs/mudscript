// Room: /u/p/pokai/room/wu/tower2-3
inherit ROOM;

void create()
{
  set ("short", "武威七殺塔二樓--");
  set ("long", @LONG
來到這兒，由於有小氣窗的關係，你覺得有這間房間給人的感覺和剛剛完全
不同，這使你原本緊繃的心情也為之鬆弛。這裡有個通往七殺塔三樓的的樓梯，
四周的牆壁上刻劃了一些人物形圖像(figure)，你想可能是闖關的武者們研究守
關守衛的一些記錄。
LONG);

  set("light_up", 1);
  set("item_desc", ([ /* sizeof() == 1 */
  "figure" : @LONG

             O/     / /       O  _|         H
          -- |    0 --        l \ __     -- I --
            / \    |  \         I           Q     #@%$@%^$^&#.........

                                你看了看，笑了一下，覺得有些不以為然的感覺。                 
LONG,
]) );
  set("exits", ([ /* sizeof() == 2 */
  "climb" : __DIR__"tower3-1",
  "east" : __DIR__"tower2-2",
]));
  setup();
}
