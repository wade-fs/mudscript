// Room: /u/d/devils/school3.c

inherit ROOM;

void create ()
{
  set ("short", "練武場");
  set ("long", @LONG
這裡是正晴武館教授棍法之處,一位彪形大漢正揮舞著冰火風雷棍
,其臀力之強,令方圓三丈的人都感覺勁風撲面....地上還躺著三,四個
武館弟子(可能不小心被打到的吧!),你想了想決定還是快離開比較安全
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"school2",
  "east" : __DIR__"school4",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/wu/npc/trainee1" : 1,
]));

  set("outdoors", "/open/wu");
  setup();
}
