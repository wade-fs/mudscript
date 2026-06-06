// Room: /u/m/moner/water/r7.c
inherit ROOM;

void create ()
{
  set ("short", "廣場");
  set ("long", @LONG

    這裡是魔刀門的廣場，是魔刀門內召集門徒，比試武藝，或其它
非常時刻的重要地方，廣場往南、北方向延伸，看起來可以容納數千
人。

LONG);

  set("light_up", 1);
  set("outdoors", "wind");
  set("exits", ([ /* sizeof() == 1 */
"east":"/open/gblade/mroom/mrm/r7.c",
]));
        set("objects",([
"/open/gblade/npc/man.c":3,
]));
  setup();
}
