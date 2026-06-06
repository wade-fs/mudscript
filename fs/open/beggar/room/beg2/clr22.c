// Room: /u/g/guetenr/beggar/room/beg2/clr22.c
inherit ROOM;

void create ()
{
  set ("short", "雲龍廳");
  set ("long", @LONG
轎廳乃賓客來訪遞名帖候招待之處，一進門來抬頭見一匾額上書『沉霧
降龍』四大字，北側偌大牆垣上有題詩，皆筆帶蒼勁宛如竹劍破空富凌霄之
態；又置桌椅咸鑲石屏圖畫山水白鶴，兩旁一對高几玉瓷上插幾枝桃花擷一
室春意，下首兩行座椅則置椅墊上繡三友四君子；兩側粉牆上數幅筆墨，逞
閒居田野之美。左右迴廊向北連向正廳，南接前院。

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"clr23.c",
  "north" : __DIR__"main.c",
  "south" : __DIR__"clr21.c",
  "east" : __DIR__"clr32.c",
]));

  setup();
}
