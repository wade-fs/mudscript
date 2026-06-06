inherit ROOM;

void create ()
{
  set ("short", "迴廊");
  set ("long", @LONG
這裡是連接走道和東院走廊的迴廊,從這裡往北走就可以到達東院中
新建的玄機房,玄機房中好像住著段家的一代高手－段譽,和他的妻子王
語嫣,他們夫婦倆不久前宣布退出江湖,隱居天龍寺,所以還是不要去打擾
他們吧
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"aa21",
  "west" : __DIR__"aa12",
]));

  setup();
  replace_program(ROOM);
}
