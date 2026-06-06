// Room: /u/w/whatup/peach/peach11
inherit ROOM;

void create ()
{
  set ("short", "桃木林");
  set ("long", @LONG
一走進桃木林裡，映入眼簾的是一大片桃木，並且一直延伸下去
，也沒有明顯的道路痕跡，只能四處走走，期盼能快點找到出口，早
點離開這裡。，路旁有顆大石頭(stone)。
LONG);


  set("item_desc", ([ /* sizeof() == 1 */
  "stone" : "
人生短短幾十年，不要給自己留下了什麼遺憾，想笑就笑，想哭就哭，該愛的時
候就去愛，無謂壓抑自己。~~玲

....這似乎是記錄著一位女子率性的戀慕之心. \n
",
]));

  set("outdoors", "/u/b/blazakira");
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"peach6",
]));

  setup();
}
