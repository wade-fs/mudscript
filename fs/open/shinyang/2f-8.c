// Room: /u/w/whatup/area/shinyang/2f-8.c
inherit ROOM;

void create ()
{
  set ("short", "陽台");
  set ("long", @LONG
一個寬廣的陽台，可以一眼看到南門進出的人們與在中央大道上
奔馳的騎兵們，微風徐徐的吹入，陽台上擺著兩棵鐵樹，跟一把藤椅
一個小圓桌，想必城主在閒暇之餘會來這裡泡壺茶坐在藤椅上乘涼，
一定十分的快活。
LONG);

  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"2f-6.c",
]));
  set("no_auc", 1);
  set("light_up", 1);

  setup();
}
