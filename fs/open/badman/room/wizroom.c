// Room: /open/badman/room/wizroom
inherit ROOM;

void create ()
{
  set ("short", "惡人谷幕後黑手專用刑求室");
  set ("long", @LONG
你一進門就看到牆上掛著一幅巨大的對聯，上聯寫著『有話快
說』，下聯則是『有屁快放』，上頭還有一個大大的橫批『無事退
朝』。看著看著你忽然發現牆角邊有一行小字(word)....

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "word" : "無聊透頂....oda 到此一游x...遊 :b
世事無常... powell :P
我也要來留個言... Sincerely yous, Caesar ... :P
",
]));
  set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"g1",
]));
  set("light_up", 1);
  set("no_fight", 1);
  set("no_magic", 1);

  setup();
  call_other("/obj/board/badwiz_b", "???");
}
