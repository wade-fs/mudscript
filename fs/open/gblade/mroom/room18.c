// Room: /u/m/moner/room/room18.c
inherit ROOM;

void create ()
{
  set ("short", "書房");
  set ("long", @LONG

一踏入這, 映目所及都是書, 數不清的刀譜, 詩, 詞、、、等,皆被分
門別列, 井然有序的放置於架上, 幾張傑白的宣紙被鎮在桌上, 一旁懸著
幾隻狼毫筆, 門欄外映著綠竹, 雕窗外傳來薜荔藤蘿的香味, 果然是一個
讀書的好地方。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"room17.c",
]));
  set("light_up", 1);

  setup();
}
