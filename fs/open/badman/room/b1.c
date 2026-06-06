// Room: /open/badman/room/b1.c

inherit ROOM;

void create ()
{
  set ("short", "惡人谷");
  set ("long", @LONG
突然間，你的眼前豁然開朗，四面窮山中，奇蹟般的出現了一
片燈火，有如萬點明星，眩人奪目。江湖中人心目中所想像的惡人
谷，自然是說不出的陰森、黑暗，但此刻惡人谷中竟是一片輝煌的
燈火。但這燈火非但未使惡人谷的神秘減少，反而使惡人谷更增加
了說不出的詭異。
    燈光下，只見一個石碑(stele)立在道旁。

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "stele" : "
	入谷入谷，
	永不為奴。
",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/main/obj/torch" : 1,
]));
  set("outdoors", "/open/badman");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"b2",
  "east" : __DIR__"b0",
]));

  setup();
}
