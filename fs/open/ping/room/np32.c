inherit ROOM;

void create ()
{
  set ("short", "武器室");
  set ("long", @LONG
這裡是段王府的武器儲藏室 ,左首一排長架擺滿了各式各樣的刺術武
器 ,有竹筆 ,鐵扇 ,打穴撅..等 ,一應俱全 ,右首的長架則擺滿了其它各
樣的武器 ,不論是大刀 ,鐵棍 ,長鞭 ,短匕 ,暗器 ,盡皆齊備。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"np2.c",
]));
  set("light_up", 1);
  set("no_fight", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/ping/obj/fan-2" : 2,
]));

  setup();
}
