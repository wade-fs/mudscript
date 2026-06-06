// Room: /u/r/ranko/garden1.c
inherit ROOM;

void create ()
{
  set ("short", "毒園入口");
  set ("long", @LONG
這裡是冥蠱教用來種毒花毒草的地方,以供給教中煉製毒藥所用
園子裡五顏六色的種滿各式各樣的花草,看的你眼花撩亂,目不暇己.
空氣中更不時飄來陣陣濃鬱的香氣,令人感到渾身鬆軟,飄飄欲仙.但
過不久,你就發現這股香氣有點軌異,你心想在不離開的話也許會中毒
也說不定。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road18",
  "south" : __DIR__"garden2.c",
]));

  setup();
}
