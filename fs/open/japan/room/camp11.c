inherit ROOM;

void create()
{
  set ("short", "隊長室");
  set ("long", @LONG
小客廳內一塵不染，牆壁上的字畫(word)大大書寫著「忠義」。
房屋中央的榻榻米上擺著小矮桌跟鋪著坐墊的座椅，座椅旁還擺設著
憑肘。開放性的窗戶可以將外面的風景進收眼底。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 1 */
    "south" : __DIR__"camp10.c",
  ]));
  setup();
}
