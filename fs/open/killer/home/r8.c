inherit ROOM;
void create()
{
  set ("short", "殺手練習室");
  set ("long", @LONG
這是初級殺手訓練的地方
想要成為好的殺手必須經過不斷的鍛鍊
而這裡便是培育優良殺手的房間之一

LONG);

  set("light_up", 100);
  set("no_magic", 10);
  set("exits", ([ /* sizeof() == 1 */
        "north":__DIR__"r5",
]));
  set("objects",([
	"open/killer/npc/trainee1" :3, ]));
 setup();
}
