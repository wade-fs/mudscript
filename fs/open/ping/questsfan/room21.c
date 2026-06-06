// Room: /u/d/dhk/questsfan/room21
inherit ROOM;

void create ()
{
  set ("short", "白晶層");
  set ("long", @LONG
這一層位於谷緣的結晶都呈現乳白色的光芒，所以顧
名思義這一層的結晶叫〝白晶石 〞，因其顏色是乳白色的
不時還會冒出乳白色的液體，傳聞若喝下這些液體一口就
會使你皮膚雪白、還老還童。你一路觀看過延途一層層各
式各色的晶石，另你感到致身於仙境中的感覺、眼花撩亂
，忽而好極忽而鬱悶…變的多愁善感。

LONG);

  set("outdoors", "/u/d");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"room22",
  "northup" : __DIR__"room20",
]));

  setup();
}
