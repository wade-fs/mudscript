// Room: /u/l/leei/blacktest0.c
inherit ROOM;

void create()
{
  set ("short", "殺手練習室一");
  set ("long", @LONG
   這裡是中級殺手的訓練室之一
想要成為好的殺手必須經過不斷的鍛鍊
而這裡便是培育優良殺手的房間之一
想要成為好的殺手來這裡就對了!!

LONG);

  set("light_up", 10000);
  set("no_magic", 10);
  set("exits", ([ /* sizeof() == 1 */
	"west":__DIR__"r5",
]));
  set("objects",([
	"open/killer/npc/trainee2": 4,
    ]));
   setup();
}
