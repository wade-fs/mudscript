// Room: /open/main/room/maiu-7
inherit ROOM;

void create()
{
  set ("short", "茅草屋");
	set( "build", 12 );
  set ("long", @LONG
    你走進一間茅草屋,簡陋的擺設,破舊的家具,這就是苗人的
住所,完全無法跟中原民家的富麗相比,與平南連年的征戰帶來了
窮困與疾病,這難道是苗人命運的枷鎖?
LONG);

  set("objects", ([
      "/open/ping/npc/maiu-gen" : 1,
      ]));
  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"maiu-4",
]));
  setup();
}
