inherit ROOM;

void create ()
{
  set ("short", "長廊");
  set ("long", @LONG

角落掛著水晶玻璃各色風燈，一邊還掛著五美圖，五美分別是中國五個才
色俱佳的女子--西施、虞姬、明妃、綠珠、紅拂，你走近過去一看，每一
幅畫都題有詩句在旁。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"g2-1.c",
  "west" : __DIR__"gblade",
  "east" : __DIR__"g1-7.c",
]));

  set("light_up", 1);

  setup();
}
