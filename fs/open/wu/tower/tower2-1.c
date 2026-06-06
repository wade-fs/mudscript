// Room: /u/p/pokai/room/wu/tower2-1
inherit ROOM;

void create ()
{
  set ("short", "武威七殺塔二樓--");
  set ("long", @LONG
走到了這兒，發現地上的血漬不像方才那麼多，但四周的殺氣比方才更加的濃
烈，你發現地磚上印有幾個深深的腳印，你可以想見到過這兒的武者個個都是身懷
絕技。牆上貼有一張告示(note)。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"tower2-2",
  "down" : __DIR__"tower1-3",
]));
  set("light_up", 1);

  set("item_desc", ([ /* sizeof() == 1 */
  "note" : @LONG
    血腥的考驗將要展開，你可以考慮在此回頭，或是接受二到五層的考驗。
LONG,
]));

  setup();
}

