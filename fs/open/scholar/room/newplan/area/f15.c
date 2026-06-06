// Room: /u/s/sueplan/newplan/area/f15.c
inherit ROOM;

void create ()
{
  set ("short", " 樹道");
  set ("long", @LONG
樹蔭夾道的小徑，兩旁盛開的野玫瑰，如火如荼，花把枝兒都壓彎了，
一路延伸的草徑上，遍佈著小得不能再小的雛菊，好像一片綠黃相間的地毯
，迎接你前來。你哼著不知名的小調，漫步而走，遠方隱約傳來三兩聲響，
似乎是風聲，抑或是音樂聲。
LONG);

  set("outdoors", "/u/s");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"f11",
  "north" : __DIR__"f16.c",
]));

  setup();
}
