// Room: /u/g/guetenr/beggar/room/beg1/room20.c
inherit ROOM;

void create ()
{
  set ("short", "石板小路");
  set ("long", @LONG
石板鋪成的街道向兩邊綿延過去，緩緩飄揚的雨絲日夜瀟瀟，潮潤得路
面泛著淺淺的光輝；南邊清泉東行夾岸楊柳嬌如膩人，岸邊幾叢鈴兒草，串
串弓形斜垂粉紅小花，隨風輕搖似紅袖相招；北邊客棧不時傳來陣陣飲宴笑
語聲花。
LONG);

  set("outdoors", "/open/");
  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"room19.c",
  "north" : __DIR__"room21.c",
  "west" : __DIR__"room24.c",
]));

  setup();
}
