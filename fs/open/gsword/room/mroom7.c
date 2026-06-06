// Room: /d/oldpine/epath2.c

inherit ROOM;

void create ()
{
  set ("short", "仙劍派前山");
  set ("long", @LONG
    前進到此,只見巨石聳立,水聲淙淙,陣陣水氣襲來,帶給你滿面清涼,
道路在此轉向北方,你直覺你已經到仙劍派外圍.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road1.c",
  "east" : __DIR__"mroom6.c",
]));

  set("outdoors", "/open/gsword/room");

  setup();
}
