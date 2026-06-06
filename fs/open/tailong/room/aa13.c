inherit ROOM;

void create ()
{
  set ("short", "迴廊");
  set ("long", @LONG
這裡是連接走道和西院走廊的迴廊,從這裡往北走就可以到達西院
中的牟尼堂,牟尼堂內常有著天龍寺的高手在清修, 所以如果自己沒有
幾分斤兩還是不要隻身冒險比較好
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"aa11",
  "north" : __DIR__"aa15",
]));

  setup();
  replace_program(ROOM);
}
