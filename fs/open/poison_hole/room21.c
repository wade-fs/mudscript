// Room: /u/w/whatup/poison_hole/room21
inherit ROOM;

void create ()
{
  set ("short", "涼亭");
  set ("long", @LONG
這裡的一個供人乘涼的涼亭，面對的是一個非常高的懸崖，一眼望
去可以看到整個大陸。陣陣的涼風從西邊吹來，讓人非常的涼爽。在這
你忍不住的想大叫幾聲，讓自已壓抑己久的心情可以舒暢點。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"room20",
]));
  set("outdoors", "/u/w");

  setup();
}
